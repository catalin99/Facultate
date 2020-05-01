#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <nlohmann/json.hpp>
#include "serverProfil.h"
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>

using namespace std;
using json = nlohmann::json;
#define PORT 4999
#define MaxClients 1000
extern int errno; //cod de eroare
serverProfil TemporaryObject;
serverProfil objProfil;
fd_set actfds;

char * conv_addr (struct sockaddr_in address) //converteste ip-ul clientului in char[]
{
    static char ipport[25];
    char port[7];

    strcpy (ipport, inet_ntoa (address.sin_addr));  //se adauga adresa ip
    bzero (port, 7);
    sprintf (port, ":%d", ntohs (address.sin_port));
    strcat (ipport, port); //se adauga portul
    return (ipport);
}

bool Write_String_S(const string& input, int fd)
{
    unsigned long size=input.size();
    char sizeChar[11];
    sprintf(sizeChar,"%lu",size);
    int kk=strlen(sizeChar);
    while(kk<10)
    {
        sizeChar[kk++]='-';
        sizeChar[kk]='\0';
    }
    if(write(fd,sizeChar, 10)<=0)
    {
        cout<<"Eroare la write (SIZE)\n";
        return false;
    }
    if(input!="EXIT")
    {
        if(write(fd, input.data(), size)<=0)
        {
            cout<<"Eroare la write (Mesaj)\n";
            return false;
        }
    }
    return true;
}

bool Read_String_S(string &output, int fd)
{
    char sizeInput[11];
    if(read(fd, sizeInput, 10)<=0)
    {
        cout<<"Eroare la read (SIZE)\n";
        return false;
    }
    char fin[11];
    for(int i=0; i<strlen(sizeInput); i++)
    {
        if (isdigit(sizeInput[i]))
        {
            fin[i]=sizeInput[i];
            int p=i;
            p++;
            fin[p]='\0';
        }
        else
            break;
    }
    int size=atoi(fin);
    char out[10000];
    if(read(fd, out, (size_t)size)<0)
    {
        cout<<"Eroare la read (Mesaj)\n";
        return false;
    }
    output.assign(out, 0, (unsigned long)size);
    //cout<<"Output*"<<output<<"*\n";
    return true;
}

bool CheckRobotSrv(const string Answer)
{
    vector <string> AnswerList={
            "300",
            "Sunt Robot",
            "SUNT ROBOT",
            "sunt robot",
            "Sunt robot",
            "4",
            "belu",
            "BELU",
            "Belu",
            "alba",
            "alb",
            "ALBA",
            "alb",
            "x",
            "X"
    };
    for (auto &check:AnswerList)
    {
        if (check==Answer)
            return true;
    }
    return false;
}

string CheckData(string input)
{
    size_t found=input.find("\n");
    string username, password;
    username.assign(input,0,found);
    password.assign(input,found+1,input.size()-(found+1));
    string Check=TemporaryObject.checkUser(username);
    if (Check=="fail#")
        return "Username Gresit\n";
    if (Check!=password)
        return "Parola Gresita\n";
    return "Autentificare reusita\n";
}

string ForgotPassword(const int& fdlocal)
{
    //char UserN[50];
    string StringReturn;
    /*if(read(fdlocal, UserN, sizeof(UserN))<0)
    {
        perror("Eroare la read de la client in functia ForgotPassword\n");
        return "Error";
    }*/
    string UserNAME;
    Read_String_S(UserNAME,fdlocal);
    string CheckFP=TemporaryObject.checkFP(UserNAME);
    if (CheckFP=="fail#")
        StringReturn="Wrong Username";
    else
        StringReturn=CheckFP;
    /*if(write(fdlocal,StringReturn.data(),StringReturn.size())<0)
    {
        perror("Eroare la write catre client in functia ForgotPassword\n");
        return "Error";
    }*/
    Write_String_S(StringReturn,fdlocal);
    return StringReturn;
}

