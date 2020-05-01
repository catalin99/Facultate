#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <random>
#include <pthread.h>
#include <thread>
#include <atomic>

using namespace std;
extern int errno; //cod de eroare
int port; //port de conectare
std::atomic<bool> exit_thread_flag{false};

bool Write_String(const string& input, const int& sd)
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
    //cout<<sizeChar<<'^';
    if(write(sd,sizeChar, 10)<=0)
    {
        cout<<"Eroare la write (SIZE)\n";
        return false;
    }
    //cout<<input<<'^'<<endl;
    if(write(sd, input.data(), size)<=0)
    {
        cout<<"Eroare la write (Mesaj)\n";
        return false;
    }
    return true;
}

bool Read_String(string &output, const int& sd)
{
    char sizeInput[11];
    if(read(sd, sizeInput, 10)<=0)
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
    if(read(sd, out, (size_t)size)<0)
    {
        cout<<"Eroare la read (Mesaj)\n";
        return false;
    }
    output.assign(out, 0, (unsigned long)size);
    return true;
}

string NoRobot()
{
    cout<<"Pentru a accesa aplicatia trebuie sa verificam faptul ca nu esti robot!\n";
    cout<<"Pentru asta va trebui sa raspunzi la o intrebare simpla:\n";
    string CheckRobot;
    srand(time(NULL));
    int x=rand()%5;
    switch(x)
    {
        case 0:
            CheckRobot="Cat fac 100*3?\n";
            break;
        case 1:
            CheckRobot="Introdu textul 'Sunt Robot'\n";
            break;
        case 2:
            CheckRobot="Cate picioare are pisica?\n";
            break;
        case 3:
            CheckRobot="Care este numele de familie al creatorului aplicatiei?\n";
            break;
        case 4:
            CheckRobot="Ce Culoare are zapada?\n";
            break;
        default:
            break;
    }
    CheckRobot+="Raspuns: ";
    return CheckRobot;
}

bool LOGIN(const int& sd)
{
    string temp,temp2;
    cout<<"Nume: ";
    cin.ignore();
    getline(std::cin,temp);
    string Autentificare=temp;
    Autentificare+="\n";
    cout<<"Password: ";
    getline(std::cin,temp2);
    Autentificare+=temp2;
    /*ssize_t retval=write(sd, Autentificare.data(), Autentificare.size());
    if (retval < 0) //trimitem mesajul sirul catre server//
    {
        perror ("[C]Eroare la write() in login spre server.\n"); //tratam eroarea
        return false;
    }
    else if (retval==0)
    {
        perror("[C]Nu s-a scris nimic catre server in login\n");
        return false;
    }*/
    Write_String(Autentificare,sd);
    string Complete;
    /*if(read(sd,Complete,sizeof(Complete))<0)
    {
        perror("[C]Eroare la read de server in login, mesaj final");
        return false;
    }*/
    Read_String(Complete, sd);
    cout<<Complete;
    if(Complete=="Autentificare reusita\n")
        return true;
    return false;

}

bool ForgotPassword(const int& sd)
{
    string tempUsername;
    cout<<"Username: ";
    cin.ignore();
    getline(std::cin, tempUsername);
    /*ssize_t retval=write(sd, tempUsername.data(), tempUsername.size());
    if (retval < 0) //trimitem mesajul sirul catre server//
    {
        perror ("[C]Eroare la write() in \nForgotPassword spre server.\n"); //tratam eroarea
        return false;
    }
    else if (retval==0)
    {
        perror("[C]Nu s-a scris nimic catre server in ForgotPassword\n");
        return false;
    }*/
    Write_String(tempUsername,sd);
    /*if(read(sd,ForgPass,sizeof(ForgPass))<0)
    {
        perror("[C]Eroare la read de la server in ForgotPassword, mesaj final");
        return false;
    }*/
    string FORGPASS;
    Read_String(FORGPASS,sd);
    if(FORGPASS[0]=='W' && FORGPASS[6]=='U')
    {
        cout<<FORGPASS<<'\n';
        return false;
    }
    else
    {
        string ForgPass2=FORGPASS;
        size_t found=ForgPass2.find("\n");
        size_t found2=ForgPass2.find("#$#");
        string SQ, SA, PASSWORD;
        SQ.assign(ForgPass2,0,found); //intrebare secreta \n raspuns secret ### password
        SA.assign(ForgPass2,found+1,found2-found-1);

        PASSWORD.assign(ForgPass2, found2+3,ForgPass2.size()-(found2+3));
        cout<<"Raspundeti la intrebarea secreta: \n";
        cout<<SQ;
        string answer;
        cout<<"\nRaspuns: ";
        //cin.ignore();
        getline(std::cin, answer);
        //cout<<answer<<"***"<<SA<<"*********\n";
        if(answer==SA)
        {
            cout<<"Parola ta este:\n";
            cout<<PASSWORD<<'\n';
            return true;
        }
    }
    return false;
}

