#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod*succ;
};

bool creare(nod*&prim, nod*&ultim)
{
    int x, i, n;
    nod *q;
    cin>>n;
    if (n<1)
        return false;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        q=new nod;
        q->info=x;
        q->succ='\0';
        if(prim=='\0')
            prim=q;
        else
            ultim->succ=q;
        ultim=q;
    }
    return true;
}

bool afisare(nod*prim)
{
    nod*p;
    if(prim=='\0')
        return false;
    for(p=prim; p!='\0'; p=p->succ)
        cout<<p->info<<" ";
    return true;
}

 bool nrprim(int x)
 {
     if(x<2)
        return false;
     if(x==2)
        return true;
     if(x%2==0)
        return false;
     for(int i=3; i*i<=x; i+=2)
        if(x%i==0)
            return false;
     return true;
 }

void eliminaprime(nod*&prim)
{
    if(prim=='\0')
        return;
    nod*q=prim;
    while(q->succ!='\0')
        if(nrprim(q->succ->info))
        {
            nod*copie=q;
            q->succ=q->succ->succ;
            delete(copie->succ);
        }
        else
            q=q->succ;

    if(nrprim(q->info))
    {
        nod*copie=q;
        q=q->succ;
        delete(copie);
    }
    if(nrprim(prim->info))
    {
        nod*copie=prim;
        prim=prim->succ;
        delete copie;
        return;
    }
}
int main()
{
    nod *L='\0';
    nod *last='\0';
    creare(L, last);
    cout<<"Lista simplu inantuita este: \n";
    afisare(L);
    cout<<'\n';
    eliminaprime(L);
    cout<<"Lista dupa eliminarea numerelor prime este: \n";
    afisare(L);
    return 0;
}