bool Register(const int& fdlocal)
{
    char RecvRegister[300];
    /*if (read(fdlocal, RecvRegister, sizeof(RecvRegister)) < 0)
    {
        perror("Eroare la read de la client in functia Register\n");
        return false;
    }*/
    string RecvRegStr;
    Read_String_S(RecvRegStr,fdlocal);
    for(int i=0; i<RecvRegStr.size();i++)
    {
        RecvRegister[i]=RecvRegStr[i];
        int b=i;
        b++;
        RecvRegister[b]='\0';
    }
    string USERNAME, PASSWORD, SECRETQUESTION, SECRETANSWER;
    short InputNo=1;
    char *p=strtok(RecvRegister,"\n");
    USERNAME.assign(p,strlen(p));
    while(p)
    {
        p++;
        p=strtok(nullptr, "\n");
        switch (InputNo)
        {
            case 1:
                PASSWORD.assign(p,strlen(p)); break;
            case 2:
                SECRETQUESTION.assign(p,strlen(p)); break;
            case 3:
                SECRETANSWER.assign(p,strlen(p)); break;
            default:
                break;
        }
        InputNo++;
    }
    short check=TemporaryObject.Register(USERNAME,PASSWORD,SECRETQUESTION,SECRETANSWER);
    string RETstr;
    switch(check)
    {
        case 0:
            RETstr="ERROR"; break;
        case 1:
            RETstr="Success"; break;
        case 2:
            RETstr="Username ERROR"; break;
        default:
            break;
    }
    /*if(write(fdlocal,RETstr.data(),RETstr.size())<0)
    {
        perror("Eroare la write catre client in functia Register\n");
        return false;
    }*/
    Write_String_S(RETstr,fdlocal);
    return true;
}

bool Edit_Profil_Srv(const int& fdlocal)
{
    cout << "*Edit profil start*\n";
    string Infos;
    Infos = objProfil.MyProfilInfo(fdlocal);
    Write_String_S(Infos, fdlocal);
    string msg;
    Read_String_S(msg, fdlocal);
    string Returnmsj;
    if(msg=="51")
    {
        string lastname;
        Read_String_S(lastname, fdlocal);
        objProfil.UpdateLastName(lastname,fdlocal);
        Returnmsj="Complete";
    }
    else if(msg=="52")
    {
        string firstname;
        Read_String_S(firstname, fdlocal);
        objProfil.UpdateFirstName(firstname,fdlocal);
        Returnmsj="Complete";
    }
    else if(msg=="53")
    {
        string visibil;
        Read_String_S(visibil, fdlocal);
        if(visibil=="1")
        {
            objProfil.UpdateVisibility("Public", fdlocal);
            Returnmsj="Complete";
        }
        else if(visibil=="2")
        {
            objProfil.UpdateVisibility("Private", fdlocal);
            Returnmsj="Complete";
        }
        else if(visibil=="3")
        {
            objProfil.UpdateVisibility("Friends", fdlocal);
            Returnmsj="Complete";
        }
        else if(visibil=="4")
        {
            objProfil.UpdateVisibility("Friends of Friends", fdlocal);
            Returnmsj="Complete";
        }
        else
        {
            return true;
        }
    }
    else
    {
        Write_String_S("Back", fdlocal);
        cout<<"Stop server";
        return false;
    }
    Write_String_S(Returnmsj,fdlocal);
    return true;
}

bool Profil_Views(const int& fdlocal,serverProfil& objProfil)
{
    string CARE;
    Write_String_S("Vizualizare Profiluri: \n",fdlocal);
    while(Read_String_S(CARE,fdlocal))
    {
        if(CARE=="#toate#")
        {
            string Profiluri = objProfil.VeziProfile(fdlocal);
            Write_String_S(Profiluri, fdlocal);
        }
        else if(CARE=="#BACK#")
        {
            Write_String_S("Mergem inapoi\n", fdlocal);
            return true;
        }
        else if(CARE=="#EXIT#")
        {
            Write_String_S("Iesire\n",fdlocal);
            return false;
        }
        else
        {
            string Profil=objProfil.VeziUnProfil(fdlocal, CARE);
            Write_String_S(Profil, fdlocal);
        }
    }
    return true;
}

