#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *succ;
};

struct digraf
{
    int n; ///nr varfuri
    int m; ///nr arce
    nod *a[100];
};
void D_NULL(digraf &D)
{
    for(int i=0; i<=50; i++)
        D.a[i]==NULL;
}
void insereaza_arc(digraf &D, int x, int y)
{
    nod *p=D.a[x];
    if(!p)
    {
        nod *q=new nod;
        q->info=y;
        q->succ='\0';
        p->info=x;
        p->succ=q;
        return;
    }
    while(p->succ && p->info!=y)
        p=p->succ;
    if(p->info==y)
        return;
    nod *q=new nod;
    q->info=y;
    q->succ='\0';
    p->succ=q;

}
void creeaza_digraf(digraf &D)
{
    cin>>D.n;
    cin>>D.m;
    for(int i=1; i<=D.m; i++)
    {
        int x, y;
        cin>>x>>y;
        insereaza_arc(D, x, y);
    }
}
int main()
{
    digraf D;
    D_NULL(D);
    creeaza_digraf(D);
}
