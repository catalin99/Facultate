#include <iostream>
#include <fstream>

using namespace std;
ifstream in("prob.in");
typedef struct nod
{
    long long int info;
    nod *urm;
}NOD;

void creare(NOD *&prim, NOD *&ultim)
{
    long long int x,i,n;
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

long long int factorial(long long int x)
{
    long long int p=1;
    for(long long int i=2;i<=x;i++)
        p=p*i;
    return 2*p;
}

void inserare(NOD *&prim, bool &ok)
{
    NOD *q;
    for(q=prim;q->urm!=NULL;q=q->urm)
        if(q->urm->info%2==0)
        {
            NOD *p;
            p=new NOD;
            p->info=factorial(q->urm->info);
            p->urm=q->urm;
            q->urm=p;
            ok=true;
            q=q->urm;
        }
    if(prim->info%2==0)
    {
        NOD *t;
        t=new NOD;
        t->info=factorial(prim->info);
        t->urm=prim;
        prim=t;
    }
}

void afisare(NOD *prim)
{
    NOD *q;
    for(q=prim;q!=NULL;q=q->urm)
        cout<<q->info<<' ';
    cout<<endl;
}

int main()
{
    NOD *prim, *ultim;
    prim=ultim=NULL;
    creare(prim,ultim);
    cout<<"Lista initiala: ";
    afisare(prim);
    if(prim==NULL)
            cout<<"Lista este vida!";
    else
    {
        bool ok=false;
        inserare(prim,ok);
        if(ok==false)
        {
            cout<<"Lista nu contine elemente pare, deci va fi formata tot din elementele: ";
            afisare(prim);
        }
        else
        {
            cout<<"Lista modificata este formata din elementele: ";
            afisare(prim);
        }
    }
    return 0;
}
