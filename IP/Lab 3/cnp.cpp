#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

struct cnp
{
    char sex[10];
    int aa, ll, zz;
    char jj[15];
    int nnn[5], control;
};
#define lli long long int
int main()
{
    lli numar;
    int vnumar[15], i, exista=0, r;
    cnp c;
    cin>>numar;
    for(i=13; i>=1; i--)
    {
        vnumar[i]=numar%10;
        numar/=10;
    }

    if(vnumar[1]==1 || vnumar[1]==3 || vnumar[1]==5)
        strcpy(c.sex,"Masculin");
    else if(vnumar[1]==2 || vnumar[1]==4 || vnumar[1]==6)
        strcpy(c.sex,"Feminin");
    else if(vnumar[1]==0 || vnumar[1]==9 || vnumar[1]==7 || vnumar[1]==8)
    {
        exista=1;
        cout<<"eroare sex"<<endl;
    }
    if(vnumar[1]==1 || vnumar[1]==2)
        r=1900;
    else if(vnumar[1]==3 || vnumar[1]==4)
        r=1800;
    else if(vnumar[1]==5 || vnumar[1]==6)
        r=2000;

    c.aa=r+(10*vnumar[2]+vnumar[3]);
    c.ll=10*vnumar[4]+vnumar[5];
    c.zz=10*vnumar[6]+vnumar[7];

    if(c.ll>12 || c.ll<1)
    {
        exista=2;
        cout<<"eroare luna"<<endl;
    }
    if(c.zz>31 || c.zz<1)
    {
        exista=3;
        cout<<"eroare zi"<<endl;
    }

    r=vnumar[8]*10+vnumar[9];
    if(r<1 || r>52)
    {
        exista=4;
        cout<<"eroare cod judet"<<endl;
        strcpy(c.jj,"cod judet invalid");
    }
    else
        strcpy(c.jj,"Judetul ...");

    c.nnn[1]=vnumar[10];
    c.nnn[2]=vnumar[11];
    c.nnn[3]=vnumar[12];

    c.control=vnumar[13];
    lli vf, verif;
    //279146358279
    vf=9*vnumar[12]+7*vnumar[11]+2*vnumar[10]+8*vnumar[9]+5*vnumar[8]+3*vnumar[7]+6*vnumar[6]+4*vnumar[5]+1*vnumar[4]+9*vnumar[3]+7*vnumar[2]+2*vnumar[1];
    //cout<<"suma "<<vf<<endl;
    verif=vf%11;
    //cout<<"rest init "<<verif<<endl;
    if (verif==10)
        verif=1;
    //cout<<"rest final "<<verif<<endl;
    if(verif!=c.control)
    {
        exista=5;
        cout<<"eroare cifra control"<<endl;
    }

    cout<<"sex "<<c.sex<<endl;
    cout<<"an "<<c.aa<<endl;
    cout<<"luna "<<c.ll<<endl;
    cout<<"zi "<<c.zz<<endl;
    cout<<"judet "<<c.jj<<endl;
    cout<<"numar evidenta ";
    for(int p=1; p<=3; p++)
        cout<<c.nnn[p];
    cout<<endl;
    cout<<"control "<<c.control<<endl;

    if(exista)
        cout<<"Acest CNP nu exista";
    else
        cout<<"CNP-ul exista!";
    return 0;
}
