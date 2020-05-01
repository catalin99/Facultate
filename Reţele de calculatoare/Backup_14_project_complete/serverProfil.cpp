//
// Created by catalin on 15.12.2018.
//

#include "serverProfil.h"
#include <stdio.h>
#include <cstdlib>
using namespace std;
using json = nlohmann::json;
//std::ifstream users_login("../users_login_data.json");
//json login = json::parse(users_login);
//std::ifstream users_profil("../users_profil_data.json");
//json profil=json::parse(users_profil);

void serverProfil::PrintAllProfilData()
{
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    for (auto logi : login["Login_Info"]) {
        string username = logi["username"];
        cout << username << '\n';
    }
    users_login.close();
}

bool serverProfil::DelogheazaUser(int fd)
{
    map<int, string>::iterator it;
    it=ConnectedUsers.find(fd);
    if(it!=ConnectedUsers.end())
    {
        ConnectedUsers.erase(it);
        return true;
    }
    return false;
}

void serverProfil::FillMap(int fd, string username)
{
    string id;
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    for(auto lgi:login["Login_Info"])
    {
        string User=lgi["username"];
        string Id=lgi["id"];
        if (User == username) {
            id = Id;
            break;
        }
    }
    users_login.close();
    ConnectedUsers.insert(pair<int, string>(fd, id));
}

void serverProfil::PrintMap(){
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    for(auto &i:ConnectedUsers)
        cout<<"Descriptor "<<i.first<<", id: "<<i.second<<endl;
    users_login.close();
}

string serverProfil::checkUser(string username)
{
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    for(auto lgi:login["Login_Info"])
    {
        string User=lgi["username"];
        string Pass=lgi["password"];
        if(User==username)
        {
            users_login.close();
            return Pass;
        }
    }
    users_login.close();
    return "fail#";
}

string serverProfil::checkFP(string username)
{
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    for(auto lfp:login["Login_Info"])
    {
        string User=lfp["username"];
        string RetSTR=lfp["secret_quest"];
        RetSTR+="\n";
        RetSTR+=lfp["secret_ans"];
        RetSTR+="#$#";
        RetSTR+=lfp["password"];
        if(User==username)
        {
            users_login.close();
            return RetSTR;
        }
    }
    users_login.close();
    return "fail#";
}

void serverProfil::NoLogConfirm()
{
    NoLogin=true;
}

bool serverProfil::NoLog(int fd)
{
    string ID=GetIdFromMap(fd);
    if(ID.empty())
        return true;
    return false;
}

short serverProfil::Register(string username, string password, string sq, string sa)
{
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    for (auto iz:login["Login_Info"])
    {
        string Wrong=iz["username"];
        if (Wrong==username)
            return 2;
    }
    string idd=login["Id_Start"];
    int id=atoi(idd.data());
    id++;
    char chrr[20];
    sprintf(chrr,"%d",id);
    string chr(chrr);
    vector<string> requests;
    requests.emplace_back("0");
    //login data part
    login["Id_Start"]=chr;
    login["Login_Info"][chr]["username"]=username;
    login["Login_Info"][chr]["password"]=password;
    login["Login_Info"][chr]["secret_quest"]=sq;
    login["Login_Info"][chr]["secret_ans"]=sa;
    login["Login_Info"][chr]["id"]=chr;
    login["Login_Info"][chr]["request_send"]=requests;
    login["Login_Info"][chr]["request_received"]=requests;
    std::ofstream users_login_out("../users_login_data.json");
    users_login_out<<login.dump(2);
    users_login_out.close();
    users_login.close();
    //profil data part
    string defaultN, defaultViz, defaultGrad, defaultPosts;
    defaultN="-";
    defaultViz="Public";
    defaultGrad="Normal User";
    defaultPosts="0";
    vector<string> vectornull;
    vectornull.emplace_back("0");
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    profil["Profil_Info"][chr]["Nume"]=defaultN;
    profil["Profil_Info"][chr]["Prenume"]=defaultN;
    profil["Profil_Info"][chr]["Vizibilitate"]=defaultViz;
    profil["Profil_Info"][chr]["Grad"]=defaultGrad;
    profil["Profil_Info"][chr]["Posts"]=defaultPosts;
    profil["Profil_Info"][chr]["id"]=chr;
    profil["Profil_Info"][chr]["Friends"]=vectornull;
    std::ofstream users_profil_out("../users_profil_data.json");
    users_profil_out<<profil.dump(2);
    users_profil_out.close();
    users_profil.close();
    return 1;
}

string serverProfil::MyProfilInfo(int fd)
{
    string ProfilInfos;
    string id;
    for(auto &i:ConnectedUsers)
        if(i.first==fd)
            id=i.second;
    string tempdata;
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    for(auto lgn:login["Login_Info"])
    {
        string tempid2=lgn["id"];
        if(tempid2==id)
        {
            tempdata="Username: ";
            tempdata+=lgn["username"];
            break;
        }
    }
    for(auto inf:profil["Profil_Info"])
    {
        string tempid=inf["id"];
        if(tempid==id)
        {
            tempdata=inf["Nume"];
            ProfilInfos+="\nLast Name: ";
            ProfilInfos+=tempdata;
            tempdata=inf["Prenume"];
            ProfilInfos+="\nFirst Name: ";
            ProfilInfos+=tempdata;
            tempdata=inf["Vizibilitate"];
            ProfilInfos+="\nVizibility: ";
            ProfilInfos+=tempdata;
            tempdata=inf["Grad"];
            ProfilInfos+="\nGrade: ";
            ProfilInfos+=tempdata;
            tempdata=inf["Posts"];
            ProfilInfos+="\nPosts: ";
            ProfilInfos+=tempdata;
            cout<<"[LOG]"<<'\n';
            cout<<tempdata<<'\n'<<ProfilInfos<<'\n';
            cout<<"[END_LOG]"<<'\n';
            users_profil.close();
            return ProfilInfos;
        }
    }
    ProfilInfos="Error";
    users_profil.close();
    return ProfilInfos;
}

string serverProfil::GetIdFromMap(int fd)
{
    string id;
    for(auto &parc:ConnectedUsers)
    {
        if (parc.first == fd)
            id = parc.second;
    }
    return id;
}

string serverProfil::GetGradFromID(string ID)
{
    string GRAD;
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    users_profil.close();
    GRAD=profil["Profil_Info"][ID]["Grad"];
    return GRAD;
}

