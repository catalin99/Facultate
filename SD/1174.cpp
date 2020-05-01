#include <iostream>
using namespace std;
struct nod
{
    int info;
    nod *urm;
};

int numarare(nod * p)
{
    int nr=0;
    nod *q;
    while(p->urm!=NULL)
    {
        q=p->urm;
        while(q!=NULL)
        {
            int a, b;
            a=p->info;
            b=q->info;
            while(a!=b)
                if(a>b)
                    a=a-b;
                else
                    b=b-a;
            if(a==1)
                nr++;
            q=q->urm;
        }
        p=p->urm;
    }
    return nr;
}

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

void afisare(nod * p)
{
    nod *q=p;
    while(q)
    {
        cout<<q->info<<' ';
        q=q->urm;
    }
    return;
}

int main()
{
    nod *p;
    p=NULL;
    int n, x, i=1;
    cin>>n;
    while(i<=n)
    {
        cin>>x;
        adaugare(p, x);
        i++;
    }
    afisare(p);
    //cout<<'\n';
    cout<<numarare(p);
    return 0;
}
