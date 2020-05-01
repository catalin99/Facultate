#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod* stg;
    nod* drt;
};

int EsteArboreNull(nod* a)
{
    if(a=='\0')
        return 1;
    return 0;
}

void InitializareArbore(nod*&a)
{
    if(!EsteArboreNull(a))
        a='\0';
}

bool InserareElement(nod*&a, int x)
{
    if(EsteArboreNull(a))
    {
        a=new nod;
        //if(!a)
            //return false;
        a->info=x;
        a->stg='\0';
        a->drt='\0';
        //return true;
    }
    else if(x<a->info)
        InserareElement(a->stg, x);
    else
        InserareElement(a->drt, x);
}

bool cautarelement(nod*a, int el)
{
    if(!EsteArboreNull(a))
    {
        if(a->info==el)
            return true;
        else if(el<a->info)
            return cautarelement(a->stg, el);
        else
            return cautarelement(a->drt, el);
    }
    else
        return false;
}


int SumaPare(nod *a)
{
    if(!EsteArboreNull(a))
    {
        if(a->info%2==0)
            return a->info+SumaPare(a->stg)+SumaPare(a->drt);
        else
            return SumaPare(a->stg)+SumaPare(a->drt);
    }
}
void parcurgereInordine(nod*a)
{
    if(!EsteArboreNull(a))
    {
        parcurgereInordine(a->stg);
        cout<<a->info<<" ";
        parcurgereInordine(a->drt);
    }
}

void parcurgerePreordine(nod*a)
{
    if(!EsteArboreNull(a))
    {
        cout<<a->info<<" ";
        parcurgerePreordine(a->stg);
        parcurgerePreordine(a->drt);
    }
}

void parcurgerePostordine(nod*a)
{
    if(!EsteArboreNull(a))
    {
        parcurgerePostordine(a->stg);
        parcurgerePostordine(a->drt);
        cout<<a->info<<" ";
    }
}
 bool prim(int x)
 {
     if(x<2)
        return false;
     if(x==2)
        return true;
     if(x%2==0)
        return false;
     for(int i=3; i*i<=x; i+=2)
        if(x%i==0)
            return false;
     return true;
 }

int NumararePrime(nod *a)
{
    if(!EsteArboreNull(a))
        if(prim(a->info))
            return 1+NumararePrime(a->stg)+NumararePrime(a->drt);
        else
            return NumararePrime(a->stg)+NumararePrime(a->drt);
}
int main()
{
    nod*a;
    InitializareArbore(a);
    int i, n, prime=0;
    int x, cautat;
    cout<<"Introduceti numarul de elemente din arbore ";
    cin>>n;
    cout<<"Introduceti elementele arborelui ";
    for(i=1; i<=n; i++)
    {
        cin>>x;
        InserareElement(a, x);
    }
    cout<<"Introduceti elementul cautat ";
    cin>>cautat;
    if(cautarelement(a, cautat))
        cout<<"Element gasit"<<endl;
    else cout<<"Element negasit"<<endl;
    cout<<"Parcurgere Inordine: ";
    parcurgereInordine(a);
    cout<<endl;
    cout<<"Parcurgere Preordine: ";
    parcurgerePreordine(a);
    cout<<endl;
    cout<<"Parcurgere Postordine: ";
    parcurgerePostordine(a);
    cout<<endl;
    cout<<"Suma elementelor pare: "<<SumaPare(a);
    cout<<endl;
    cout<<"Numarul elementelor prime: "<<NumararePrime(a);
}
