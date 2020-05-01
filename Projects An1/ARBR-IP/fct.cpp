#include <iostream>
#include <cstring>
using namespace std;

struct nod
{
    int info;
    nod *stanga;
    nod *dreapta;
};
/// Functii arbori binari
bool arboreNULL(nod *arbore)
{
    if(!arbore)
        return 1;
    return 0;
}

void InitializareArbore(nod *arbore)
{
    if(!arboreNULL(arbore))
        arbore='\0';
    return;
}

void CreareCopie(nod *arbore, nod *copie)
{
    if(arboreNULL(arbore))
        InitializareArbore(copie);
    else
        copie=arbore;
}
nod  *creare_arbore() ///creeaza arbore pana cand toti fii sunt nuli //preordine
{
    int valoare;
    cout<<"Introduceti noul nod! ";
    cin>>valoare;
    nod *arbore=new nod;
    if(valoare!=0)
    {
        arbore->info=valoare;
        arbore->stanga=creare_arbore();
        arbore->dreapta=creare_arbore();
    }
    else arbore=NULL;
    return arbore;
}

void insereaza(nod *&arbore, nod *father, char tip[], int informatie)
{
    if(strcmp(tip, "STANGA") && strcmp(tip, "DREAPTA") && strcmp(tip, "RADACINA"))
    {
        cout<<"Eroare tip \n";
        return;
    }
    if(arboreNULL(father) && !(arboreNULL(arbore)))
    {
        cout<<"Adresa nodului tata este incorecta \n";
        return;
    }
    if(arboreNULL(arbore) && !(arboreNULL(father)))
    {
        cout<<"Arborele este NULL, deci adrasa catre nodul tata dat nu exista \n";
        return;
    }
    if(arboreNULL(father) && arboreNULL(arbore))
    {
        if(strcmp(tip, "RADACINA"))
        {
            cout<<"Nu poti initializa un arbore cu acest tip \n";
            cout<<"La initializare nodul introdus trebuie sa fie de tip <radacina> \n";
            return;
        }
        InitializareArbore(father);
        father->info=informatie;
        father->stanga='\0';
        father->dreapta='\0';
        arbore=father;
        return;
    }
    if(!strcmp(tip, "STANGA"))
    {
        if(father->stanga)
        {
            cout<<"Ai deja un fiu introdus in stanga acestui nod tata \n";
            return;
        }
        nod *q=new nod;
        q->info=informatie;
        q->stanga='\0';
        q->dreapta='\0';
        father->stanga=q;
    }
    if(!strcmp(tip, "DREAPTA"))
    {
        if(father->dreapta)
        {
            cout<<"Ai deja un fiu introdus in dreapta acestui nod tata \n";
            return;
        }
        nod *q=new nod;
        q->info=informatie;
        q->stanga='\0';
        q->dreapta='\0';
        father->dreapta=q;
    }
    ///working progress
    ///+Cum folosim asta
}
//begin_arbore_binar_cautare
void inserareArbBinCautare(nod*& arbore, int valoare)
{
    if(arboreNULL(arbore))
    {
        arbore=new nod;
        arbore->info=valoare;
        arbore->stanga='\0';
        arbore->dreapta='\0';
        return;
    }
    else if(valoare<arbore->info)
        inserareArbBinCautare(arbore->stanga, valoare);
    else if(valoare>arbore->info)
        inserareArbBinCautare(arbore->dreapta, valoare);
}

bool cautarelementArbBinCautare(nod*arbore, int el)
{
    if(!arboreNULL(arbore))
    {
        if(arbore->info==el)
            return true;
        else if(el<arbore->info)
            return cautarelementArbBinCautare(arbore->stanga, el);
        else
            return cautarelementArbBinCautare(arbore->dreapta, el);
    }
    else
        return false;
}
//end_arbore_binar_cautare

//begin_other_functions
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

int NumararePrime(nod *arbore)
{
    if(!arboreNULL(arbore))
        if(prim(arbore->info))
            return 1+NumararePrime(arbore->stanga)+NumararePrime(arbore->dreapta);
        else
            return NumararePrime(arbore->stanga)+NumararePrime(arbore->dreapta);
}
//end_other_functions


void elimina(nod *arbore, nod *&element, nod *father)
{
    if(arboreNULL(arbore) || arboreNULL(element) || arboreNULL(father))
    {
        cout<<"Eliminarea nu se poate face, deoarece unul dintre parametri este null \n";
        return;
    }
    if(father->stanga==element)
    {
        father->stanga='\0';
        delete element;
        return;
    }
    if(father->dreapta==element)
    {
        father->dreapta='\0';
        delete element;
        return;
    }
}

void parcurgePreordine(nod *&arbore) //parcurgere cu afisare
{
    if(arboreNULL(arbore))
        return;
    cout<<arbore->info<<' ';
    parcurgePreordine(arbore->stanga);
    parcurgePreordine(arbore->dreapta);
}

void parcurgeInordine(nod *&arbore) //parcurgere cu afisare
{
    if(arboreNULL(arbore))
        return;
    parcurgeInordine(arbore->stanga);
    cout<<arbore->info<<' ';
    parcurgeInordine(arbore->dreapta);
}

void parcurgePostordine(nod *&arbore) //parcurgere cu afisare
{
    if(arboreNULL(arbore))
        return;
    parcurgePostordine(arbore);
    parcurgePostordine(arbore);
    cout<<arbore->info<<' ';
}

void parcurge_BFS(nod *arbore)
{
    if(arbore==NULL)
        return;
    nod* coada[100001];
    int start,ultim;
    start=ultim=1;
    coada[start]=arbore;
    while(start<=ultim)
    {

        cout<<coada[start]->info<<" ";
        if(coada[start]->stanga!=NULL)
            coada[++ultim]=coada[start]->stanga;
        if(coada[start]->dreapta!=NULL)
            coada[++ultim]=coada[start]->dreapta;
        start++;
    }
}

///Arbore oarecare
void transformaArbInArbBin(nod *arbore)
{

}