void serverProfil::UpdateLastName(string Var, int fd)
{
    string ID=GetIdFromMap(fd);
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    profil["Profil_Info"][ID]["Nume"]=Var;
    std::ofstream users_profil_out("../users_profil_data.json");
    users_profil_out<<profil.dump(2);
    users_profil_out.close();
    users_profil.close();
}

void serverProfil::UpdateFirstName(string Var, int fd)
{
    string ID=GetIdFromMap(fd);
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    profil["Profil_Info"][ID]["Prenume"]=Var;
    std::ofstream users_profil_out("../users_profil_data.json");
    users_profil_out<<profil.dump(2);
    users_profil_out.close();
    users_profil.close();
}

void serverProfil::UpdateVisibility(string Var, int fd)
{
    string ID=GetIdFromMap(fd);
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    profil["Profil_Info"][ID]["Vizibilitate"]=Var;
    std::ofstream users_profil_out("../users_profil_data.json");
    users_profil_out<<profil.dump(2);
    users_profil_out.close();
    users_profil.close();
}

bool serverProfil::isFriend(const string& myid,const string& idfriend)
{
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    for(auto fri:profil["Profil_Info"])
    {
        if(myid==fri["id"])
        {
            vector<string> friend_list=fri["Friends"];
            for(auto temp:friend_list)
            {
                if (temp == idfriend)
                {
                    users_profil.close();
                    return true;
                }
            }
            users_profil.close();
            return false;
        }
    }
    users_profil.close();
    return false;
}

bool serverProfil::isFriendofFriends(const string& myid,const string& idfriend)
{
    if(isFriend(myid,idfriend))
        return true;
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    vector<string> friend_list;
    for(auto fri:profil["Profil_Info"])
    {
        if(myid==fri["id"])
        {
            vector<string>friend_list_temp=fri["Friends"];
            friend_list=friend_list_temp;
            break;
        }
    }
    users_profil.close();
    for(auto parcvect:friend_list)
    {
        std::ifstream users_profil2("../users_profil_data.json");
        json profil2=json::parse(users_profil2);
        for(auto parcfriends:profil2["Profil_Info"])
        {
            if(parcvect==parcfriends["id"])
            {
                vector<string> friendoffriend_list=parcfriends["Friends"];
                for(auto temp:friendoffriend_list)
                {
                    if (temp == idfriend)
                    {
                        users_profil2.close();
                        return true;
                    }
                }
            }
        }
        users_profil2.close();
    }
    return false;
}

string serverProfil::VeziProfile(int fd) 
{
    bool NoLogin=NoLog(fd);
    string ID=GetIdFromMap(fd);
    string gradUser;
    string RETstr="Acestea sunt profilurile pe care le poti vedea:\n\n";
    if(NoLogin==false) 
    {
        std::ifstream users_profil("../users_profil_data.json");
        json profil = json::parse(users_profil);
        for (auto datas:profil["Profil_Info"]) {
            if (ID == datas["id"]) {
                gradUser = datas["Grad"];
                users_profil.close();
                break;
            }
        }
    } 
    else
        gradUser="Normal User";
    std::ifstream users_profil2("../users_profil_data.json");
    json profil2=json::parse(users_profil2);
    for(auto othersdata:profil2["Profil_Info"])
    {
        std::ifstream users_login("../users_login_data.json");
        json login = json::parse(users_login);
        users_login.close();
        string IDcreator=othersdata["id"];
        string Username=login["Login_Info"][IDcreator]["username"];
        string grad=othersdata["Grad"];
        string nume=othersdata["Nume"];
        string prenume=othersdata["Prenume"];
        string posts=othersdata["Posts"];
        string vizibilitate=othersdata["Vizibilitate"];
        string iidd=othersdata["id"];
        if(gradUser=="Normal User") 
        {
            if (vizibilitate == "Public") 
            {
                RETstr += "Username: ";
                RETstr += Username;
                RETstr += "\nNume: ";
                RETstr += nume;
                RETstr += "\nPrenume: ";
                RETstr += prenume;
                RETstr += "\nGrad: ";
                RETstr += grad;
                RETstr += "\nVizibilitate Profil: ";
                RETstr += vizibilitate;
                RETstr += "\nPostari: ";
                RETstr += posts;
                RETstr += "\n\n";
            }
            else if (vizibilitate=="Friends")
            {
                if(isFriend(ID,iidd)==true)
                {
                    RETstr += "Username: ";
                    RETstr += Username;
                    RETstr += "\nNume: ";
                    RETstr += nume;
                    RETstr += "\nPrenume: ";
                    RETstr += prenume;
                    RETstr += "\nGrad: ";
                    RETstr += grad;
                    RETstr += "\nVizibilitate Profil: ";
                    RETstr += vizibilitate;
                    RETstr += "\nPostari: ";
                    RETstr += posts;
                    RETstr += "\n\n";
                }
            }
            else if (vizibilitate=="Friends of Friends")
            {
                if(isFriend(ID,iidd)==true || isFriendofFriends(ID,iidd)==true)
                {
                    RETstr += "Username: ";
                    RETstr += Username;
                    RETstr += "\nNume: ";
                    RETstr += nume;
                    RETstr += "\nPrenume: ";
                    RETstr += prenume;
                    RETstr += "\nGrad: ";
                    RETstr += grad;
                    RETstr += "\nVizibilitate Profil: ";
                    RETstr += vizibilitate;
                    RETstr += "\nPostari: ";
                    RETstr += posts;
                    RETstr += "\n\n";
                }
            }
        }
        else {
            RETstr += "Username: ";
            RETstr += Username;
            RETstr += "\nNume: ";
            RETstr += nume;
            RETstr += "\nPrenume: ";
            RETstr += prenume;
            RETstr += "\nGrad: ";
            RETstr += grad;
            RETstr += "\nVizibilitate Profil: ";
            RETstr += vizibilitate;
            RETstr += "\nPostari: ";
            RETstr += posts;
            RETstr += "\n\n";
        }
    }
    users_profil2.close();
    return RETstr;
    
}