bool REGISTER(const int& sd)
{
    string User, Pass, SQ, SA;
    cout<<"Username:\n";
    cin.ignore();
    getline(std::cin, User);
    cout<<"Password:\n";
    getline(std::cin, Pass);
    cout<<"Intrebare secreta:\n";
    getline(std::cin, SQ);
    cout<<"Raspuns pentru intrebarea secreta:\n";
    getline(std::cin, SA);
    string RegisterSTR=User;
    RegisterSTR+="\n";
    RegisterSTR+=Pass;
    RegisterSTR+="\n";
    RegisterSTR+=SQ;
    RegisterSTR+="\n";
    RegisterSTR+=SA;
    /*if(write(sd,RegisterSTR.data(),RegisterSTR.size())<0)
    {
        perror("Eroare la write catre server in Register\n");
        return false;
    }*/
    Write_String(RegisterSTR,sd);
    string RaspRegister;
    /*if(read(sd,RaspRegister,sizeof(RaspRegister))<0)
    {
        perror("Eroare la read de la server in Register\n");
        return false;
    }*/
    Read_String(RaspRegister,sd);
    if(RaspRegister=="Username ERROR")
    {
        cout<<"This username is already used\n";
        return false;
    }
    else if(RaspRegister=="Success")
        return true;
    else
        return false;
}

bool EditProfil(const int& sd)
{
    string msgforWrite;
    Read_String(msgforWrite,sd);
    string fin;
    cout<<"Informatii actuale despre profil: \n";
    cout<<msgforWrite;
    cout << "\nCe doresti sa modifici? \n";
    cout << "1. Edit Last Name\n";
    cout << "2. Edit First Name\n";
    cout << "3. Edit Visibility\n";
    cout << "4. Back!\n"; //TO DO -> nu mai face functioneaza nimic dupa back
    char msgEditProfil[10];
    cin >> msgEditProfil;
    int decProfil = atoi(msgEditProfil);
    decProfil += 50;
    if (decProfil >= 54 || decProfil <=50 )
    {
        fin="Back";
        Write_String(fin, sd);
        string Ret;
        Read_String(Ret, sd);
        cout<<"STOP CLIENT";
        return false;
    }
    string mihnea=to_string(decProfil);
    Write_String(mihnea,sd);
    switch(decProfil)
    {
        case 51:
            cout<<"New Last Name: ";//51 New_Last_Name
            break;
        case 52:
            cout<<"New First Name: ";//52 New_First_Name
            break;
        case 53:
            cout<<"Visibility: \n";
            break;
        default:
            break;
    }
    if(decProfil==51 || decProfil==52)
    {
        cin.ignore();
        string edit;
        getline(std::cin, edit);
        Write_String(edit, sd);
    }
    else if(decProfil==53)
    {
        cout<<"0. Exit\n";
        cout<<"1. Public\n";
        cout<<"2. Private\n";
        cout<<"3. Friends\n";
        cout<<"4. Friends of Friends\n";
        string kk;
        cin>>kk;
        if(kk!="0" && kk!="1" && kk!="2" && kk!="3" && kk!="4")
            kk="0";
        Write_String(kk, sd);
        if(kk=="0")
        {
            string ret="Ne intoarcem la meniul de editari..\n";
            cout<<ret;
            return true;
        }
    }
    string ret;
    Read_String(ret, sd);
    if(ret=="Complete")
        cout<<"Editare reusita!\n";
    else
        cout<<"Au fost intampinate erori la editare!\n";
    return true;
}