bool Requests_Manager_S(const int& fdlocal)
{
    string What;
    string SendBack;
    Read_String_S(What,fdlocal);
    if(What=="FriendRequests")
    {
        string Back;
        if (objProfil.CereriPrimite(fdlocal, Back))
        {
            SendBack="Cereri primite:\n";
            SendBack+=Back;
        }
        else
            SendBack="Nu exista cereri de prietenie primite\n";
    }
    else if(What=="RequestsSent")
    {
        string Back;
        if (objProfil.CereriTrimise(fdlocal, Back))
        {
            SendBack="Cereri Trimise:\n";
            SendBack+=Back;
        }
        else
            SendBack="Nu exista cereri de prietenie trimise care nu au fost inca acceptate!\n";
    }
    else if(What[0]=='S' && What[1]=='a')
    {
        if(What[5]=='U' && What[8]=='r')
        {
            string GOstr=&What[10];
            SendBack=objProfil.SendReqbyUsername(fdlocal,GOstr);
        }
        else if(What[5]=='N' && What[8]=='P')
        {
            string GOstr=&What[10];
            size_t found = GOstr.find('\n');
            string GOstrN;
            string GOstrP;
            GOstrN.assign(GOstr, 0, found);
            GOstrP.assign(GOstr, found+1, GOstr.size()-(found+1));
            SendBack=objProfil.SendReqbyNP(fdlocal,GOstrN,GOstrP);
        }
    }
    else if(What[0]=='A' && What[1]=='a')
    {
        if(What[5]=='U' && What[8]=='r')
        {
            string GOstr=&What[10];
            SendBack=objProfil.AccReqbyUsername(fdlocal,GOstr);
        }
        else if(What[5]=='N' && What[8]=='P')
        {
            string GOstr=&What[10];
            size_t found = GOstr.find('\n');
            string GOstrN;
            string GOstrP;
            GOstrN.assign(GOstr, 0, found);
            GOstrP.assign(GOstr, found+1, GOstr.size()-(found+1));
            SendBack=objProfil.AccReqbyNP(fdlocal,GOstrN,GOstrP);
        }
    }
    else
    {
        cout<<"Test: "<<What<<"*end";
        Write_String_S("BackFR\n",fdlocal);
        return false;
    }
    Write_String_S(SendBack,fdlocal);
    return true;
}

bool Create_Post_Srv(const int& fdlocal)
{
    string inputmsj;
    Read_String_S(inputmsj, fdlocal);
    if(inputmsj[0]=='0' || inputmsj[inputmsj.size()-1]=='#')
    {
        Write_String_S("Nu a fost publicata postarea\n",fdlocal);
        return false;
    }
    string VIS, POST;
    switch(inputmsj[0])
    {
        case '1':
            VIS="Public";
            break;
        case '2':
            VIS="Private";
            break;
        case '3':
            VIS="Friends";
            break;
        case '4':
            VIS="Friends of Friends";
            break;
        default:
            VIS="Public";
            break;
    }
    POST=&inputmsj[2];
    if(objProfil.Make_Post(fdlocal, VIS, POST))
    {
        Write_String_S("Postarea a fost publicata cu succes\n",fdlocal);
        return true;
    }
    else
    {
        Write_String_S("Au aparut erori la crearea acestei postari\n",fdlocal);
        return false;
    }
}

bool See_Posts(const int& fdlocal)
{
    string input;
    Read_String_S(input, fdlocal);
    if(input=="Back_to_meniu_principal\n")
    {
        cout<<"[LOG]Back\n";
        return false;
    }
    else if(input=="All posts\n")
    {
        cout<<"[LOG]Toate postarile\n";
        string output;
        output=objProfil.VeziToatePostarile(fdlocal);
        Write_String_S(output,fdlocal);
        return true;
    }
    else if(input=="My Posts\n")
    {
        cout<<"[LOG]Postarile utilizitorului cu descriptorul "<<fdlocal<<endl;
        string outputmyposts;
        outputmyposts=objProfil.VeziPostarileMele(fdlocal);
        Write_String_S(outputmyposts,fdlocal);
        return true;
    }
    else
    {
        cout<<"[LOG]Postarile utilizatorului "<<input<<'\n';
        string outputuser;
        outputuser=objProfil.VeziPostariUser(fdlocal, input);
        Write_String_S(outputuser,fdlocal);
        return true;
    }
}