string serverProfil::VeziUnProfil(int fd, string PeCare) 
{
    bool NoLogin=false;
    string ID=GetIdFromMap(fd);
    if(ID.empty())
        NoLogin=true;
    string gradUser;
    string RETstr="Nu exista niciun utilizator cu acest nume/prenume in sistem\n\n";
    if(NoLogin==false)
    {
        std::ifstream users_profil("../users_profil_data.json");
        json profil = json::parse(users_profil);
        for (auto datas:profil["Profil_Info"]) {
            if (ID == datas["id"]) {
                gradUser = datas["Grad"];
                users_profil.close();
                break;
            }
        }
    }
    else
        gradUser="Normal User";
    std::ifstream users_profil2("../users_profil_data.json");
    json profil2=json::parse(users_profil2);
    for(auto othersdata:profil2["Profil_Info"]) {
        string grad = othersdata["Grad"];
        string nume = othersdata["Nume"];
        string prenume = othersdata["Prenume"];
        string posts = othersdata["Posts"];
        string vizibilitate = othersdata["Vizibilitate"];
        string iidd=othersdata["id"];
        if (nume == PeCare || prenume == PeCare) 
        {
            std::ifstream users_login("../users_login_data.json");
            json login = json::parse(users_login);
            users_login.close();
            string IDcreator=othersdata["id"];
            string Username=login["Login_Info"][IDcreator]["username"];
            if (gradUser == "Normal User") 
            {
                if (vizibilitate == "Public") 
                {
                    RETstr ="Am gasit utilizatorul cautat\nAcestea sunt informatiile despre profilul lui:\n";
                    RETstr += "Username: ";
                    RETstr += Username;
                    RETstr += "\nNume: ";
                    RETstr += nume;
                    RETstr += "\nPrenume: ";
                    RETstr += prenume;
                    RETstr += "\nGrad: ";
                    RETstr += grad;
                    RETstr += "\nVizibilitate Profil: ";
                    RETstr += vizibilitate;
                    RETstr += "\nPostari: ";
                    RETstr += posts;
                    RETstr += "\n\n";
                }
                else if (vizibilitate=="Friends")
                {
                    if(isFriend(ID,iidd)==true)
                    {
                        RETstr ="Am gasit utilizatorul cautat\nAcestea sunt informatiile despre profilul lui:\n";
                        RETstr += "Username: ";
                        RETstr += Username;
                        RETstr += "\nNume: ";
                        RETstr += nume;
                        RETstr += "\nPrenume: ";
                        RETstr += prenume;
                        RETstr += "\nGrad: ";
                        RETstr += grad;
                        RETstr += "\nVizibilitate Profil: ";
                        RETstr += vizibilitate;
                        RETstr += "\nPostari: ";
                        RETstr += posts;
                        RETstr += "\n\n";
                    }
                    else
                        RETstr="Nu ai acces sa vezi informatiile despre profilul acestui user\nNe pare rau\n\n";
                }
                else if (vizibilitate=="Friends of Friends")
                {
                    if(isFriendofFriends(ID,iidd)==true)
                    {
                        RETstr ="Am gasit utilizatorul cautat\nAcestea sunt informatiile despre profilul lui:\n";
                        RETstr += "Username: ";
                        RETstr += Username;
                        RETstr += "\nNume: ";
                        RETstr += nume;
                        RETstr += "\nPrenume: ";
                        RETstr += prenume;
                        RETstr += "\nGrad: ";
                        RETstr += grad;
                        RETstr += "\nVizibilitate Profil: ";
                        RETstr += vizibilitate;
                        RETstr += "\nPostari: ";
                        RETstr += posts;
                        RETstr += "\n\n";
                    }
                    else
                        RETstr="Nu ai acces sa vezi informatiile despre profilul acestui user\nNe pare rau\n\n";
                }
                else
                    RETstr="Nu ai acces sa vezi informatiile despre profilul acestui user\nNe pare rau\n\n";
            } 
            else {
                RETstr ="Am gasit utilizatorul cautat\nAcestea sunt informatiile despre profilul lui:\n";
                RETstr += "Username: ";
                RETstr += Username;
                RETstr += "\nNume: ";
                RETstr += nume;
                RETstr += "\nPrenume: ";
                RETstr += prenume;
                RETstr += "\nGrad: ";
                RETstr += grad;
                RETstr += "\nVizibilitate Profil: ";
                RETstr += vizibilitate;
                RETstr += "\nPostari: ";
                RETstr += posts;
                RETstr += "\n\n";
            }
            break;
        }
    }
    users_profil2.close();
    return RETstr;
}

bool serverProfil::CereriPrimite(int fd, string &Return)
{
    string ID=GetIdFromMap(fd);
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    vector<string> showdata;
    for(auto &list:login["Login_Info"])
    {
        if(ID==list["id"])
        {
            vector<string> REQ=list["request_received"];
            for(auto &str:REQ)
            {
                if(str!="0")
                {
                    showdata.emplace_back(str);
                }
            }
            break;
        }
    }
    for (auto &parc:showdata)
    {
        std::ifstream users_login2("../users_login_data.json");
        json login2 = json::parse(users_login2);
        users_login2.close();
        std::ifstream users_profil5("../users_profil_data.json");
        json profil5=json::parse(users_profil5);
        users_profil5.close();
        for(auto lg:login2["Login_Info"])
        {
            if(lg["id"]==parc)
            {
                string username=lg["username"];
                Return+="Username: ";
                Return+=username;
                Return+="\n";
                break;
            }
        }
        for(auto pf:profil5["Profil_Info"])
        {
            if(pf["id"]==parc)
            {
                string nume=pf["Nume"];
                Return+="Nume: ";
                Return+=nume;
                Return+="\n";
                string prenume=pf["Prenume"];
                Return+="Prenume: ";
                Return+=prenume;
                Return+="\n\n";
                break;
            }
        }
    }
    if(Return.empty())
        return false;
    return true;
}

bool serverProfil::CereriTrimise(int fd, string &Return)
{
    string ID=GetIdFromMap(fd);
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    vector<string> showdata;
    for(auto &list:login["Login_Info"])
    {
        if(ID==list["id"])
        {
            vector<string> REQ=list["request_send"];
            for(auto &str:REQ)
            {
                if(str!="0")
                {
                    showdata.emplace_back(str);
                }
            }
            break;
        }
    }
    for (auto &parc:showdata)
    {
        std::ifstream users_login2("../users_login_data.json");
        json login2 = json::parse(users_login2);
        users_login2.close();
        std::ifstream users_profil2("../users_profil_data.json");
        json profil2=json::parse(users_profil2);
        users_profil2.close();
        for(auto lg:login2["Login_Info"])
        {
            if(lg["id"]==parc)
            {
                string username=lg["username"];
                Return+="Username: ";
                Return+=username;
                Return+="\n";
                break;
            }
        }
        for(auto pf:profil2["Profil_Info"])
        {
            if(pf["id"]==parc)
            {
                string nume=pf["Nume"];
                Return+="Nume: ";
                Return+=nume;
                Return+="\n";
                string prenume=pf["Prenume"];
                Return+="Prenume: ";
                Return+=prenume;
                Return+="\n\n";
                break;
            }
        }
    }
    if(Return.empty())
        return false;
    return true;
}

