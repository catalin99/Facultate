#include <iostream>
using namespace std;

struct nod
{
    int elt; //element
    nod* succ; //trimitere catre urmatorul element
};
//pune 10 dupa 3
nod *prim;
nod *ultim;
nod *p, *q;

p=prim;
while(p->elt!=3)
{
    p=p->succ;
    q=new nod;
    q->elt=10;
    q->succ=p->succ;
    p->succ=q;
}