string ShowInfos()
{
    string RETPRIV;
    RETPRIV="Lista cu privilegii in functie de gradul utilizatrilor:\n";
    RETPRIV+="Normal User:\n";
    RETPRIV+="Editare profil propriu\nVizualizare alte profiluri(in functie de vizibilitatea acestora)\nCreare postare\nVizualizare alte postari(in functie de vizibilitatea acestora)\n";
    RETPRIV+="Lista de prieteni: Trimite cereri, accepta cereri, vizualizare cereri trimise si neacceptate inca, vizualizare cereri primite\n *Daca esti prieten cu o persoana ii poti vedea postarile(sau profilul) daca acesta are setat vizibilitatea doar pentru prieteni\n";
    RETPRIV+="Deschidere conversatie cu un utilizator sau cu un grup de utilizatori\n";
    RETPRIV+="VIP:\n";
    RETPRIV+="Vizualizare profiluri sau postari indiferent de vizibilitatea setata a acestora\n";
    RETPRIV+="Admin:\n";
    RETPRIV+="Panou admininistrare:\n\tStergere postari\n\tEditare vizibilitate postari sau profiluri\n\tVizualizare lista privilegii utilizatori\n";
    RETPRIV+="Owner:\n";
    RETPRIV+="Panou administrare:\n\tModificare grad utilizatori (Admin, Owner, VIP, normal user)\n";
    RETPRIV+="Nota: Utilizatorii cu grad mai mare au toate facilitatile celor cu grad inferior lor\nIerarhie: Normal User < VIP < Admin < Owner\n";
    return RETPRIV;
}

bool AdministreazaSrv(const int& fdlocal)
{
    string Grad=objProfil.checkGrad(fdlocal);
    if(Grad!="Owner" && Grad!="Admin")
    {
        Write_String_S(Grad,fdlocal);
        return false;
    }
    Write_String_S(Grad,fdlocal);
    if(Grad=="Admin") //case admin
    {
        string in;
        Read_String_S(in, fdlocal);
        if(in=="1")  //privilegii
        {
            string Priv=ShowInfos();
            Write_String_S(Priv,fdlocal);
            return true;
        }
        else if(in=="2") //sterge postare
        {
            string IdPost;
            IdPost=objProfil.GetFullInfosAboutPosts();
            Write_String_S(IdPost, fdlocal);
            string IdForDelete;
            Read_String_S(IdForDelete,fdlocal);
            objProfil.DeletePost(IdForDelete);
            return true;
        }
        else if(in=="3") //vizibilitate postare
        {
            string IdPost;
            IdPost=objProfil.GetFullInfosAboutPosts();
            Write_String_S(IdPost, fdlocal);
            string Modify;
            Read_String_S(Modify,fdlocal);
            objProfil.ModificaVizibilitate(Modify);
            return true;
        }
        else //back
        {
            Write_String_S("BACK",fdlocal);
            return false;
        }
    }
    else //case owner
    {
        string in;
        Read_String_S(in, fdlocal);
        if(in=="1")
        {
            string Priv=ShowInfos();
            Write_String_S(Priv,fdlocal);
            return true;
        }
        else if(in=="2")
        {
            string IdPost;
            IdPost=objProfil.GetFullInfosAboutPosts();
            Write_String_S(IdPost, fdlocal);
            string IdForDelete;
            Read_String_S(IdForDelete,fdlocal);
            objProfil.DeletePost(IdForDelete);
            return true;
        }
        else if(in=="3")
        {
            string IdPost;
            IdPost=objProfil.GetFullInfosAboutPosts();
            Write_String_S(IdPost, fdlocal);
            string Modify;
            Read_String_S(Modify,fdlocal);
            objProfil.ModificaVizibilitate(Modify);
            return true;
        }
        else if(in=="4") //acorda/modifica grad
        {
            string MdfGrade;
            Read_String_S(MdfGrade,fdlocal);
            objProfil.ModificaGrad(MdfGrade);
            return true;
        }
        else
        {
            Write_String_S("BACK",fdlocal);
            return false;
        }
    }
}

bool Keep_Talking_S(const int& fdlocal, const string& myusername, const string& msgoutusername, size_t& counter)
{
    string mesajprimit;
    Read_String_S(mesajprimit, fdlocal);
    while(mesajprimit!="STOP" && mesajprimit!="stop")
    {
        if(mesajprimit=="refresh" || mesajprimit=="REFRESH" || mesajprimit=="Refresh")
        {
            string refresh=objProfil.GetActualConv(fdlocal,msgoutusername, counter);
            Write_String_S(refresh,fdlocal);
        }
        else
            objProfil.UpdateConversation(fdlocal, mesajprimit, msgoutusername);
        Read_String_S(mesajprimit,fdlocal);

    }
    return true;
}