bool serverProfil::GetIdFromMapByNP(const string &nume, const string &prenume, string &ID)
{

    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    users_profil.close();
    ID="Numele intrdus este gresit\n";
    for(auto pf:profil["Profil_Info"])
    {
        if(pf["Nume"]==nume)
        {
            ID="Prenumele introdus este gresit\n";
            //cout<<"Prenume cautat: "<<prenume<<"*\n";
            if(pf["Prenume"]==prenume)
            {
                ID=pf["id"];
                return true;
            }
        }
    }
    return false;

}

bool serverProfil::GetIdFromMapByUN(const string &username, string &ID)
{
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    ID="Username-ul introdus este gresit\n";
    for(auto lg:login["Login_Info"])
    {
        if(lg["username"]==username)
        {
            ID=lg["id"];
            return true;
        }
    }
    return false;

}

string serverProfil::SendReqbyNP(int fd, string nume, string prenume)
{
    string ID=GetIdFromMap(fd);
    string RETSTR;
    string IDreq;
    if(!GetIdFromMapByNP(nume, prenume,IDreq))
        return IDreq;
    if(isFriend(ID,IDreq))
    {
        RETSTR="Acest utilizator este deja in lista ta de prieteni!\n";
        return RETSTR;
    }
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    unsigned int counter=0;
    for(auto lg:login["Login_Info"])
    {
        if(ID==lg["id"])
        {
            vector<string> mine=lg["request_send"];
            for(auto &search:mine)
                if(search==IDreq)
                {
                    RETSTR="Ai trimis deja o cerere catre acest utilizator\n";
                    return RETSTR;
                }
            mine.emplace_back(IDreq);
            login["Login_Info"][ID]["request_send"]=mine;
            counter++;
            if(counter==2)
                break;
        }
        if(IDreq==lg["id"])
        {
            vector<string> rq=lg["request_received"];
            rq.emplace_back(ID);
            login["Login_Info"][IDreq]["request_received"]=rq;
            counter++;
            if(counter==2)
                break;
        }
    }
    std::ofstream users_login_out("../users_login_data.json");
    users_login_out<<login.dump(2);
    users_login_out.close();
    users_login.close();
    RETSTR="Cererea a fost trimisa!\n";
    return RETSTR;
}

string serverProfil::SendReqbyUsername(int fd, string username)
{
    string ID=GetIdFromMap(fd);
    string RETSTR;
    string IDreq;
    if(!GetIdFromMapByUN(username,IDreq))
        return IDreq;
    if(isFriend(ID,IDreq))
    {
        RETSTR="Acest utilizator este deja in lista ta de prieteni!\n";
        return RETSTR;
    }
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    int counter=0;
    for(auto lg:login["Login_Info"])
    {
        if(ID==lg["id"])
        {
            vector<string> mine=lg["request_send"];
            for(auto &search:mine)
                if(search==IDreq)
                {
                    RETSTR="Ai trimis deja o cerere catre acest utilizator\n";
                    return RETSTR;
                }
            mine.emplace_back(IDreq);
            login["Login_Info"][ID]["request_send"]=mine;
            counter++;
            if(counter==2)
                break;
        }
        if(IDreq==lg["id"])
        {
            vector<string> rq=lg["request_received"];
            rq.emplace_back(ID);
            login["Login_Info"][IDreq]["request_received"]=rq;
            counter++;
            if(counter==2)
                break;
        }
    }
    std::ofstream users_login_out("../users_login_data.json");
    users_login_out<<login.dump(2);
    users_login_out.close();
    users_login.close();
    RETSTR="Cererea a fost trimisa!\n";
    return RETSTR;
}

string serverProfil::AccReqbyNP(int fd, string nume, string prenume)
{
    string ID=GetIdFromMap(fd);
    string RETSTR;
    string IDreq;
    if(!GetIdFromMapByNP(nume, prenume,IDreq))
        return IDreq;
    if(isFriend(ID,IDreq))
    {
        RETSTR="Acest utilizator este deja in lista ta de prieteni!\n";
        return RETSTR;
    }
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    int counter=0;
    bool check=false;
    for(auto lg:login["Login_Info"])
    {
        if(ID==lg["id"])
        {
            check=true;
            vector<string> mine=lg["request_received"];
            for(unsigned int i=0; i<mine.size(); i++)
                if(mine[i]==IDreq)
                {
                    mine.erase(mine.begin()+i);
                    std::ifstream users_profil("../users_profil_data.json");
                    json profil=json::parse(users_profil);
                    users_profil.close();
                    for(auto add:profil["Profil_Info"])
                        if(add["id"]==ID)
                        {
                            vector<string> friend_list=add["Friends"];
                            friend_list.emplace_back(IDreq);
                            profil["Profil_Info"][ID]["Friends"]=friend_list;;
                            std::ofstream users_profil_out("../users_profil_data.json");
                            users_profil_out<<profil.dump(2);
                            users_profil_out.close();
                            break;
                        }
                    break;
                }
            login["Login_Info"][ID]["request_received"]=mine;
            counter++;
            if(counter==2)
                break;
        }
        if(IDreq==lg["id"])
        {
            vector<string> rq=lg["request_send"];
            for(unsigned int i=0; i<rq.size(); i++)
                if(rq[i]==ID)
                {
                    rq.erase(rq.begin()+i);
                    std::ifstream users_profil("../users_profil_data.json");
                    json profil=json::parse(users_profil);
                    users_profil.close();
                    for(auto add:profil["Profil_Info"])
                        if(add["id"]==IDreq)
                        {
                            vector<string> friend_list = add["Friends"];
                            friend_list.emplace_back(ID);
                            profil["Profil_Info"][IDreq]["Friends"] = friend_list;;
                            std::ofstream users_profil_out("../users_profil_data.json");
                            users_profil_out << profil.dump(2);
                            users_profil_out.close();
                            break;
                        }
                        break;
                }
            login["Login_Info"][IDreq]["request_send"]=rq;
            counter++;
            if(counter==2)
                break;
        }
    }
    if(!check)
    {
        RETSTR="Nu exista nicio cerere de la acest utilizator\n";
        return RETSTR;
    }
    std::ofstream users_login_out("../users_login_data.json");
    users_login_out<<login.dump(2);
    users_login_out.close();
    users_login.close();
    RETSTR="Cererea a fost acceptata!\n";
    return RETSTR;
}

