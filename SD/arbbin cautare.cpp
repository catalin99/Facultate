#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *st;
    nod *dr;
};

void inserare(nod *&arb, int val)
{
    if(!arb)
    {
        arb=new nod;
        arb->info=val;
        arb->st='\0';
        arb->dr='\0';
    }
    else if(val<arb->info)
        inserare(arb->st, val);
    else
        inserare(arb->dr, val);
}

void InOrdine(nod *arb)
{
    if(arb)
    {
        InOrdine(arb->st);
        cout<<arb->info<<' ';
        InOrdine(arb->dr);
    }
}

void PreOrdine(nod *arb)
{
    if(arb)
    {
        cout<<arb->info<<' ';
        PreOrdine(arb->st);
        PreOrdine(arb->dr);
    }
}

void PostOrdine(nod *arb)
{
    if(arb)
    {
        PostOrdine(arb->st);
        PostOrdine(arb->dr);
        cout<<arb->info<<' ';
    }
}

int main()
{
    int n, i, x;
    nod *arb=NULL;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        inserare(arb, x);
    }
    InOrdine(arb);
    cout<<'\n';
    PreOrdine(arb);
    cout<<'\n';
    PostOrdine(arb);
    return 0;
}
