#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
//nume, prenume, sex (M/F), varsta, punctaj
struct concurent
{
    char nume[20], prenume[20];
    int varsta, punctaj;
    char sex[10];
};
int main()
{
    concurent cc[100], aux;
    int nrconc, i, j;
    cin>>nrconc;
    for(i=1; i<=nrconc; i++)
    {
        cin.get();
        cin.get(cc[i].nume, 19);
        cin.get();
        cin.get(cc[i].prenume, 19);
        cin.get();
        cin.get(cc[i].sex, 2);
        cin.get();
        cin>>cc[i].varsta>>cc[i].punctaj;
    }
    for(i=1; i<nrconc; i++)
        if(cc[i].varsta>=16 && cc[i].varsta<=20 && !strcmp(cc[i].sex,"M"))
            for(j=i+1; j<=nrconc; j++)
                if(cc[j].varsta>=16 && cc[j].varsta<=20)
                    if(cc[i].punctaj<cc[j].punctaj && !strcmp(cc[j].sex,"M"))
                    {
                        aux=cc[i];
                        cc[i]=cc[j];
                        cc[j]=aux;
                    }
    for(i=1; i<=nrconc; i++)
        cout<<cc[i].nume<<" "<<cc[i].prenume<<" "<<cc[i].sex<<" "<<cc[i].varsta<<" "<<cc[i].punctaj<<endl;
    return 0;
}
