#include <iostream>
#define MAX_ELEM 100
using namespace std;
struct matrix
{
    unsigned int nrlinii;
    int a[MAX_ELEM][3];
};
int prim(int x)
{
    if(x<=1)return 0;
    if(x==2) return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0)
            return 0;
    return 1;
}
matrix primeTwins(unsigned int count, unsigned int lowerBound, matrix c)
{
    c.nrlinii=0;int copie=0;
    for(unsigned int i=lowerBound;copie<count;i+=2)
    if(prim(i)==1&&prim(i+2)==1)
    {
        c.a[copie][1]=i;
        c.a[copie++][2]=i+2;
    }
    c.nrlinii=copie;
    return c;
}

void afisare(matrix b,char nume)
{
    cout<<"Se afiseaza matricea cu numele "<<nume<<endl;
    cout<<"Numarul de perechi gasite este :"<<b.nrlinii<<endl;
    for(unsigned int contor=0; contor<b.nrlinii; contor++)
        cout<<"Perechea "<<contor+1<<" este "<<b.a[contor][1]<<", "<<b.a[contor][2]<<endl;
}
int main()
{
    matrix a;
    unsigned int count,lowerbound;
    cout<<"Numarul de perechi cerute: ";
    cin>>count;
    cout<<"Limita minima: ";cin>>lowerbound;
    if(lowerbound%2==0)
        lowerbound++;
    a=primeTwins(count,lowerbound,a);
    afisare(a,'A');
    return 0;
}