bool Viz_Prof(const int& sd)
{
    string input;
    int in=0;
    while(in!=3) {
        cout << "Pe al cui profil vrei sa il vezi?\n";
        cout << "1. Toate\n";
        cout << "2. Introduc un nume/prenume\n";
        cout << "3. Back!\n";
        //cout << "4. EXIT app\n";
        cin >> in;
        if(in!=1 && in!=2)
            in=3;
        if (in == 1)
            Write_String("#toate#", sd);
        else if (in==2)
        {
            string NorP;
            cout << "Introduceti numele sau prenumele userului pentru care vreti sa afisati profilul\n";
            cin.ignore();
            getline(std::cin, NorP);
            Write_String(NorP, sd);
        }
        else if (in==3)
        {
            Write_String("#BACK#",sd);
            Read_String(input, sd);
            cout << input;
            return false;
        }
        Read_String(input, sd);
        cout << input;

    }
    return true;
}

bool Request_Manager(const int& sd)
{
    string cereri="Cereri de prietenie:\n1.Cereri primite\n2.Cereri trimise\n3.Trimite o cerere de prietenie\n4.Accepta o cerere de prietenie\n5.Back\n";
    cout<<cereri;
    string RetCereri;
    string BackCereri;
    int what;
    cin>>what;
    if(what<1||what>5)
        what=5;
    if(what==1)
        RetCereri="FriendRequests";
    else if(what==2)
        RetCereri="RequestsSent";
    else if(what==3)
    {
        RetCereri="SaFR\n";
        int pick;
        cout<<"Trimite catre:\n1.Username\n2.Nume si prenume\n";
        cin>>pick;
        string var;
        while(pick!=1&&pick!=2)
        {
            cout<<"Ati ales gresit. Introduceti din nou!\n";
            cin>>pick;
        }
        if(pick==1)
        {
            RetCereri+="User\n";
            cout<<"Username: ";
            cin.ignore();
            getline(std::cin,var);
            RetCereri+=var;
        }
        else if(pick==2)
        {
            RetCereri+="NsiP\n";
            cout<<"Nume: ";
            cin.ignore();
            getline(std::cin,var);
            RetCereri+=var;
            cout<<"Prenume: ";
            //cin.ignore();
            getline(std::cin,var);
            RetCereri+="\n";
            RetCereri+=var;
        }
    }
    else if(what==4)
    {
        RetCereri="AaFR\n";
        int pick;
        cout<<"Accepta de la:\n1.Username\n2.Nume si prenume\n";
        cin>>pick;
        string var;
        while(pick!=1&&pick!=2)
        {
            cout<<"Ati ales gresit. Introduceti din nou!\n";
            cin>>pick;
        }
        if(pick==1)
        {
            RetCereri+="User\n";
            cout<<"Username: ";
            cin.ignore();
            getline(std::cin,var);
            RetCereri+=var;
        }
        else if(pick==2)
        {
            RetCereri+="NsiP\n";
            cout<<"Nume: ";
            cin.ignore();
            getline(std::cin,var);
            RetCereri+=var;
            cout<<"Prenume: ";
            //cin.ignore();
            getline(std::cin,var);
            RetCereri+="\n";
            RetCereri+=var;
        }
    }
    else if(what==5)
        RetCereri="BackFR\n";
    Write_String(RetCereri,sd);
    Read_String(BackCereri,sd);
    cout<<BackCereri;
    cout<<"Press any key to continue...\n";
    if(BackCereri=="BackFR\n")
        return false;
    string just;
    cin>>just;
    return true;
}
bool Create_Post(const int& sd)
{
    string Post;
    cout<<"Alege tipul de vizibilitate al postarii tale\n";
    cout<<"0. Back\n";
    cout<<"1. Public\n"; //53 Set visibilty public
    cout<<"2. Private\n"; //54 set visibility private
    cout<<"3. Friends\n"; //55 set visibility friends
    cout<<"4. Friends of Friends\n";
    int pick;
    cin>>pick;
    if(pick<0 || pick>4)
        pick=0;
    Post=to_string(pick);
    Post+="\n";
    if(pick==0)
    {
        Post+="#";
        Write_String(Post,sd);
        string status1;
        Read_String(status1,sd);
        cout<<status1;
        if(status1=="Nu a fost publicata postarea\n")
            return false;
    }
    string MSJ;
    cout<<"Scrieti mesajul postarii.\nPostarea va fi publicata in momentul in care apasati tasta <ENTER>\n";
    cout<<"Daca doriti sa anulati crearea postarii introduceti la finalul mesajului caracterul <#>\n";
    cin.ignore();
    getline(std::cin,MSJ);
    Post+=MSJ;
    Write_String(Post,sd);
    string status;
    Read_String(status,sd);
    cout<<status;
    if(status=="Nu a fost publicata postarea\n")
        return false;
    return true;
}

