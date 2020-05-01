#include <iostream>
#include <cmath>
using namespace std;
#define MAX_ELEMENTE 100
bool isPalindrom(unsigned long long number)//problema 4
{
    unsigned long long copie=number;
    unsigned long long oglindit=0;
    while(number>0)
    {
        oglindit=oglindit*10+number%10;
        number=number/10;
    }
    return (copie==oglindit);
}

bool  verif_perfect(unsigned int number)//problema 7
{
    unsigned int suma=0;
    for(unsigned int i=1;i<=number/2;i++)
        if(number%i==0)suma=suma+i;
    return(suma==number);
}
unsigned long perfectNumbers(unsigned int number)
{
    int numere_perfecte=0,suma=0;
    for(int i=number;i>=6&&numere_perfecte<2;i--)
    if(verif_perfect(i)==1){suma=suma+i;numere_perfecte++;}
    return suma;

}

unsigned char sumBinaryFigure(unsigned long long number)//problema 6
{
    unsigned char s='0';
    while(number>0)
    {
        s=s+number%2;
        number=number/2;
    }
    return s;
}

struct vector//problema 9
            {
                int nr_elem;
                int elem[MAX_ELEMENTE];
            };
void citire(vector &a,char nume)
{
    cout<<"Citim vectorul "<<nume<<endl;
    cout<<"Numarul de elemente pentru vectorul "<<nume<<" este:";
    cin>>a.nr_elem;
    for(int i=0;i<=a.nr_elem-1;i++)
    {
        cout<<nume<<"["<<i<<"]=";
        cin>>a.elem[i];
    }
}
int  suma_elementelor(vector a)
{
    int s=0;
    for(int i=0;i<a.nr_elem;i++)
    {
        if(a.elem[i]<0){s=s+a.elem[i];cout<<s<<endl;}
    }
    return s;
}




struct matrix
{
    unsigned int nrlinii;
    int a[MAX_ELEMENTE][3];
};
int prim(int x)
{
    if(x<=1)return 0;
    if(x==2) return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0) return 0;
    return 1;
}
matrix primeTwins(unsigned int count, unsigned int lowerBound,matrix c)
{
    c.nrlinii=0;int copie=0;
    for(unsigned int i=lowerBound;copie<count;i+=2)
    if(prim(i)==1&&prim(i+2)==1){c.a[copie][1]=i;
                                 c.a[copie++][2]=i+2;}
    c.nrlinii=copie;
    return c;
}

void afisare(matrix b,char nume)
    {cout<<"Se afiseaza matricea cu numele "<<nume<<endl;
    cout<<"Numarul de perechi gasite este :"<<b.nrlinii<<endl;
    for(unsigned int contor=0;contor<b.nrlinii;++contor)
        cout<<"Perechea "<<contor+1<<" este "<<b.a[contor][1]<<", "<<b.a[contor][2]<<endl;
}
int main()
{
   // matrix a;
   // unsigned int count,lowerbound;
   // cout<<"Se citeste numarul de perechi cerute: ";
   // cin>>count;
   // cout<<"Limita maxima acceptata este :";cin>>lowerbound;
   // a=primeTwins(count,lowerbound,a);
   // cout<<a.nrlinii;
    //afisare(a,'A');
    unsigned char s=sumBinaryFigure(562223237);cout<<s;
    return 0;
}
