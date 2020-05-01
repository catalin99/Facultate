#include <iostream>
using namespace std;
typedef unsigned long ul;
#define tip int

struct nod
{
    tip elt;
    nod *succ;
};

void citire(nod *&L, ul &nrElemente, &Suma)
{
    tip x;
    ul i;
    nod *p;
    cout<<"dati numarul de elemente ";
    cin>>nrElemente;
    L='\0';
    for(i=0; i<nrElemente; i++)
    {
        cout<<"Dati elementul numarul "<<i+1<<" ";
        cin>>x;
        p=new nod;
        p->elt=x;
        p->succ=L;
        L=p;
    }
}

void afisare(nod *L)
{
    nod *p;
    p=L;
    while(p!='\0')
    {
        cout<<p->elt<<" ";
        p=p->succ;
    }
}


int main()
{
    ul n, Suma=0;
    nod *L;
    citire(L, n);
    afisare(L);
    return 0;
}
