#include <iostream>
using namespace std;
struct nod{
int info;
nod*st,*dr;
};
nod *creare()
{
    int x;
    cin>>x;
    nod *q=new nod;
    if(x!=0)
    {
        q->info=x;
        q->st=creare();
        q->dr=creare();
    }
    else q=NULL;
    return q;
}
void afisare_Inordine(nod *q)
{
    if(!q)
        return;
    else
    {
        afisare_Inordine(q->st);
        cout<<q->info<<' ';
        afisare_Inordine(q->dr);
    }
}

void afisare_Preordine(nod *q)
{
    if(!q)
        return;
    else
    {
        cout<<q->info<<' ';
        afisare_Preordine(q->st);
        afisare_Preordine(q->dr);
    }
}
void afisare_Postordine(nod *q)
{
    if(!q)
        return;
    else
    {
        afisare_Postordine(q->st);
        afisare_Postordine(q->dr);
        cout<<q->info<<' ';
    }
}

void BFS(nod *q)
{
    if(q==NULL)
        return;
    nod* coada[100001];
    int p,u;
    p=u=1;
    coada[p]=q;
    while(p<=u)
    {

        cout<<coada[p]->info<<" ";
        if(coada[p]->st!=NULL)
            coada[++u]=coada[p]->st;
        if(coada[p]->dr!=NULL)
            coada[++u]=coada[p]->dr;
        p++;
    }
}

int main()
{
    nod*q=new nod;
    q=creare();
    cout<<"Afisarea inordine:"<<" ";
    afisare_Inordine(q);
    cout<<endl;
    cout<<"Afisarea preordine:"<<" ";
    afisare_Preordine(q);
    cout<<endl;
    cout<<"Afisarea postordine:"<<" ";
    afisare_Postordine(q);
    cout<<endl;
    cout<<"Afisare BFS: ";
    BFS(q);
    return 0;
}
