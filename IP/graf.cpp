#include <iostream>

using namespace std;
 struct nod
 {
        int info;
        nod *urm;
 };
 nod *v[100005];
 int n,m,viz[200005];

 void adauga(nod*&dest,int val)
 {
     nod *p=new nod;
     p->info=val;
     p->urm=dest;
     dest=p;
 }
 void citire()
 {
     cin>>n>>m;
     for(int i=1;i<=m;i++)
     {
         int x,y;
         cin>>x>>y;
         adauga(v[x],y);
     }
 }
 void dfs(int start)
 {
     nod *q=v[start];
     viz[start]=1;
     cout<<start<<" ";
     while(q!=NULL)
     {
         if(viz[q->info]==0)
            dfs(q->info);
         q=q->urm;
     }
 }
 void bfs(int start)
 {
     nod *coada[100005];
     int prim,ultim;
     prim=ultim=1;
     coada[prim]=v[start];
     viz[start]=1;
     cout<<start<<" ";
     while(prim<=ultim)
     {
        nod *q=coada[prim++];
        while(q!=NULL)
        {
            if(viz[q->info]==0)
            {
                coada[++ultim]=q;
                viz[q->info]=1;
                cout<<q->info<<" ";
            }
            q=q->urm;
         }
     }
 }
int main()
{
    citire();
    //dfs(1);
    cout<<'\n';
    bfs(1);
    return 0;
}
