#include <iostream>
#include <algorithm>
using namespace std;
//numar de 10 cifre distincte. Sa se determine succesorul lui pastrand proprietatea
//Exemplu: 2089731654
//Afisare: 2089734156
#define ll long long


int main()
{
    ll n;
    int v[11], aux, i, j, k, minim, poz, confirm=0;
    cin>>n;
    for(i=10; i>=1; i--)
    {
        v[i]=n%10;
        n/=10;
    }
    for (i=9; i>=1, !confirm; i--)
    {
        for(j=i+1; j<=10; j++)
            if(v[i]<v[j])
            {
                minim=10;
                for(k=i+1; k<=10; k++)
                    if(v[k]<minim && v[k]>v[i])
                    {
                        minim=v[k];
                        poz=k;
                    }
                aux=v[i];
                v[i]=v[poz];
                v[poz]=aux;
                confirm=1;
                poz=i;
                break;
            }
    }
    for(i=poz+1; i<10; i++)
        for(j=i+1; j<=10; j++)
            if(v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    for(i=1; i<=10; i++)
        cout<<v[i];
    return 0;
}
