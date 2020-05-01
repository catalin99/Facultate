#include <iostream>
using namespace std;

struct nod
{
  int info;
  nod *succ;
};
#define urm succ
void creare(nod *&prim)
{
    int n, i, x;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        nod *q=new nod;
        q->info=x;
        q->succ=NULL;
        nod *p=prim;
        if(prim==NULL)
            prim=q;
        else
        {
            while(p->succ!=NULL)
                p=p->succ;
            p->succ=q;
        }
        /* //Adaugare la inceputul listei.
        q->info=x;
        q->succ=prim;
        prim=q;
        */
    }
    return;
}

void afisare (nod *prim)
{
    nod *q=prim;
    while(q!=NULL)
    {
        cout<<q->info<<' ';
        q=q->succ;
    }
    return;
}

int main()
{
    nod *prim;
    prim=NULL;
    creare(prim);
    afisare(prim);
    return 0;
}