bool Keep_Talking_Group_S(const int& fdlocal, const string& myusername, const vector<string>& ids, size_t& counter)
{
    string mesajprimit;
    Read_String_S(mesajprimit, fdlocal);
    while(mesajprimit!="STOP" && mesajprimit!="stop")
    {
        if(mesajprimit=="refresh" || mesajprimit=="REFRESH" || mesajprimit=="Refresh")
        {
            string refresh=objProfil.GetActualConvGroup(fdlocal,ids, counter);
            Write_String_S(refresh,fdlocal);
        }
        else
            objProfil.UpdateConversationGroup(fdlocal, mesajprimit, ids);
        Read_String_S(mesajprimit,fdlocal);

    }
    return true;
}

bool History_S(const int& fdlocal,const string& username)
{
    size_t counter=1;
    string actual_chat=objProfil.GetActualConv(fdlocal,username,counter);
    Write_String_S(actual_chat,fdlocal);
    if(actual_chat=="Nu esti prieten cu acest utilizator\n")
        return false;
    string myUsername;
    myUsername=objProfil.GetUsername(fdlocal);
    Write_String_S(myUsername,fdlocal);
    Keep_Talking_S(fdlocal, myUsername, username,counter);
    return true;
}

bool History_Group_S(const int& fdlocal, const vector<string>& ids)
{
    size_t counter=1;
    string actual_chat=objProfil.GetActualConvGroup(fdlocal,ids,counter);
    Write_String_S(actual_chat,fdlocal);
    if(actual_chat=="Nu esti prieten cu acest utilizator\n")
        return false;
    string myUsername;
    myUsername=objProfil.GetUsername(fdlocal);
    Write_String_S(myUsername,fdlocal);
    Keep_Talking_Group_S(fdlocal, myUsername, ids ,counter);
    return true;
}

bool Start_a_New_Conversation_S(const int& fdlocal)
{
    string username;
    Read_String_S(username,fdlocal);
    if(username=="Back#new_conv")
    {
        return false;
    }
    else
    {
        string ID=objProfil.GetIDFromUsername(username);
        Write_String_S(ID,fdlocal);
        if(ID=="fail")
            return false;
        History_S(fdlocal,username);
        return true;
    }
}

bool Start_a_New_Conversation_Group_S(const int& fdlocal)
{
    string username;
    username.clear();
    bool one=false;
    vector <string> ids;
    while(username!="Back#new_conv")
    {
        Read_String_S(username, fdlocal);
        if (username == "Back#new_conv")
        {
            if(one)
            {
                History_Group_S(fdlocal, ids);
                return true;
            }
        }
        else
        {
            one=true;
            string ID = objProfil.GetIDFromUsername(username);
            Write_String_S(ID, fdlocal);
            if (ID != "fail")
            {
                ids.emplace_back(ID);
            }
        }
    }
    return false;
}

bool Actual_Conv(const int& fdlocal)
{
    string lista;
    lista=objProfil.GetConvList(fdlocal);
    Write_String_S(lista,fdlocal);
    Start_a_New_Conversation_S(fdlocal);
    return true;
}

bool Actual_Conv_Group_S(const int& fdlocal)
{
    string lista;
    lista=objProfil.GetConvListGroup(fdlocal);
    Write_String_S(lista,fdlocal);
    Start_a_New_Conversation_Group_S(fdlocal);
    return true;
}

bool Conversatie_S(const int& fdlocal)
{
    string Input;
    Read_String_S(Input,fdlocal);
    if(Input=="conversatii_actuale")
    {
        Actual_Conv(fdlocal);
        return true;
    }
    else if(Input=="new_conversation")
    {
        Start_a_New_Conversation_S(fdlocal);
        return true;
    }
    else
    {
        cout<<"[LOG]"<<Input;
        return false;
    }
}

