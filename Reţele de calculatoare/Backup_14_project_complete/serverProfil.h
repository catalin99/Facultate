//
// Created by catalin on 15.12.2018.
//

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#ifndef PROJRC_SERVERPROFIL_H
#define PROJRC_SERVERPROFIL_H
using namespace std;
using json = nlohmann::json;


class serverProfil {
private:
    map<int, string> ConnectedUsers;
    bool NoLogin;
    string GetIdFromMap(int fd);
    string GetGradFromID(string ID);
    bool isFriend(const string& myid,const string& idfriend);
    bool isFriendofFriends(const string& myid,const string& idfriend);
    bool GetIdFromMapByNP(const string& nume, const string& prenume, string& ID);
    bool GetIdFromMapByUN(const string& username, string &ID);
    void Assign(const string &ID, string &id, string &visibility) const;
    bool CheckAllIdsForGroup(const vector<string>& search, const vector<string>& where);
public:
    void PrintAllProfilData();
    bool DelogheazaUser(int fd);
    void FillMap(int fd, string username);
    void PrintMap();
    string checkUser(string username);
    void NoLogConfirm();
    bool NoLog(int fd);
    string checkFP(string username);
    short Register(string username, string password, string sq, string sa);
    string MyProfilInfo(int fd);
    void UpdateLastName(string Var, int fd);
    void UpdateFirstName(string Var, int fd);
    void UpdateVisibility(string Var, int fd);
    string VeziProfile(int fd);
    string VeziUnProfil(int fd, string PeCare);
    bool CereriPrimite(int fd, string& Return);
    bool CereriTrimise(int fd, string& Return);
    string SendReqbyUsername(int fd, string username);
    string SendReqbyNP(int fd, string nume, string prenume);
    string AccReqbyUsername(int fd, string username);
    string AccReqbyNP(int fd, string nume, string prenume);
    bool Make_Post(const int& fd, const string& Vis, const string& Post);
    string VeziToatePostarile(const int& fd);
    string VeziPostariUser(const int& fd, const string& User);
    string VeziPostarileMele(const int& fd);
    string checkGrad(const int& fd);
    string GetFullInfosAboutPosts();
    bool DeletePost(const string& ID);
    bool ModificaVizibilitate(const string& ID);
    bool ModificaGrad(const string& IDandGrade);
    string GetUsernameFromID(const string& ID);
    string GetIDFromUsername(const string& Username);
    string GetIdFromMessage(const string &Message);
    string GetActualConv(const int& fd, const string& username, size_t& counter);
    string GetUsername(const int& fd);
    bool UpdateConversation(const int& fd, const string& mesaj, const string& usernameout);
    string GetConvList(const int& fd);
    string GetActualConvGroup(const int& fd, const vector<string>& ids, size_t& counter);
    bool UpdateConversationGroup(const int& fd, const string& mesaj, const vector<string>& ids);
    string GetConvListGroup(const int& fd);
    string GetNoLoginPosts();
    string GetNoLoginProfiles();
};


#endif //PROJRC_SERVERPROFIL_H
