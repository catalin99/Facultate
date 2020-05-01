#include <iostream>
#include <fstream>

using namespace std;

ifstream in("bilatime.in");
ofstream out("bilatime.out");

struct nod
{
int info;
nod*st;
nod*dr;
};
nod *creare()
{
    int x;
    in>>x;
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

        out<<coada[p]->info<<" ";
        if(coada[p]->st!=NULL)
            coada[++u]=coada[p]->st;
        if(coada[p]->dr!=NULL)
            coada[++u]=coada[p]->dr;
        p++;
    }
}

int main()
{
    nod *q=new nod;
    q=creare();
    BFS(q);
}
