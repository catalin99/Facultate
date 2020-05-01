#include <iostream>
using namespace std;

struct node
{
    int val;
    node *stg;
    node *drt;
};

void InsertNewNode(node *&arb, int x)
{
    if(!arb)
    {
        arb=new(node);
        arb->stg='\0';
        arb->drt='\0';
        arb->val=x;
        return;
    }
    if(x>=arb->val)
        InsertNewNode(arb->drt, x);
    if(x<arb->val)
        InsertNewNode(arb->stg, x);
}

void inordine(node *arb)
{
    if(!arb)
        return;
    inordine(arb->stg);
    cout<<arb->val<<' ';
    inordine(arb->drt);
}
//asta

void preordine(node *arb)
{
    if(!arb)
        return;
    cout<<arb->val<<' ';
    preordine(arb->stg);
    preordine(arb->drt);
}

void postordine(node *arb)
{
    if(!arb)
        return;
    postordine(arb->stg);
    postordine(arb->drt);
    cout<<arb->val<<' ';
}

node *cautare(node *arb, int cautat)
{
    if(!arb)
        return '\0';
    if(arb->val==cautat)
        return arb;
    if(arb->val<cautat)
        return cautare(arb->drt, cautat);
    else
        return cautare(arb->stg, cautat);
}

node *searchpred(node *arb, node *_sch)
{
    if(arb==_sch)
        return '\0';
    if(arb->stg==_sch || arb->drt==_sch)
        return arb;
    if(_sch->val>arb->val)
        return searchpred(arb->drt, _sch);
    else
        return searchpred(arb->stg, _sch);
}

void elimina(node *_sch, node *pred, node *succSTG, node *succDRT)
{
    //case 1
    if(!succSTG && !succDRT)
    {
        if(pred->stg==_sch)
        {
            pred->stg='\0';
            delete (_sch);
        }
        if(pred->drt==_sch)
        {
            pred->drt='\0';
            delete(_sch);
        }
    }
    //case 2
    else if(!succSTG)
    {
        if(pred->stg==_sch)
        {
            pred->stg=succDRT;
            delete (_sch);
        }
        if(pred->drt==_sch)
        {
            pred->drt=succDRT;
            delete(_sch);
        }
    }
    else if(!succDRT)
    {
        if(pred->stg==_sch)
        {
            pred->stg=succSTG;
            delete (_sch);
        }
        if(pred->drt==_sch)
        {
            pred->drt=succSTG;
            delete(_sch);
        }
    }
    //case 3
    else
    {
        node *copie=_sch;
        node *pred3=_sch;
        copie=copie->stg;
        while(copie->drt)
        {
            pred3=copie;
            copie=copie->drt;
        }
        int aux=_sch->val;
        _sch->val=copie->val;
        copie->val=aux;
        node *succSTG3=copie->stg;
        node *succDRT3=copie->drt;
        elimina(copie, pred3, succSTG3, succDRT3); //case 1 or case 2
    }
}

void succesor(node *arb, int elem, int &succ)
{
    if(!arb)
        return;
    if(arb->val>elem && arb->val<succ)
        succ=arb->val;
    succesor(arb->stg, elem, succ);
    succesor(arb->drt, elem, succ);
}

void predecesor(node *arb, int elem, int &pred)
{
    if(!arb)
        return;
    if(arb->val<elem && arb->val>pred)
        pred=arb->val;
    predecesor(arb->stg, elem, pred);;
    predecesor(arb->drt, elem, pred);
}

int main()
{
    node *arb=new(node);
    arb='\0';
    int x;
    cout<<"Citirea arborelui pana la intalnirea valorii 0: \n";
    cin>>x;
    while(x)
    {
        InsertNewNode(arb, x);
        cin>>x;
    }
    cout<<"Afisarea arborelui in preordine: ";
    preordine(arb);
    cout<<'\n';
    cout<<"Afisarea arborelui in postordine : ";
    postordine(arb);
    cout<<'\n';
    cout<<"Afisarea arborelui in inordine: ";
    inordine(arb);
    cout<<'\n';
    int sch;
    start:
    cout<<"Introduceti valoarea cautata: \n";
    cin>>sch;
    node *_sch=cautare(arb, sch);
    if(!_sch)
        cout<<"Element nu a fost gasit. \n";
    else
        cout<<"Element gasit \n";
    if(_sch)
    {
        int askelim;
        cout<<"Vrei sa elimini elementul cautat? \n1=DA, alta valoare=NU! \n";
        cin>>askelim;
        if (askelim==1 && _sch)
        {
            node *succSTG=_sch->stg;
            node *succDRT=_sch->drt;
            node *pred=searchpred(arb, _sch);
            elimina(_sch, pred, succSTG, succDRT);
            cout<<"Afisarea noului arbore: \n";
            inordine(arb);
        }
            cout<<"\nVreti sa mai faceti cautari? \n";
            int zrz;
            cout<<"Scrieti 1 pentru DA, altceva pentru NU! \n";
            cin>>zrz;
            if(zrz==1)
                goto start;
    }
    else
    {
        cout<<"Doriti sa afisati succesorul sau predecesorul elementului? \n";
        cout<<"0=NU \n";
        cout<<"1=Succesor \n";
        cout<<"2=Predecesor \n";
        cout<<"3=Succesor si predecesor \n";
        short ps=0; cin>>ps;
        int pred=-9999999;
        int succ=9999999;
        if(ps==1)
        {
            succesor(arb, sch, succ);
            if(succ!=9999999)
                cout<<"Succesorul elementului "<<sch<<" este: "<<succ;
            else
                cout<<"Elementul nu are succesor";
        }
        else if(ps==2)
        {
            predecesor(arb, sch, pred);
            if(pred!=-9999999)
                cout<<"Predecesorul elementului "<<sch<<" este: "<<pred;
            else
                cout<<"Elementul nu are predecesor";
        }
        else if(ps==3)
        {
            succesor(arb, sch, succ);
            if(succ!=9999999)
                cout<<"Succesorul elementului "<<sch<<" este: "<<succ<<'\n';
            else
                cout<<"Elementul nu are succesor"<<'\n';
            predecesor(arb, sch, pred);
            if(pred!=-9999999)
                cout<<"Predecesorul elementului "<<sch<<" este: "<<pred;
            else
                cout<<"Elementul nu are predecesor";
        }
        else
            cout<<"Nu se vor afisa succesorul si/sau predecesorul elementului cautat \n";
        cout<<"\nVreti sa mai faceti cautari? \n";
        int zrzsp;
        cout<<"Scrieti 1 pentru DA, altceva pentru NU! \n";
        cin>>zrzsp;
        if(zrzsp==1)
            goto start;
    }
    return 0;
}
