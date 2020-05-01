#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("arbore.in");

struct nod {
int info;
nod *st,*dr;

};


nod* Creare(char var[], int &counter, nod *&p)///creare arbore cu o anumita proprietate, adica pentru valoarea null din arbore se citeste #
{
    char y;
    //nod *p;
    //cin>>y;
    while(counter<strlen(var))
    {
        counter++;
        y=var[counter];
        p=new nod;
        if(isspace(y))
        {
            counter++;
            Creare(var, counter, p);
        }
        else if(isdigit(y))
        {
            int x=y-'0';
            p->info=x;
            p->st=Creare(var, counter, p);
            p->dr=Creare(var, counter, p);
        }
        else
            p=NULL;
    }
    //return p;
}

void parcurgere(nod *a)///parcurgere arbore si afisare, pentru valoarea null se afiseaza #, dar prin citirea de la tastatura
{
    if(a==NULL)cout<<"#";

   else  if(a!=NULL)
    {
        cout<<a->info;
        parcurgere(a->st);
        parcurgere(a->dr);
    }

}

nod* fuzionare(nod *a,nod *b)
{
    nod*c=new nod;
    if(a!=NULL&&b!=NULL)
    {
        c->info=a->info+b->info;
        c->st=fuzionare(a->st,b->st);
        c->dr=fuzionare(a->dr,b->dr);
    }
    else if(a==NULL&&b!=NULL)
    {
        c->info=b->info;
        c->st=fuzionare(a,b->st);
        c->dr=fuzionare(a,b->dr);

    }
    else if(a!=NULL&&b==NULL)
    {
        c->info=a->info;
        c->st=fuzionare(a->st,b);
        c->dr=fuzionare(a->dr,b);
    }
    else c=NULL;
    return c;
}


int main()
{
    nod *a=new nod;
    char primul[200];
    char doi[200];
    int counter;
    counter=-1;
    f.get(primul, 199);
    f.get();
    f.get(doi, 199);
    a=NULL;
    Creare(primul, counter, a);
    //cout<<endl<<"vom creea urmatorul arbore"<<endl;
    counter=-1;
    nod *b=new nod;
    b=NULL;
    Creare(doi, counter, b);
    nod *c=new nod;
    c=NULL;
    c=fuzionare(a,b);
     //parcurgere(a);
     cout<<endl<<"arborele fuzionat rezultat este de parcurgerea: ";
    parcurgere(c);
    return 0;
}
