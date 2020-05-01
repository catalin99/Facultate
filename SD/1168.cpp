#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

void adaugare(nod *&p, int x)
{
    nod *prim=p;
    nod *q=new nod;
    q->info=x;
    q->urm=NULL;
    if(p==NULL)
        p=q;
    else
    {
        while(prim->urm!=NULL)
            prim=prim->urm;
        prim->urm=q;
    }
}