bool Vezi_Postari(const int& sd)
{
    cout<<"Ce postari doresti sa vezi?\n";
    cout<<"1. Toate postarile disponibile\n";
    cout<<"2. Postarile unui anumit utilizator\n";
    cout<<"3. Postarile mele\n";
    cout<<"4. Back\n";
    int pick;
    cin>>pick;
    if(pick<1||pick>4)
        pick=4;
    if(pick==4)
    {
        Write_String("Back_to_meniu_principal\n",sd);
        cout<<"Ne intoarcem la meniul principal...\n";
        return false;
    }
    else if(pick==1)
    {
        Write_String("All posts\n", sd);
        string posts;
        Read_String(posts,sd);
        cout<<"Postarile pe care le poti vedea in acest moment sunt: \n";
        cout<<posts;
        cout<<"Press any key to continue...\n";
        string key;
        cin>>key;
        return true;
    }
    else if(pick==2)
    {
        cout<<"Introduceti username-ul persoanei careia doresti sa ii vezi postarile: \n";
        cout<<"Username: ";
        string username;
        cin.ignore();
        getline(std::cin,username);
        Write_String(username, sd);
        string StatusOrOutput;
        Read_String(StatusOrOutput,sd);
        cout<<"Postarile utilizatorului "<<username<<":\n";
        cout<<StatusOrOutput;
        cout<<"Press any key to continue...\n";
        string key;
        cin>>key;
        return true;
    }
    else if(pick==3)
    {
        Write_String("My Posts\n",sd);
        string myPOSTS;
        Read_String(myPOSTS,sd);
        cout<<"Acestea sunt postarile facute de tine: \n";
        cout<<myPOSTS;
        cout<<"Press any key to continue...\n";
        string key;
        cin>>key;
        return true;
    }
}

void AnyKey()
{
    cout<<"Press any key to continue...\n";
    string key;
    cin>>key;
}