string serverProfil::AccReqbyUsername(int fd, string username)
{
    string ID=GetIdFromMap(fd);
    string RETSTR;
    string IDreq;
    if(!GetIdFromMapByUN(username,IDreq))
        return IDreq;
    if(isFriend(ID,IDreq))
    {
        RETSTR="Acest utilizator este deja in lista ta de prieteni!\n";
        return RETSTR;
    }
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    int counter=0;
    bool check=false;
    for(auto lg:login["Login_Info"])
    {
        if(ID==lg["id"])
        {
            cout<<"Intrare mine\n";
            check=true;
            vector<string> mine=lg["request_received"];
            for(unsigned int i=0; i<mine.size(); i++)
                if(mine[i]==IDreq)
                {
                    mine.erase(mine.begin()+i);
                    std::ifstream users_profil("../users_profil_data.json");
                    json profil=json::parse(users_profil);
                    users_profil.close();
                    for(auto add:profil["Profil_Info"])
                    {
                        if(add["id"]==ID)
                        {
                            vector<string> friend_list=add["Friends"];
                            friend_list.emplace_back(IDreq);
                            profil["Profil_Info"][ID]["Friends"]=friend_list;;
                            std::ofstream users_profil_out("../users_profil_data.json");
                            users_profil_out<<profil.dump(2);
                            users_profil_out.close();
                            break;
                        }
                    }
                    break;
                }
            login["Login_Info"][ID]["request_received"]=mine;
            counter++;
            if(counter==2)
                break;
        }
        if(IDreq==lg["id"])
        {
            cout<<"Intrare rq\n";
            vector<string> rq=lg["request_send"];
            for(unsigned int i=0; i<rq.size(); i++)
                if(rq[i]==ID)
                {
                    rq.erase(rq.begin()+i);
                    std::ifstream users_profil("../users_profil_data.json");
                    json profil=json::parse(users_profil);
                    users_profil.close();
                    for(auto add:profil["Profil_Info"])
                    {
                        if (add["id"] == IDreq)
                        {
                            vector<string> friend_list = add["Friends"];
                            friend_list.emplace_back(ID);
                            profil["Profil_Info"][IDreq]["Friends"] = friend_list;;
                            std::ofstream users_profil_out("../users_profil_data.json");
                            users_profil_out << profil.dump(2);
                            users_profil_out.close();
                            break;
                        }
                    }
                    break;
                }
            login["Login_Info"][IDreq]["request_send"]=rq;
            counter++;
            if(counter==2)
                break;
        }
    }
    if(!check)
    {
        RETSTR="Nu exista nicio cerere de la acest utilizator\n";
        return RETSTR;
    }
    std::ofstream users_login_out("../users_login_data.json");
    users_login_out<<login.dump(2);
    users_login_out.close();
    users_login.close();
    RETSTR="Cererea a fost acceptata!\n";
    return RETSTR;
}

bool serverProfil::Make_Post(const int& fd, const string& Vis, const string& Post)
{
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    string IDuser=GetIdFromMap(fd);
    //update_nr_postari_start
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    users_profil.close();
    string nrPost=profil["Profil_Info"][IDuser]["Posts"];
    int nrPostInt=atoi(nrPost.data());
    nrPostInt++;
    nrPost=to_string(nrPostInt);
    profil["Profil_Info"][IDuser]["Posts"]=nrPost;
    std::ofstream users_profil_out("../users_profil_data.json");
    users_profil_out<<profil.dump(2);
    users_profil_out.close();
    //update_nr_postari_end;
    string Counter=post["Id_Start"];
    int idpostint=atoi(Counter.data());
    idpostint++;
    string IDpost=to_string(idpostint);
    post["Id_Start"]=IDpost;
    post["Posts"][IDpost]["Id_Post"]=IDpost;
    post["Posts"][IDpost]["Id_User"]=IDuser;
    post["Posts"][IDpost]["Status"]="ok";
    post["Posts"][IDpost]["Visibility"]=Vis;
    post["Posts"][IDpost]["Postare"]=Post;
    std::ofstream posts_out("../posts_data.json");
    posts_out << post.dump(2);
    posts_out.close();
    return true;
}

string serverProfil::VeziToatePostarile(const int& fd)
{
    string OUTstr="Nu exista postari in sistem sau nu ai acces sa vezi vreuna din ele!\n";
    string myID=GetIdFromMap(fd);
    string grad=GetGradFromID(myID);
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    bool first=true;
    for(auto news:post["Posts"])
    {
        string Status=news["Status"];
        if(Status!="ok")
            continue;
        string IDcreator=news["Id_User"];
        string Vis=news["Visibility"];
        if(Vis!="Public" && myID!=IDcreator && grad=="Normal User")
        {
            if(Vis=="Private")
            {
                continue;
            }
            else if(Vis=="Friends")
            {
                if(!isFriend(myID,IDcreator))
                    continue;
            }
            else if(Vis=="Friends of Friends")
            {
                if(!isFriendofFriends(myID,IDcreator))
                    continue;
            }
        }
        if(first)
        {
            OUTstr.clear();
            first=false;
        }
        std::ifstream users_profil("../users_profil_data.json");
        json profil=json::parse(users_profil);
        users_profil.close();
        string Nume=profil["Profil_Info"][IDcreator]["Nume"];
        string Prenume=profil["Profil_Info"][IDcreator]["Prenume"];
        std::ifstream users_login("../users_login_data.json");
        json login = json::parse(users_login);
        users_login.close();
        string Username=login["Login_Info"][IDcreator]["username"];
        OUTstr+="*Creator postare: ";
        OUTstr+=Prenume;
        OUTstr+=" ";
        OUTstr+=Nume;
        OUTstr+=" (";
        OUTstr+=Username;
        OUTstr+=")\n*Vizibilitatea postarii: ";
        OUTstr+=Vis;
        OUTstr+="\n*Mesajul postarii:\n\t";
        string MSGPost=news["Postare"];
        OUTstr+=MSGPost;
        OUTstr+="\n\n";
    }
    return OUTstr;
}

