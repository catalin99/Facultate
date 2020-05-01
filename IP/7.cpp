#include <iostream>
#include <fstream>
using namespace std;
ifstream in("prob.in");
typedef struct nod
{
    int info;
    nod *urm;
}NOD;

void creare(NOD *&prim, NOD *&ultim)
{
    int x,i,n;
    NOD *q;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>x;
        q=new NOD;
        q->info=x;
        q->urm=NULL;
        if(prim==NULL)
            prim=q;
        else ultim->urm=q;
        ultim=q;
    }
}

void stergere(NOD *&prim, bool &ok)
{
    NOD *q;
    q=prim;
    while(q->urm!=NULL)
    {
        if(q->urm->info%2==0)
        {
            NOD *p;
            p=q->urm;
            q->urm=q->urm->urm;
            delete p;
            ok=true;
        }
        else q=q->urm;
    }
    if(prim->info%2==0)
    {
        ok=true;
        NOD *t;
        t=prim;
        prim=prim->urm;
        delete t;
    }
}

void afisare(NOD *prim)
{
    NOD *q;
    for(q=prim;q!=NULL;q=q->urm)
        cout<<q->info<<' ';
    cout<<endl;
}

void Rezolvare(NOD *prim)
{
    cout<<"Lista initiala: ";
    afisare(prim);
    if(prim==NULL)
            cout<<"Lista este vida!";
    else
    {
        bool ok=false;
        stergere(prim,ok);
        if(ok==false)
        {
            cout<<"Lista nu contine elemente pare, deci va fi formata tot din elementele: ";
            afisare(prim);
        }
        else
        {
            if(prim==NULL)
                cout<<"Lista modificata este vida!";
            else
            {
                cout<<"Lista modificata este formata din elementele: ";
                afisare(prim);
            }
        }
    }
}

int main()
{
    NOD *prim, *ultim;
    prim=ultim=NULL;
    creare(prim,ultim);
    Rezolvare(prim);
    return 0;
}