bool Administrare(const int& sd)
{
    string Status;
    Read_String(Status, sd);
    if (Status!="Owner" && Status!="Admin")
    {
        cout<<"Ne pare rau, dar nu ai acces la acest panou de administrare\n";
        cout<<"Ca sa poti avea acces trebuie sa ai grad de Admin sau sa fii ownerul acestui server\n";
        return false;
    }
    else if(Status=="Admin")
    {
        cout<<"Gradul tau pe server este: "<<Status;
        cout<<"\nBun venit la panoul de administrare al serverului\nCe doresti sa faci?\n";
        cout<<"1. Lista privilegiilor gradelor de pe server\n";
        cout<<"2. Sterge o postare\n";
        cout<<"3. Schimba vizibilitatea unei postari\n";
        cout<<"4. Back\n";
        string input;
        cin>>input;
        if(input[0]!='1' && input[0]!='2' && input[0]!='3' && input[0]!='4')
            input="4";
        Write_String(input,sd);
        if(input=="1")
        {
            string privilegii;
            Read_String(privilegii,sd);
            cout<<privilegii;
            AnyKey();
            return true;
        }
        else if(input=="2")
        {
            string PostsData;
            Read_String(PostsData,sd);
            cout<<"Aici ai afisate toate postarile impreuna cu id-ul lor.\n Pentru a sterge o postare va trebui sa introduci id-ul acesteia!\n";
            cout<<PostsData;
            cout<<"Introdu id-ul postarii pe care doresti sa o stergi.\n Poti introduce un id gresit daca vrei sa anulezi\n";
            string IDfordelete;
            cin>>IDfordelete;
            Write_String(IDfordelete,sd);
            AnyKey();
            return true;
        }
        else if(input=="3")
        {
            string PostsData;
            Read_String(PostsData,sd);
            cout<<"Aici ai afisate toate postarile impreuna cu id-ul lor.\n Pentru a modifica vizibilitatea unei postari va trebui sa introduci id-ul acesteia!\n";
            cout<<PostsData;
            cout<<"Introdu id-ul postarii pentru care vrei sa modifici vizibilitatea\n Poti introduce un id gresit daca vrei sa anulezi\n";
            string IDformodificare;
            cin>>IDformodificare;
            int vizibilitate;
            cout<<"Ce vizibilitate vrei sa aiba aceasta postare?\n";
            cout<<"1. Public\n";
            cout<<"2. Private\n";
            cout<<"3. Friends\n";
            cout<<"4. Friends of Friends\n";
            cin>>vizibilitate;
            IDformodificare+="\n";
            if(vizibilitate==2)
                IDformodificare+="Private";
            else if(vizibilitate==3)
                IDformodificare+="Friends";
            else if(vizibilitate==4)
                IDformodificare+="Friends of Friends";
            else
                IDformodificare+="Public";
            Write_String(IDformodificare,sd);
            AnyKey();
            return true;
        }
        else
        {
            string bk;
            Read_String(bk, sd);
            return false;
        }
    }
    else
    {
        cout<<"Gradul tau pe server este: "<<Status;
        cout<<"\nBun venit la panoul de administrare al serverului\nCe doresti sa faci?\n";
        cout<<"1. Lista privilegiilor gradelor de pe server\n";
        cout<<"2. Sterge o postare\n";
        cout<<"3. Schimba vizibilitatea unei postari\n";
        cout<<"4. Schimba gradul unui utilizator\n";
        cout<<"5. Back\n";
        string input;
        cin>>input;
        if(input[0]!='1' && input[0]!='2' && input[0]!='3' && input[0]!='4' && input[0]!='5')
            input="5";
        Write_String(input,sd);
        if(input=="1")
        {
            string privilegii;
            Read_String(privilegii,sd);
            cout<<privilegii;
            AnyKey();
            return true;
        }
        else if(input=="2")
        {
            string PostsData;
            Read_String(PostsData,sd);
            cout<<"Aici ai afisate toate postarile impreuna cu id-ul lor.\n Pentru a sterge o postare va trebui sa introduci id-ul acesteia!\n";
            cout<<PostsData;
            cout<<"Introdu id-ul postarii pe care doresti sa o stergi.\n Poti introduce un id gresit daca vrei sa anulezi\n";
            string IDfordelete;
            cin>>IDfordelete;
            Write_String(IDfordelete,sd);
            AnyKey();
            return true;
        }
        else if(input=="3")
        {
            string PostsData;
            Read_String(PostsData,sd);
            cout<<"Aici ai afisate toate postarile impreuna cu id-ul lor.\n Pentru a modifica vizibilitatea unei postari va trebui sa introduci id-ul acesteia!\n";
            cout<<PostsData;
            cout<<"Introdu id-ul postarii pentru care vrei sa modifici vizibilitatea\n Poti introduce un id gresit daca vrei sa anulezi\n";
            string IDformodificare;
            cin>>IDformodificare;
            int vizibilitate;
            cout<<"Ce vizibilitate vrei sa aiba aceasta postare?\n";
            cout<<"1. Public\n";
            cout<<"2. Private\n";
            cout<<"3. Friends\n";
            cout<<"4. Friends of Friends\n";
            cin>>vizibilitate;
            IDformodificare+="\n";
            if(vizibilitate==2)
                IDformodificare+="Private";
            else if(vizibilitate==3)
                IDformodificare+="Friends";
            else if(vizibilitate==4)
                IDformodificare+="Friends of Friends";
            else
                IDformodificare+="Public";
            Write_String(IDformodificare,sd);
            AnyKey();
            return true;
        }
        else if(input=="4")
        {
            string grad;
            string Id;
            cout<<"ID: ";
            cin>>Id;
            cout<<"Grad: ";
            cin>>grad;
            Id+="\n";
            Id+=grad;
            Write_String(Id,sd);
            AnyKey();
            return true;
        }
        else
        {
            string bk;
            Read_String(bk, sd);
            return false;
        }
    }
}

void *Refresh(const int& sd, const string& myusername)
{
    while(!exit_thread_flag)
    {
        //sleep(10);
        for(unsigned i=0; i<10; i++)
        {
            if(exit_thread_flag)
                return nullptr;
            sleep(1);
        }
        if (!Write_String("refresh", sd))
            break;
        string out;
        if (!Read_String(out, sd))
            break;
        if(out!="Nu sunt mesaje noi\n")
        {
            cout << '\n' << out;
        }
    }
    return nullptr;
}