string serverProfil::VeziPostariUser(const int& fd, const string& User)
{
    string OUTstr="Acest utilizator nu are inca postari sau nu poti vedea niciuna dintre ele!\n";
    string myID=GetIdFromMap(fd);
    string grad=GetGradFromID(myID);
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    string perfectID;
    GetIdFromMapByUN(User,perfectID);
    bool first=true;
    if(perfectID=="Username-ul introdus este gresit\n")
        return perfectID;
    for(auto news:post["Posts"])
    {
        string Status=news["Status"];
        if(Status!="ok")
            continue;
        string IDcreator=news["Id_User"];
        if(IDcreator!=perfectID)
            continue;
        string Vis=news["Visibility"];
        if(Vis!="Public" && myID!=IDcreator && grad=="Normal User")
        {
            if(Vis=="Private")
            {
                continue;
            }
            else if(Vis=="Friends")
            {
                if(!isFriend(myID,IDcreator))
                    continue;
            }
            else if(Vis=="Friends of Friends")
            {
                if(!isFriendofFriends(myID,IDcreator))
                    continue;
            }
        }
        if(first)
        {
            OUTstr.clear();
            first=false;
        }
        std::ifstream users_profil("../users_profil_data.json");
        json profil=json::parse(users_profil);
        users_profil.close();
        string Nume=profil["Profil_Info"][IDcreator]["Nume"];
        string Prenume=profil["Profil_Info"][IDcreator]["Prenume"];
        std::ifstream users_login("../users_login_data.json");
        json login = json::parse(users_login);
        users_login.close();
        string Username=login["Login_Info"][IDcreator]["username"];
        OUTstr+="*Creator postare: ";
        OUTstr+=Prenume;
        OUTstr+=" ";
        OUTstr+=Nume;
        OUTstr+=" (";
        OUTstr+=Username;
        OUTstr+=")\n*Vizibilitatea postarii: ";
        OUTstr+=Vis;
        OUTstr+="\n*Mesajul postarii:\n\t";
        string MSGPost=news["Postare"];
        OUTstr+=MSGPost;
        OUTstr+="\n\n";
    }
    return OUTstr;
}

string serverProfil::VeziPostarileMele(const int& fd)
{
    string OUTstr="Nu ai facut inca nicio postare\n";
    string myID=GetIdFromMap(fd);
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    bool first=true;
    for(auto news:post["Posts"])
    {
        string Status=news["Status"];
        if(Status!="ok")
            continue;
        string IDcreator=news["Id_User"];
        if(IDcreator!=myID)
            continue;
        string Vis=news["Visibility"];
        if(first)
        {
            OUTstr.clear();
            first=false;
        }
        OUTstr+="*Vizibilitatea postarii: ";
        OUTstr+=Vis;
        OUTstr+="\n*Mesajul postarii:\n\t";
        string MSGPost=news["Postare"];
        OUTstr+=MSGPost;
        OUTstr+="\n\n";
    }
    return OUTstr;
}

string serverProfil::checkGrad(const int& fd) 
{
    string ID=GetIdFromMap(fd);
    string Grad=GetGradFromID(ID);
    return Grad;
}

string serverProfil::GetFullInfosAboutPosts()
{
    string OUTstr="Nu exista postari in sistem!\n";
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    bool first=true;
    for(auto news:post["Posts"])
    {
        string Status=news["Status"];
        if(Status!="ok")
            continue;
        string IDcreator=news["Id_User"];
        string Vis=news["Visibility"];
        string IDpost=news["Id_Post"];
        if(first)
        {
            OUTstr.clear();
            first=false;
        }
        std::ifstream users_profil("../users_profil_data.json");
        json profil=json::parse(users_profil);
        users_profil.close();
        string Nume=profil["Profil_Info"][IDcreator]["Nume"];
        string Prenume=profil["Profil_Info"][IDcreator]["Prenume"];
        std::ifstream users_login("../users_login_data.json");
        json login = json::parse(users_login);
        users_login.close();
        string Username=login["Login_Info"][IDcreator]["username"];
        OUTstr+="*ID postare: ";
        OUTstr+=IDpost;
        OUTstr+="\n*Creator postare: ";
        OUTstr+=Prenume;
        OUTstr+=" ";
        OUTstr+=Nume;
        OUTstr+=" (";
        OUTstr+=Username;
        OUTstr+=");  Vizibilitate:";
        OUTstr+=Vis;
        OUTstr+="\n*Mesajul postarii:\t";
        string MSGPost=news["Postare"];
        OUTstr+=MSGPost;
        OUTstr+="\n\n";
    }
    return OUTstr;
}

bool serverProfil::DeletePost(const string& ID)
{
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    for (auto ps:post["Posts"])
    {
        if(ps["Id_Post"]==ID)
        {
            post["Posts"][ID]["Status"]="deleted";
            std::ofstream posts_out("../posts_data.json");
            posts_out << post.dump(2);
            posts_out.close();
            return true;
        }
    }
    return false;
}

void serverProfil::Assign(const string &ID, string &id, string &visibility) const
{
    size_t found=ID.find('\n');
    id.assign(ID, 0, found);
    visibility.assign(ID, found+1, ID.size()-(found+1));
}

bool serverProfil::ModificaVizibilitate(const string& ID)
{
    string id;
    string visibility;
    Assign(ID, id, visibility);
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    for (auto ps:post["Posts"])
    {
        if(ps["Id_Post"]==id)
        {
            post["Posts"][id]["Visibility"]=visibility;
            std::ofstream posts_out("../posts_data.json");
            posts_out << post.dump(2);
            posts_out.close();
            return true;
        }
    }
    return false;
}

bool serverProfil::ModificaGrad(const string& IDandGrade)
{
    string id;
    string newgrade;
    Assign(IDandGrade,id,newgrade);
    std::ifstream users_profil("../users_profil_data.json");
    json profil=json::parse(users_profil);
    users_profil.close();
    for (auto pf:profil["Profil_Info"])
    {
        if(pf["id"]==id)
        {
            if(newgrade!="Admin" && newgrade!="Owner" && newgrade!="VIP")
                newgrade="Normal User";
            profil["Profil_Info"][id]["Grad"]=newgrade;
            std::ofstream users_profil_out("../users_profil_data.json");
            users_profil_out<<profil.dump(2);
            users_profil_out.close();
            return true;
        }
    }
    return false;
}