bool Conversatie_Group_S(const int& fdlocal)
{
    string Input;
    Read_String_S(Input,fdlocal);
    if(Input=="conversatii_group_actuale")
    {
        Actual_Conv_Group_S(fdlocal);
        return true;
    }
    else if(Input=="new_group_conversation")
    {
        Start_a_New_Conversation_Group_S(fdlocal);
        return true;
    }
    else
    {
        cout<<"[LOG]"<<Input;
        return false;
    }
}

bool After_Login(const int& fdlocal, bool& CHECK)
{
    string msg;
    Read_String_S(msg, fdlocal);
    if (msg=="11")
    {
        Write_String_S("Editare Profil\n",fdlocal);
        while(Edit_Profil_Srv(fdlocal));
        return true;
    }
    else if (msg=="12")
    {
        cout << "*Vizualizare profiluri*\n";
        if(Profil_Views(fdlocal, objProfil))
            return true;
        return false;
    }
    else if(msg=="13")
    {
        cout<<"[LOG]Creare postare[LOG]\n";
        Write_String_S("Create Post\n",fdlocal);
        Create_Post_Srv(fdlocal);
        return true;
    }
    else if(msg=="14")
    {
        cout<<"[Log]Vizualizare postari\n";
        Write_String_S("Vezi postari\n",fdlocal);
        while(See_Posts(fdlocal));
        return true;
    }
    else if(msg=="15")
    {
        cout<<"[LOG]Panou administrare accesat\n";
        Write_String_S("Administrare server\n", fdlocal);
        while(AdministreazaSrv(fdlocal));
        return true;
    }
    else if(msg=="16")
    {
        cout<<"[LOG]Conversatii\n";
        Write_String_S("Conversatie\n",fdlocal);
        while(Conversatie_S(fdlocal));
        return true;
    }
    else if(msg=="17")
    {
        cout<<"[LOG]Grup\n";
        Write_String_S("Grup_Conv\n",fdlocal);
        while(Conversatie_Group_S(fdlocal));
        return true;
    }
    else if(msg=="18")
    {
        string cereri="Cereri\n";
        Write_String_S(cereri,fdlocal);
        while(Requests_Manager_S(fdlocal))
        {}
        return true;
    }
    else if(msg=="19")
    {
        //cout<<"HERE\n";
        //objProfil.DelogheazaUser(fdlocal);
        Write_String_S("EXIT00",fdlocal);
        CHECK=false;
        return false;
    }
    else
    {
        cout<<"case else\n";
        Write_String_S("EXIT00",fdlocal);
        CHECK=false;
        return false;
    }
}

bool No_Login_S(const int& fdlocal)
{
    string input;
    Read_String_S(input, fdlocal);
    if(input=="1")
    {
        Write_String_S("posts",fdlocal);
        string output=objProfil.GetNoLoginPosts();
        Write_String_S(output, fdlocal);
        return true;
    }
    else if(input=="2")
    {
        Write_String_S("profiles", fdlocal);
        string output=objProfil.GetNoLoginProfiles();
        Write_String_S(output,fdlocal);
        return true;
    }
    else
    {
        Write_String_S("BACKK", fdlocal);
        return false;
    }
}