bool Keep_Talking(const string& myusername, const int& sd)
{

    string msjsent;
    cout<<"Puteti conversa cu acest(i) utilizator. Conversatia se va opri cand veti introduce <STOP>\n";
    cout<<"Pentru a vedea noile mesaje din sistem introduceti <REFRESH>\n";
    exit_thread_flag=false;
    thread c(Refresh, sd, myusername);
    cin.ignore();
    do{
        cout<<'*'<<myusername<<"*: ";
        getline(std::cin,msjsent);
        if(msjsent=="stop" || msjsent=="STOP")
        {
            exit_thread_flag=true;
            c.join();
            Write_String(msjsent,sd);
            break;
        }
        Write_String(msjsent,sd);
        if(msjsent=="refresh" || msjsent=="REFRESH" || msjsent=="Refresh")
        {
            string out;
            Read_String(out,sd);
            cout<<out;
        }
    }while(msjsent!="stop"&&msjsent!="STOP");
    return true;
}

bool History(const int& sd)
{
    string history;
    Read_String(history,sd);
    cout<<history;
    if(history=="Nu esti prieten cu acest utilizator\n")
        return false;
    string MyUsername;
    Read_String(MyUsername,sd);
    Keep_Talking(MyUsername,sd);
    return true;
}

bool Start_a_New_Conversation(const int& sd)
{
    cout<<"Introdu username-ul persoanei cu care doresti sa incepi o conversatie\n";
    cout<<"Daca vrei sa anulezi introdu <Back!>\n";
    cout<<"Username: ";
    string username;
    cin>>username;
    if(username=="Back!")
    {
        Write_String("Back#new_conv",sd);
        return false;
    }
    else
    {
        Write_String(username,sd);
        string check;
        Read_String(check,sd);
        if(check=="fail")
        {
            cout<<"Username gresit\n";
            return false;
        }
        History(sd);
        return true;
    }
}

bool Start_a_New_Conversation_Group(const int& sd)
{
    cout<<"Introdu pe rand username-ul persoanelor cu care doresti sa incepi o conversatie de grup\n";
    cout<<"Daca vrei sa te opresti introdu <stop>\n";
    string username;
    bool one=false;
    //vector<string> validusernames;
    while(username!="stop")
    {
        cout << "Username: ";
        cin >> username;
        if (username == "stop")
        {
            Write_String("Back#new_conv", sd);
            if(one)
            {
                History(sd);
                return true;
            }

        }
        else
        {
            one=true;
            Write_String(username, sd);
            string check;
            Read_String(check, sd);
            if (check == "fail")
            {
                cout << "Username gresit\n";
            }
            //else
                //validusernames.emplace_back(username);
        }
    }
    return false;
}

bool Actual_Conversations(const int& sd)
{
    string lista;
    Read_String(lista,sd);
    cout<<lista<<'\n';
    Start_a_New_Conversation(sd);
    return true;
}

bool Actual_Conversations_Group(const int& sd)
{
    string lista;
    Read_String(lista,sd);
    cout<<lista<<'\n';
    cout<<"Pentru a incepe o conversatie in grup introduceti username-urile tuturor utilizatorilor din acel grup\n";
    cout<<"*fara username-ul tau; introducerea altor username-uri va genera un alt grup\n";
    Start_a_New_Conversation_Group(sd);
    return true;
}

bool Conversatie(const int& sd)
{
    cout<<"1. Vezi conversatii actuale\n";
    cout<<"2. Incepe o conversatie noua\n";
    cout<<"3. Back\n";
    string pick;
    cin>>pick;
    if(pick!="1" && pick!="2" && pick!="3")
        pick="3";
    if(pick=="1")
    {
        Write_String("conversatii_actuale",sd);
        Actual_Conversations(sd);
        return true;
    }
    else if(pick=="2")
    {
        Write_String("new_conversation",sd);
        Start_a_New_Conversation(sd);
        return true;
    }
    else
    {
        Write_String("BACK#conv",sd);
        cout<<"Ne intoarcem la meniul principal...\n";
        return false;
    }
}