string serverProfil::GetUsernameFromID(const string& ID)
{
    string ret="fail";
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    for(auto lg:login["Login_Info"])
    {
        if(lg["id"]==ID)
        {
            ret=lg["username"];
            break;
        }
    }
    return ret;
}

string serverProfil::GetIDFromUsername(const string &Username)
{
    string ret="fail";
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    for(auto lg:login["Login_Info"])
    {
        if(lg["username"]==Username)
        {
            ret=lg["id"];
            break;
        }
    }
    return ret;
}

string serverProfil::GetIdFromMessage(const string &Message)
{
    string ret;
    int i=0;
    while(Message[i]!=':')
    {
        ret+=Message[i];
        i++;
    }
    return ret;
}

string serverProfil::GetActualConv(const int& fd, const string& username, size_t& counter)
{
    string Output;
    if(counter==1)
        Output="Local history:\n";
    std::ifstream conversations("../conversations.json");
    json conv = json::parse(conversations);
    conversations.close();
    string ID1=GetIdFromMap(fd);
    string ID2=GetIDFromUsername(username);
    for(auto &parc:conv["Conversations"])
    {
        if((parc["Id_1"]==ID1 && parc["Id_2"]==ID2) || (parc["Id_1"]==ID2 && parc["Id_2"]==ID1))
        {
            string idconv=parc["Id_conv"];
            vector<string> messages=conv["Conversations"][idconv]["List_Msj"];
            size_t ind=1;
            for(; ind<messages.size(); ind++)
            {
                if(ind>=counter)
                {
                    string curstr = messages[ind];
                    Output += curstr;
                    Output += "\n";
                    counter++;
                }
            }
            break;
        }
    }
    if (Output=="Local history:\n")
    {
        if(!isFriend(ID1,ID2))
        {
            Output="Nu esti prieten cu acest utilizator\n";
            return Output;
        }
        else {
            std::ifstream conversations2("../conversations.json");
            json conv2 = json::parse(conversations2);
            conversations2.close();
            string Start = conv2["Id_Start"];
            int startInt = atoi(Start.data());
            startInt++;
            Start = to_string(startInt);
            conv2["Id_Start"] = Start;
            conv2["Conversations"][Start]["Id_1"] = ID1;
            conv2["Conversations"][Start]["Id_2"] = ID2;
            conv2["Conversations"][Start]["Id_conv"] = Start;
            conv2["Conversations"][Start]["Nr_mess"] = "0";
            vector<string> vctgol;
            vctgol.emplace_back("#");
            conv2["Conversations"][Start]["List_Msj"] = vctgol;
            std::ofstream conversations_out("../conversations.json");
            conversations_out << conv2.dump(2);
            conversations_out.close();
        }
    }
    else if(Output.empty())
    {
        Output="Nu sunt mesaje noi\n";
    }
    return Output;
}

string serverProfil::GetUsername(const int& fd)
{
    string ID=GetIdFromMap(fd);
    std::ifstream users_login("../users_login_data.json");
    json login = json::parse(users_login);
    users_login.close();
    for(auto lg:login["Login_Info"])
    {
        if(lg["id"]==ID)
            return (lg["username"]);
    }
    return "fail...";
}

bool serverProfil::UpdateConversation(const int& fd, const string& mesaj, const string& usernameout)
{
    string ID=GetIdFromMap(fd);
    string IDout=GetIDFromUsername(usernameout);
    string Username=GetUsernameFromID(ID);
    string newmesaj=Username;
    newmesaj+=": ";
    newmesaj+=mesaj;
    std::ifstream conversations("../conversations.json");
    json conv = json::parse(conversations);
    conversations.close();
    for(auto &cv:conv["Conversations"])
    {
        if((cv["Id_1"]==ID && cv["Id_2"]==IDout) || (cv["Id_1"]==IDout && cv["Id_2"]==ID))
        {
            string idconv=cv["Id_conv"];
            string nr=cv["Nr_mess"];
            int nrint=atoi(nr.data());
            nrint++;
            string nrnou=to_string(nrint);
            vector<string> vctforupdate=cv["List_Msj"];
            vctforupdate.emplace_back(newmesaj);
            conv["Conversations"][idconv]["Nr_mess"]=nrnou;
            conv["Conversations"][idconv]["List_Msj"]=vctforupdate;
            std::ofstream conversations_out("../conversations.json");
            conversations_out<<conv.dump(2);
            conversations_out.close();
            break;
        }
    }
    return true;
}

string serverProfil::GetConvList(const int& fd)
{
    string retSTR="Persoanele cu care ai conversat pana acum sunt:\n";
    std::ifstream conversations("../conversations.json");
    json conv = json::parse(conversations);
    conversations.close();
    string ID=GetIdFromMap(fd);
    string IDpers;
    size_t counter=0;
    for(auto parc:conv["Conversations"])
    {
        IDpers.clear();
        if(parc["Id_1"]==ID)
        {
            IDpers=parc["Id_2"];
        }
        else if(parc["Id_2"]==ID)
        {
            IDpers=parc["Id_1"];
        }
        if(!IDpers.empty())
        {
            counter++;
            retSTR+=to_string(counter);
            retSTR+=". ";
            string username=GetUsernameFromID(IDpers);
            retSTR+=username;
            retSTR+="\n";
        }

    }
    return retSTR;
}

string serverProfil::GetConvListGroup(const int& fd)
{
    string retSTR="Grupurile in care ai conversatii pana acum sunt:\n";
    std::ifstream conversations("../conversations.json");
    json conv = json::parse(conversations);
    conversations.close();
    string ID=GetIdFromMap(fd);
    size_t counter=0;
    for(auto parc:conv["Conv_Group"])
    {
        vector<string> temp=parc["Ids"];
        for(auto &blabla:temp)
        {
            if(blabla==ID)
            {
                counter++;
                retSTR+=to_string(counter);
                retSTR+=") ";
                for(auto &m:temp) {
                    string username = GetUsernameFromID(m);
                    retSTR += username;
                    retSTR += ", ";
                }
                retSTR+="\n";
                break;
            }
        }
    }
    return retSTR;
}

bool serverProfil::CheckAllIdsForGroup(const vector<string>& search, const vector<string>& where)
{
    if(search.size()!=where.size())
        return false;
    for(auto one:search)
    {
        bool localcheck=false;
        for(auto two:where)
        {
            if(one==two)
            {
                localcheck=true;
                break;
            }
        }
        if(localcheck==false)
            return false;
    }
    return true;
}

