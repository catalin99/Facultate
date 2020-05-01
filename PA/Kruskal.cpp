#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("kruskal.in");
ofstream fout("kruskal.out");
struct vect
{
    int x,y,c;
};
vect v[1001],w[1001];

int n ,m,k;
long long ct;
void citire()
{
    fin>>n>>m;
    for(int i=1;i8<=m;i++)
        fin>>v[i].x>>v[i].y>>v[i].c;
}

void ordo()
{
    int ok;
    do{
        ok=0;
        for(int i=1;i<=m-1;i++)
            if(v[i].c>v[i+1].c)
            {
                v[0]=v[i];
                v[i]=v[i+1];
                v[i+1]=v[0];
                ok=1;
            }
        m--;
    }while(ok==1);
}

void kruskal()
{
    int l[1001];
    for(int i=1;i<=n;i++)
        l[i]=i;
    ordo();
    int i=1;
    while(k<n-1)
    {
        if(l[v[i].x]!=l[v[i].y])
        {
            k++;
            w[k].x=v[i].x;
            w[k].y=v[i].y;
            ct=ct+v[i].c;
            int nr1=l[v[i].x];
            int nr2=l[v[i].y];
            for(int i=1;i<=n;i++)
                if(l[i]==nr2)l[i]=nr1;
        }
        i++;
    }
    fout<<ct<<endl;;
    for(int i=1;i<=k;i++)
        fout<<w[i].x<<" "<<w[i].y<<endl;

}
int main()
{
    citire();
    kruskal();
    return 0;
}