bool Conversatie_Group(const int& sd)
{
    cout<<"1. Vezi conversatii de grup actuale\n";
    cout<<"2. Incepe o conversatie de grup noua\n";
    cout<<"3. Back\n";
    string pick;
    cin>>pick;
    if(pick!="1" && pick!="2" && pick!="3")
        pick="3";
    if(pick=="1")
    {
        Write_String("conversatii_group_actuale",sd);
        Actual_Conversations_Group(sd);
        return true;
    }
    else if(pick=="2")
    {
        Write_String("new_group_conversation",sd);
        Start_a_New_Conversation_Group(sd);
        return true;
    }
    else
    {
        Write_String("BACK#conv_group",sd);
        cout<<"Ne intoarcem la meniul principal...\n";
        return false;
    }
}

bool After_Login(const int& sd, bool& ClientLogat)
{
    cout<<"\n\tCe ati dori sa faceti in aplicatie mai departe?\n";
    cout<<"1. Editare profil\n";
    cout<<"2. Vizualizare profiluri\n";
    cout<<"3. Creare postare\n";
    cout<<"4. Vizualizare postari\n";
    cout<<"5. Panou admin/owner\n";
    cout<<"6. Deschide o conversatie\n";
    cout<<"7. Deschide o conversatie de grup\n";
    cout<<"8. Cereri de prietenie\n";
    cout<<"9. Exit\n";
    char msg10[10];
    strcpy(msg10,"\0");
    cin>>msg10;
    int dec=atoi(msg10);
    dec+=10;
    char msg10fin[15];
    sprintf(msg10fin, "%d", dec);
    /*if(write(sd, msg10fin, sizeof(msg10fin))<0)
    {
        perror("Eroare la write catre server in comenzi dinsponibile pentru aplicatie\n");
        return errno;
    }*/
    //cout<<RETmsg10fin<<"ahh\n";

    /*if(read(sd,msgRETURN,300)<0)
    {
        perror("Eroare la read de la server in comenzi disponibile pentru aplicatie\n");
        return errno;
    }*/
    string RETmsg10fin(msg10fin);
    //cout<<"Msg sent: "<<RETmsg10fin<<endl;
    Write_String(RETmsg10fin,sd);
    string msgRETURN;
    Read_String(msgRETURN,sd);
    if(msgRETURN=="EXIT00")
    {
        cout<<"Conexiunea va fi inchisa\n";
        ClientLogat=false;
        //close(sd);
        return false;
    }
    else if(msgRETURN=="Editare Profil\n")
    {
        while(EditProfil(sd));
        return true;
    }
    else if(msgRETURN=="Vizualizare Profiluri: \n")
    {
        while(Viz_Prof(sd))
        {

        }
        return true;
        //cout<<"Status ok\n";
    }
    else if(msgRETURN=="Create Post\n")
    {
        Create_Post(sd);
        return true;
    }
    else if(msgRETURN=="Vezi postari\n")
    {
        while(Vezi_Postari(sd));
        return true;
    }
    else if(msgRETURN=="Administrare server\n")
    {
        while(Administrare(sd));
        return true;
    }
    else if(msgRETURN=="Conversatie\n")
    {
        while(Conversatie(sd));
        return true;
    }
    else if(msgRETURN=="Grup_Conv\n")
    {
        while(Conversatie_Group(sd));
        return true;
    }
    else if(msgRETURN=="Cereri\n")
    {
        while(Request_Manager(sd))
        {}
        return true;
    }
    else
    {
        ClientLogat=false;
        return false;
    }
}

bool No_Login(const int& sd)
{
    cout<<"Accesul dumneavoastra in aplicatie este limitat. Pentru a avea acces full va trebui sa va autentificati\n";
    cout<<"Alege o optiune:\n";
    cout<<"1. Vizualizare postari publice\n";
    cout<<"2. Vizualizare profiluri publice\n";
    cout<<"3. Back\n";
    string input;
    cin>>input;
    if(input!="1" && input!="2" && input!="3")
        input="3";
    Write_String(input, sd);
    string pick;
    Read_String(pick,sd);
    if(pick=="posts")
    {
        string postari;
        Read_String(postari,sd);
        cout<<postari;
        return true;
    }
    else if(pick=="profiles")
    {
        string profiluri;
        Read_String(profiluri, sd);
        cout<<profiluri;
        return true;
    }
    else
    {
        cout<<"Revenire la meniul principal..\n";
        return false;
    }
}