string serverProfil::GetActualConvGroup(const int& fd, const vector<string>& ids, size_t& counter)
{
    string Output;
    if(counter==1)
        Output="Local history:\n";
    std::ifstream conversations("../conversations.json");
    json conv = json::parse(conversations);
    conversations.close();
    string ID1=GetIdFromMap(fd);
    vector <string> ID2;
    ID2.emplace_back(ID1);
    for(auto &username:ids)
    {
        //cout<<username<<'*';
        ID2.emplace_back(username);
    }
    for(auto &parc:conv["Conv_Group"])
    {
        vector <string> temp=parc["Ids"];
        if(CheckAllIdsForGroup(ID2,temp))
        {
            string idconv=parc["Id_conv"];
            vector<string> messages=conv["Conv_Group"][idconv]["List_Msj"];
            size_t ind=1;
            for(; ind<messages.size(); ind++)
            {
                if(ind>=counter)
                {
                    string curstr = messages[ind];
                    Output += curstr;
                    Output += "\n";
                    counter++;
                }
            }
            break;
        }
    }
    if (Output=="Local history:\n")
    {
        for(auto idfr:ids)
        {
            if(!isFriend(ID1,idfr) && ID1!=idfr)
            {
                Output="Nu esti prieten cu unul sau mai multi dintre acesti clienti\n";
                break;
            }
        }
        if(Output!="Nu esti prieten cu unul sau mai multi dintre acesti clienti\n")
        {
            std::ifstream conversations2("../conversations.json");
            json conv2 = json::parse(conversations2);
            conversations2.close();
            string Start=conv2["Id_Start_Group"];
            int startInt=atoi(Start.data());
            startInt++;
            Start=to_string(startInt);
            conv2["Id_Start_Group"]=Start;
            conv2["Conv_Group"][Start]["Ids"]=ID2;
            conv2["Conv_Group"][Start]["Id_conv"]=Start;
            conv2["Conv_Group"][Start]["Nr_mess"]="0";
            conv2["Conv_Group"][Start]["Nr_users"]=to_string(ID2.size());
            vector<string> vctgol;
            vctgol.emplace_back("#");
            conv2["Conv_Group"][Start]["List_Msj"]=vctgol;
            std::ofstream conversations_out("../conversations.json");
            conversations_out<<conv2.dump(2);
            conversations_out.close();
        }

    }
    else if(Output.empty())
    {
        Output="Nu sunt mesaje noi\n";
    }
    return Output;
}

bool serverProfil::UpdateConversationGroup(const int& fd, const string& mesaj, const vector<string>& ids)
{
    string ID=GetIdFromMap(fd);
    vector <string> IDout;
    IDout.emplace_back(ID);
    for(auto &username:ids)
    {
        //cout<<'*'<<username<<'*';
        IDout.emplace_back(username);
    }
    string Username=GetUsernameFromID(ID);
    string newmesaj=Username;
    newmesaj+=": ";
    newmesaj+=mesaj;
    std::ifstream conversations("../conversations.json");
    json conv = json::parse(conversations);
    conversations.close();
    for(auto &cv:conv["Conv_Group"])
    {
        vector <string> temp=cv["Ids"];
        if(CheckAllIdsForGroup(IDout,temp))
        {
            string idconv=cv["Id_conv"];
            string nr=cv["Nr_mess"];
            int nrint=atoi(nr.data());
            nrint++;
            string nrnou=to_string(nrint);
            vector<string> vctforupdate=cv["List_Msj"];
            vctforupdate.emplace_back(newmesaj);
            conv["Conv_Group"][idconv]["Nr_mess"]=nrnou;
            conv["Conv_Group"][idconv]["List_Msj"]=vctforupdate;
            std::ofstream conversations_out("../conversations.json");
            conversations_out<<conv.dump(2);
            conversations_out.close();
            break;
        }
    }
    return true;
}

string serverProfil::GetNoLoginPosts()
{
    string OUTstr="Nu exista postari in sistem sau nu ai acces sa vezi vreuna din ele!\n";
    std::ifstream posts("../posts_data.json");
    json post=json::parse(posts);
    posts.close();
    bool first=true;
    for(auto news:post["Posts"])
    {
        string Status=news["Status"];
        if(Status!="ok")
            continue;
        string IDcreator=news["Id_User"];
        string Vis=news["Visibility"];
        if(Vis!="Public")
            continue;
        if(first)
        {
            OUTstr.clear();
            first=false;
        }
        std::ifstream users_profil("../users_profil_data.json");
        json profil=json::parse(users_profil);
        users_profil.close();
        string Nume=profil["Profil_Info"][IDcreator]["Nume"];
        string Prenume=profil["Profil_Info"][IDcreator]["Prenume"];
        OUTstr+="*Creator postare: ";
        OUTstr+=Prenume;
        OUTstr+=" ";
        OUTstr+=Nume;
        OUTstr+="\n*Vizibilitatea postarii: ";
        OUTstr+=Vis;
        OUTstr+="\n*Mesajul postarii:\n\t";
        string MSGPost=news["Postare"];
        OUTstr+=MSGPost;
        OUTstr+="\n\n";
    }
    return OUTstr;
}

string serverProfil::GetNoLoginProfiles()
{
    string gradUser;
    string RETstr="Acestea sunt profilurile pe care le poti vedea:\n\n";
    std::ifstream users_profil2("../users_profil_data.json");
    json profil2=json::parse(users_profil2);
    for(auto othersdata:profil2["Profil_Info"])
    {
        string grad=othersdata["Grad"];
        string nume=othersdata["Nume"];
        string prenume=othersdata["Prenume"];
        string posts=othersdata["Posts"];
        string vizibilitate=othersdata["Vizibilitate"];
        string iidd=othersdata["id"];
        if (vizibilitate != "Public")
            continue;
        else
        {
            RETstr += "Nume: ";
            RETstr += nume;
            RETstr += "\nPrenume: ";
            RETstr += prenume;
            RETstr += "\nGrad: ";
            RETstr += grad;
            RETstr += "\nVizibilitate Profil: ";
            RETstr += vizibilitate;
            RETstr += "\nPostari: ";
            RETstr += posts;
            RETstr += "\n\n";
        }
    }
    users_profil2.close();
    return RETstr;
}