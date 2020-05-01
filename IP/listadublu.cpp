#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod* prec;
    nod* succ;
};

void citire(nod *&L, int x)
{
   if(L==NULL)
   {
       nod *q=new nod;
       q->info=x;
       q->prec='\0';
       q->succ='\0';
       L=q;
       return;
   }
    nod *p;
    p=L;
    nod *q=new nod;
    q->info=x;
    q->succ='\0';
    while(p->succ!='\0')
        p=p->succ;
    q->prec=p;
    p->succ=q;
}

void afisare(nod *L)
{
    nod *p=L;
    while(p!='\0')
    {
        cout<<p->info<<" ";
        p=p->succ;
    }
}


void eliminapare(nod *&L)
{
    nod *p;
    p=L;
    while(p!='\0')
    {
        if(p->info%2==0)
        {
            nod *q=p;
            p->prec->succ=q->succ;
            p->succ->prec=q->prec;
            delete(q);
        }
        p=p->succ;
    }

}

int main()
{
    int nrelem;
    nod *L=new nod;
    L='\0';
    cin>>nrelem;
    for(int i=0; i<nrelem; i++)
    {
        int x;
        cin>>x;
        citire(L, x);
    }
    afisare(L);
    eliminapare(L);
    cout<<"Afisare dupa eliminarea numerelor pare: \n";
    afisare(L);
    return 0;
}