bool MainProgram(const int& fdlocal)
{
    char buffer[1000];
    char msg[1000];
    bool bytes=true;
    strcpy(msg,"\0"); //initializam mesajul cu 0
    //bytes = read (fdlocal, msg, sizeof (buffer));
    string STRING_READ;
    while(bytes)
    {
        bytes = Read_String_S(STRING_READ, fdlocal);
        //cout<<"AM citit\n";
        for (int i = 0; i < STRING_READ.size(); i++) {
            msg[i] = STRING_READ[i];
            int b = i;
            b++;
            msg[b] = '\0';
        }
        //cout<<"[LOG]Utilizatori logati: \n";
        //objProfil.PrintMap();
        if (!bytes) //eroare la read/clientul s-a deconectat
        {
            perror("Eroare la read() de la client.\n");
            printf("[S] S-a deconectat clientul cu descriptorul %d.\n", fdlocal);
            fflush(stdout);
            objProfil.DelogheazaUser(fdlocal);
            //objProfil.PrintMap();
            /*if(write(fdlocal,"EXIT",4)<0)
            {
                perror ("[S]Eroare la write() spre client.\n"); //tratam eroarea
                return false;// errno;
            }*/
            close(fdlocal);   // inchidem conexiunea cu acest client
            FD_CLR (fdlocal, &actfds);// scoatem socketul clientului din multimea descriptorilor activi
            return false;
        } else if (!strcmp(msg, "5")) //clientul s-a deconectat
        {
            cout << "Clientul cu descriptorul " << fdlocal << " a fost deconectat de actiune\n";
            objProfil.DelogheazaUser(fdlocal);
            //objProfil.PrintMap();
            /*if(write(fdlocal,"EXIT",4)<0)
            {
                perror ("[S]Eroare la write() spre client.\n"); //tratam eroarea
                return false;// errno;
            }*/
            Write_String_S("EXIT", fdlocal);
            fflush(stdout);
            close(fdlocal);   // inchidem conexiunea cu acest client
            FD_CLR (fdlocal, &actfds);// scoatem socketul clientului din multimea descriptorilor activi
            bytes=false;
            return false;
        }
        else if (msg[0] == '1' && !isdigit(msg[1])) {
            cout << "Login accesat de clientul cu descriptorul " << fdlocal << '\n';
            /*if(write(fdlocal,"Login: ",7)<0)
            {
                perror ("[S]Eroare la write() spre client. - Login\n"); //tratam eroarea
                return false;// errno;
            }*/
            Write_String_S("Login", fdlocal);
            string ClientDataStr;
            //bzero(ClientData, 100);
            /*if (read(fdlocal, ClientData, sizeof(ClientData)) < 0)
            {
                perror("[S]Eroare la read() de la client - Login\n");
                return false;// errno;
            }*/
            Read_String_S(ClientDataStr, fdlocal);
            //string ClientDataStr(ClientData);
            string RetCheck = CheckData(ClientDataStr);
            if (RetCheck == "Autentificare reusita\n") {
                size_t found3 = ClientDataStr.find("\n");
                string USERNAME;
                USERNAME.assign(ClientDataStr, 0, found3);
                objProfil.FillMap(fdlocal, USERNAME);
                cout << "[LOG]Utilizatori logati: \n";
                objProfil.PrintMap();
            }
            /*if (write(fdlocal, RetCheck.data(), RetCheck.size()) < 0)
            {
                perror("[S]Eroare la wrote() catre client - Mesaj Return Login\n");
                return false;// errno;
            }*/
            Write_String_S(RetCheck, fdlocal);
            if (RetCheck == "Autentificare reusita\n")
            {
                bool CHECK=true;
                while(After_Login(fdlocal, CHECK))
                    cout<<"[LOG]After_Login\n";
                if(!CHECK)
                {
                    //cout << "Clientul cu descriptorul " << fdlocal << " a fost deconectat de actiune\n";
                    objProfil.DelogheazaUser(fdlocal);
                }
            }
        } else if (!strcmp(msg, "2"))
        {
            //objProfil.NoLogConfirm();
            Write_String_S("NoLog", fdlocal);
            while(No_Login_S(fdlocal));
        }
        else if (!strcmp(msg, "3")) {
            cout << "Clientul cu descriptorul " << fdlocal << " a solicitat sa se inregistreze\n";
            /*if(write(fdlocal,"REGISTER",8)<0)
            {
                perror ("[S]Eroare la write() spre client.\n"); //tratam eroarea
                return false;// errno;
            }*/
            Write_String_S("REGISTER", fdlocal);
            if (Register(fdlocal))
                cout << "Inregistrearea clientului " << fdlocal << " este completa\n";
            else
                cout << "Register error [server]";
        }
        else if (!strcmp(msg, "4")) {
            //char az[30];
            //strcpy(az, "Forgot Password: ");
            //cout<<az<<endl;
            string az = "Forgot";
            /*if(write(fdlocal,az,strlen(az))<0)
            {
                perror ("[S]Eroare la write() spre client.\n"); //tratam eroarea
                return false;// errno;
            }*/
            Write_String_S(az, fdlocal);
            string xz = ForgotPassword(fdlocal);
            cout << xz << endl;
        } else {
            cout << "Clientul cu descriptorul " << fdlocal << " a fost deconectat fortat\n";
            objProfil.DelogheazaUser(fdlocal);
            //objProfil.PrintMap();
            /*if(write(fdlocal,"EXIT",4)<0)
            {
                perror ("[S]Eroare la write() spre client.\n"); //tratam eroarea
                return false;// errno;
            }*/
            Write_String_S("EXIT", fdlocal);
            fflush(stdout);
            close(fdlocal);   // inchidem conexiunea cu acest client
            FD_CLR (fdlocal, &actfds);// scoatem socketul clientului din multimea descriptorilor activi
            return false;
        }
    }
    //return true;
}

