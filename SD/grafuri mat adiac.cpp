#include <iostream>
using namespace std;

struct matriceadiacenta
{
    int a[100][100];
    int nrmuchii, nrvarfuri;
};
void creare_matadiac(matriceadiacenta &MA)
{
    int x, y;
    cout<<"Introduceti numarul de varfuri ";
    cin>>MA.nrvarfuri;
    cout<<"Introduceti numarul de muchii ";
    cin>>MA.nrmuchii;
    for(int i=1; i<=MA.nrvarfuri; i++)
        for(int j=1; j<=MA.nrvarfuri-i+1; j++)
            MA.a[i][j]=MA.a[j][i]=0;
    cout<<"Introduceti muchiile! \n";
    for(int i=1; i<=MA.nrmuchii; i++)
    {
        cin>>x>>y;
        if(x>MA.nrvarfuri || y>MA.nrvarfuri || x<1 || y<1)
        {
            cout<<"Date introduse gresit, reintroduceti muchia nr "<<i<<'\n';
            cin>>x>>y;
        }
        else if(x==y)
        {
            cout<<"Nu se poate crea muchie de la un varf la el insusi, reintroduceti muchia nr "<<i<<'\n';
            cin>>x>>y;
        }
        MA.a[x][y]=MA.a[y][x]=1;
    }
    return;
}

void insereaza_varf(matriceadiacenta &MA)
{

}
void afisare_matriceadiac(matriceadiacenta &MA)
{
    cout<<"Se afiseaza matricea de adiacenta \n";
    for(int i=1; i<=MA.nrvarfuri; i++)
    {
        for(int j=1; j<=MA.nrvarfuri; j++)
            cout<<MA.a[i][j]<<' ';
        cout<<'\n';
    }

    return;
}

int main()
{
    matriceadiacenta MA;
    creare_matadiac(MA);
    afisare_matriceadiac(MA);
    return 0;
}
