#include <iostream>
#include <cstring>
using namespace std;

struct nod
{
    int info;
    nod *st;
    nod *dr;
};
void inordineKmembru (nod *arb, int &k)
{
    if(arb)
    {
        /*if(k==1)
        {
            cout<<arb->info;
            return;
        }*/
        //else
        {
            inordineKmembru(arb->st, k);
            k--;
            if(k==0)
                cout<<arb->info;
            inordineKmembru(arb->dr, k);
            k--;
            if(k==0)
                cout<<arb->info;
        }
    }
    else
        return;
}

void inserare(nod *&arb, int val)
{
    if(!arb)
    {
        arb=new nod;
        arb->info=val;
        arb->st='\0';
        arb->dr='\0';
    }
    else if(val<arb->info)
        inserare(arb->st, val);
    else
        inserare(arb->dr, val);
}

void InOrdine(nod *arb)
{
    if(arb)
    {
        InOrdine(arb->st);
        cout<<arb->info<<' ';
        InOrdine(arb->dr);
    }
}

int main()
{
    int n, i=1, x, k;
    nod *arb=NULL;
    cin>>n; cin>>k;
    for(;i<=n; i++)
    {
        cin>>x;
        inserare(arb, x);
    }
    //InOrdine(arb); cout<<'\n';
    inordineKmembru(arb, k);
    return 0;
}