void* RobotBoy(const int& fdlocal)
{
    string Robo;
    //strcpy(Robo, "ENTER");
    //read(fdlocal, Robo, 6);
    Read_String_S(Robo,fdlocal);
    bool stat=true;
    if(Robo=="ENTER")
    {
        while (stat) {
            stat = MainProgram(fdlocal);
        }
    }
    else
    {
        cout<<"Robot\n";
        close(fdlocal);
        FD_CLR (fdlocal, &actfds);\
    }
    return nullptr;
}

int main ()
{
    struct sockaddr_in server;//structura server
    struct sockaddr_in from;//structura client
    fd_set readfds;   //multime descriptori read
    //fd_set actfds;    // multime descriptori activi (copie)
    struct timeval tv;  //structura timp (pt select)
    int sd, client; //initializare desc pt socket
    int optval=1;   // optiune folosita pentru setsockopt()
    int fd;  //desc pt parcurgerea listei de desc.
    int nfds;  //nr maxim de descriptori
    socklen_t len;   //lungimea structurii sockaddr_in

    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1) //se creeaza socketul
    {
        perror ("[S] Eroare la socket().\n");
        return errno;
    }

    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR,&optval,sizeof(optval)); //setam socketul sa putem refolosi adresa ip

    bzero (&server, sizeof (server)); //initializarea structurii de date

    server.sin_family = AF_INET; //setam familia de de socket
    server.sin_addr.s_addr = htonl (INADDR_ANY); //setam adresa
    server.sin_port = htons (PORT); //setam port-ul

    if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1) //atasarea socketului
    {
        perror ("[S] Eroare la bind().\n");
        return errno;
    }

    if (listen (sd, 5) == -1) //serverul va asculta pentru conectarea clientilor
    {
        perror ("[S] Eroare la listen().\n");
        return errno;
    }

    // initializam multimea descriptorilor de citire
    FD_ZERO (&actfds);    // initializarea se face initial cu 0
    FD_SET (sd, &actfds);   // se include in multime socketul creat

    tv.tv_sec = 1;    //timp de asteptare 1 secunda
    tv.tv_usec = 0;

    nfds = sd; //valoarea maxima pt descriptorii folositi

    printf ("[S] Asteptam la portul %d...\n", PORT);
    fflush (stdout);

//    char buffer[1000];
//    char msg[1000];
//    int bytes=0;
//    serverProfil objProfil;
    vector<thread> threads;
    while (true) //servirea clientilor
    {
        bcopy ((char *) &actfds, (char *) &readfds, sizeof (readfds)); //facem o copie pentru multimea descriptorilor activi
        //START_SELECT
        if (select (nfds+1, &readfds, nullptr, nullptr, &tv) < 0) //servim clientii in mod concurent pentru read
        {
            perror ("[S] Eroare la select().\n");
            return errno;
        }

        if (FD_ISSET (sd, &readfds)) // verificam daca socketul nostru poate accepta clienti
        {
            //initializam structura pentru client
            len = sizeof (from);
            bzero (&from, sizeof (from));

            client = accept (sd, (struct sockaddr *) &from, &len); //acceptam conexiunea de la un client
            if (client < 0) //tratam eroarea pentru acceptarea clientului
            {
                perror ("[S] Eroare la accept().\n");
                continue;
            }

            thread t(RobotBoy, client);
            threads.push_back(move(t));
            cout<<"Sunt conectati la server: "<<threads.size()<<" clienti\n";

            printf("[S] S-a conectat clientul cu numarul %lu si descriptorul %d, de la adresa %s.\n",threads.size(), client, conv_addr (from));
        }
        if(threads.size()>MaxClients)
            break;
    }
    for (thread& thread : threads)
    {
        thread.join();
    }
}