bool Meniu_Principal(const int& sd, bool& ClientLogat, bool& ClientNoLog)
{
    char msg[10];
    Again:
    printf("\t\tVirtualSoc\n");
    printf("\tAlegeti o optiune:\n");
    printf("1. LOGIN\n");
    printf("2. NO-LOGIN\n");
    printf("3. REGISTER\n");
    printf("4. FORGOT PASSWORD\n");
    printf("5. EXIT\n");
    cin>>msg;
    int ccck=atoi(msg);
    if (ccck<1 || ccck>5)
    {
        cout<<"Input gresit, alegeri posibile: '1', '2', '3', '4', '5'\n";
        goto Again;
    }
    string MSGstr(msg);
    Write_String(MSGstr, sd);
    /*if (write (sd, msg, 5) <= 0) //trimitem mesajul sirul catre server//
    {
        perror ("[C]Eroare la write() spre server.\n"); //tratam eroarea
        return errno;
    }*/

    //fflush(stdin); //golim bufferul
    //bzero(msg2,30); //initializam msg2 cu 0
    /*if (read (sd, msg2, 30) < 0) //citim raspunsul trimis de catre server+
    {
        perror("[C]Eroare la read() de la server.\n"); //tratam eroarea
        return errno;
    }*/
    /*for(int i=0; i<MSGRET.size();i++)
    {
        msg2[i]=MSGRET[i];
        int b=i;
        b++;
        msg2[b]='\0';
    }*/
    string MSGRET;
    Read_String(MSGRET,sd);
    if(MSGRET=="Login")
    {
        if (LOGIN(sd)==true)
        {
            ClientLogat=true;
            /*bool stat=true;
            while(ClientLogat)
            {
                stat=After_Login(sd, ClientLogat);
                if(!stat==false)
                    return true;
            }*/
            while(After_Login(sd,ClientLogat))
            {}
            return true;
        }
        return true;
    }
    else if(MSGRET== "NoLog")
    {
        ClientNoLog=true;
        while(No_Login(sd));
        return true;
    }
    else if(MSGRET=="EXIT")
    {
        cout<<"Conexiunea va fi inchisa\n";
        close(sd);
        return false;
    }
    else if(MSGRET=="Forgot")
    {
        cout<<MSGRET<<endl;
        if(ForgotPassword(sd))
            cout<<"Parola recuperata cu succes\nAcum va puteti autentifica!\n";
        else
            cout<<"Eroare la recuperarea parolei\nReintoarcere la meniul principal...\n";
        return true;
    }
    else if(MSGRET=="REGISTER")
    {
        cout<<"Register:\n";
        if(REGISTER(sd))
            cout<<"Register complete. Log in!\n";
        else
            cout<<"Register error. Try Again!\n";
        return true;
    }
    return false;
}

int main (int argc, char *argv[])
{
    int sd;	//descriptorul de socket
    struct sockaddr_in server;	//structura folosita pentru conectare 
    char msg[5];//mesajul trimis
    char msg2[30];

    if (argc != 3) //executia trebuie sa fie de tip ./nume.exe adresa port 
    {
        printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
        return -1;
    }
    port = atoi (argv[2]); //convertim portul la integer (portul este primit ca parametru (arg 2))

    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1) //crearea socketului
    {
        perror ("Eroare la socket().\n");
        return errno;
    }

    //umplem structura folosita pentru realizarea conexiunii cu serverul
    server.sin_family = AF_INET;//stabilirea familiei de socket-uri
    server.sin_addr.s_addr = inet_addr(argv[1]); //stabilim adresa serverului (arg 1)
    server.sin_port = htons (port); //stabilim portul

    if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1) //realizarea conectarii la server
    {
        perror ("[C]Eroare la connect().\n");
        return errno;
    }

    Write_String("ENTER",sd);
    //bzero (msg, 5); //initializam mesajul cu 0
    bool ClientLogat=false;
    bool ClientNoLog=false;
    while(Meniu_Principal(sd,ClientLogat,ClientNoLog)==true)
    {
        cout<<"Ne intoarcem la meniul principal\n";
    }
    close (sd); //inchidem conexiunea
}
