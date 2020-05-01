#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct situatie
{
    char numeN[20], numeA[20], next[10];
    char tabla[10][10];
} var;

int main()
{
    int i, j;
    cin.get(var.numeN, 19);
    cin.get();
    cin.get(var.numeA, 19);
    cin.get();
    cin.get(var.next, 9);
    cin.get();
    for(i=0; i<=7; i++)
        for(j=0; j<=7; j++)
        {
            cin>>var.tabla[i][j];
        }
    cout<<endl;
    cout<<"Date initiale:"<<endl;
    cout<<"Nume jucator piese negre: "<<var.numeN<<endl;
    cout<<"Nume jucator piese albe: "<<var.numeA<<endl;
    cout<<"Jucatorul care urmeaza este: "<<var.next<<endl;
    cout<<endl;
    cout<<"asezare curenta: "<<endl;
    for(i=0; i<=7; i++)
    {
        for(j=0; j<=7; j++)
            cout<<var.tabla[i][j]<<" ";
        cout<<endl;
    }
    for(i=2; i<=5; i++)
        for(j=0; j<=7; j++)
            var.tabla[i][j]='0';
    var.tabla[0][0]=var.tabla[0][7]='T';
    var.tabla[0][1]=var.tabla[0][6]='C';
    var.tabla[0][2]=var.tabla[0][5]='N';
    var.tabla[0][3]='R';
    var.tabla[0][4]='S';
    var.tabla[7][0]=var.tabla[7][7]='t';
    var.tabla[7][1]=var.tabla[7][6]='c';
    var.tabla[7][2]=var.tabla[7][5]='n';
    var.tabla[7][3]='r';
    var.tabla[7][4]='s';
    for(i=0; i<=7; i++)
    {
        var.tabla[1][i]='P';
        var.tabla[6][i]='p';
    }
    cout<<endl;
    cout<<"aranjarea initiala a pieselor: "<<endl;
    for(i=0; i<=7; i++)
    {
        for(j=0; j<=7; j++)
            cout<<var.tabla[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
