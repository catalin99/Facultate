#include "bibiotecaGrafica.h"
#ifndef FUNCTIARB_H_INCLUDED
#define FUNCTIARB_H_INCLUDED



void test()
{
    cout<<"test";
}

struct nod
{
    int value;
    nod *stanga;
    nod *dreapta;
};





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

void CreareCopie(nod *arbore, nod *&copie)
{
    if(arboreNULL(arbore))
        InitializareArbore(copie);
    else
        copie=arbore;
}

nod *creare_arbore_pre(short &z) ///creeaza arbore pana cand toti fii sunt nuli //preordine
{
    int valoare;
    if(!z)
        cout<<"Numele radacinii este: ";
    else
        cout<<"Informatia nodului cu numarul "<<z<<" este: ";
    z++;
    cin>>valoare;
    nod *arbore=new nod;
    if(valoare!=0)
    {
        arbore->value=valoare;
        arbore->stanga=creare_arbore_pre(z);
        arbore->dreapta=creare_arbore_pre(z);
    }
    else arbore=NULL;
    return arbore;
}

void parcurgePreordine(nod *&arbore) //parcurgere cu afisare
{
    if(arboreNULL(arbore))
        return;
    cout<<arbore->value<<' ';
    parcurgePreordine(arbore->stanga);
    parcurgePreordine(arbore->dreapta);
}

void parcurgeInordine(nod *&arbore) //parcurgere cu afisare
{
    if(arboreNULL(arbore))
        return;
    parcurgeInordine(arbore->stanga);
    cout<<arbore->value<<' ';
    parcurgeInordine(arbore->dreapta);
}

void parcurgePostordine(nod *&arbore) //parcurgere cu afisare
{
    if(arboreNULL(arbore))
        return;
    parcurgePostordine(arbore->stanga);
    parcurgePostordine(arbore->dreapta);
    cout<<arbore->value<<' ';
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

        cout<<coada[start]->value<<" ";
        if(coada[start]->stanga!=NULL)
            coada[++ultim]=coada[start]->stanga;
        if(coada[start]->dreapta!=NULL)
            coada[++ultim]=coada[start]->dreapta;
        start++;
    }
}

void crearevector(nod *arbore, int vect[], int &dimens) //complete
{
    if(arbore==NULL)
    {
        vect[dimens]=0;
        return;
    }
    nod* coada[100001];
    int start,ultim;
    start=ultim=1;
    coada[start]=arbore;
    vect[dimens]=coada[start]->value;
    while(start<=ultim)
    {
        if(coada[start]->stanga!=NULL)
        {
            coada[++ultim]=coada[start]->stanga;
            vect[++dimens]=coada[ultim]->value;
        }
        else
            vect[++dimens]=0;
        if(coada[start]->dreapta!=NULL)
        {
            coada[++ultim]=coada[start]->dreapta;
            vect[++dimens]=coada[ultim]->value;
        }
        else
            vect[++dimens]=0;
        start++;
    }
}

void vectortati(nod *arbore, int vtata[]) //complete
{
    if(arbore==NULL)
        return;
    nod* coada[100001];
    int start,ultim;
    start=ultim=1;
    coada[start]=arbore;
    vtata[coada[start]->value]=-1;
    while(start<=ultim)
    {
        if(coada[start]->stanga!=NULL)
        {
            coada[++ultim]=coada[start]->stanga;
            vtata[coada[ultim]->value]=coada[start]->value;
        }
        if(coada[start]->dreapta!=NULL)
        {
            coada[++ultim]=coada[start]->dreapta;
            vtata[coada[ultim]->value]=coada[start]->value;
        }
        start++;
    }
}

void Frunze_unFiu_doiFii (int vect[], int dimens, int dimv[], int frunze[], int unFiu[], int doiFii[])
{
    dimv[1]=0; //numarul de frunze
    dimv[2]=0;   //numar de noduri cu un fiu
    dimv[3]=0; //numar de noduri cu doi fii
    for(int i=0; i<=dimens || 2*i+2<=dimens; i++)
        if(!vect[2*i+1] && !vect[2*i+2] && vect[i])
        {
            dimv[1]++;
            frunze[dimv[1]]=vect[i];
        }
        else if(vect[2*i+1] && vect[2*i+2] && vect[i])
        {
            dimv[3]++;
            doiFii[dimv[3]]=vect[i];
        }
        else if (vect[i])
        {
            dimv[2]++;
            unFiu[dimv[2]]=vect[i];
        }
}

int AVL(nod *arbore, int k, int &echilibrat)
{
    int a, b;
    if(!(arbore->stanga) && !(arbore->dreapta))
        return k;
    else
    {
        if(arbore->stanga)
            a=AVL(arbore->stanga, k+1, echilibrat);
        if(arbore->dreapta)
            b=AVL(arbore->dreapta, k+1, echilibrat);
        if(abs(a-b)>1)
            echilibrat=0;
        if(a>b)
            return a;
        else
            return b;
    }
}

int inaltime(nod *arbore)
{
    int inaltimestanga, inaltimedreapta;
    if(!arbore)
        return -1;
    inaltimestanga=1+inaltime(arbore->stanga);
    inaltimedreapta=1+inaltime(arbore->dreapta);
    return (inaltimestanga > inaltimedreapta ? inaltimestanga : inaltimedreapta);
}

void listacomenzi()
{
        cout<<"\t Programul se va opri cand veti da comanda <stop>! \n";
        cout<<"\t Lista comenzi: \n";
        cout<<"1=Afisarea vectorului realizat in urma parcurgerii BFS \n";
        cout<<"2=Afisarea vectorului de tati \n";
        cout<<"3=Afisarea numarului de frunze \n";
        cout<<"4=Afisarea nodurilor cu un singur fiu \n";
        cout<<"5=Afisarea nodurilor cu doi fii \n";
        cout<<"6=Afisarea numarului total de noduri \n";
        cout<<"7=Verificare daca arborele este strict \n";
        cout<<"8=Verificare daca arobrele este echilibrat (AVL) \n";
        cout<<"9=Afisarea inaltimii arborelui \n";
        cout<<"10=Afisarea parcurgerii preordine a arborelui \n";
        cout<<"11=Afisarea parcurgerii postordine a arborelui \n";
        cout<<"12=Afisarea parcurgerii inordine a arborelui \n";
        cout<<"13=Afisarea parcurgerii BFS a arborelui \n";
        cout<<"Introducerea altor date poate duce erori! \n";
}

int demo()
{
    short z=0;
    nod *temp;
    int vect[1000], dimens=0;
    int vtata[1000], dimenstata=0;
    int dimv[5]; int frunze[100], unFiu[100], doiFii[100];

    nod *q;

    char s[100];
    strcpy(s, "zzz");

    int validare=0;

    char test[30];
    char sirnull[10]="";
    cout<<"\t \t \t ARBR \n";
    start:
    cout<<"\t Ce vrei sa testezi? \n";
    cout<<"\t 1. Realizarea grafica a arborelui \n";
    cout<<"\t 2. Biblioteca de functii \n";
    _repeat:
    strcpy(test, sirnull);
    cin.getline(test, 25);
    if(!stricmp(test, "1") || !stricmp (test, "grafic"))
        goto _graphic;
    else if (!stricmp(test, "2") || !stricmp(test, "biblioteca"))
        goto _library;
    else if(test[0]!='\0');
    {
        cout<<"Datele introduse sunt invalide; Mai incearca! \n";
        goto _repeat;
    }

//#ifdef graphicpart
    _graphic:
    cout<<"\t";
    cout<<"Notatia pentru nodul NULL este '0'"<<endl;
    citire(radacina); //1-8
    afisareArbore(radacina);//9-16
    d.modificat=true;
    delay(10000);
    char continua[20];
    cout<<"Vrei sa mai faci teste? (Da/Nu) \n";
    strcpy(continua, sirnull);
    //cin.getline(continua, 15);
    //if(!stricmp(continua, "Da"))
    //{
        goto start;
   // }
    //else
      //  goto finishs;
//#endif
//#ifdef library
    _library:
    cout<<"\t Aici programul va testa functiile pentru arbori binari! \n";
    cout<<"Introduceti arborele pentru teste! \n";

    cout<<"Se creeaza arborele prin metoda preordine \n";
    q=creare_arbore_pre(z);
    temp=q;

    crearevector(q, vect, dimens);
    q=temp;

    Frunze_unFiu_doiFii(vect, dimens, dimv, frunze, unFiu, doiFii);

    listacomenzi();
    while(stricmp(s, "stop"))
    {

        strcpy(s, sirnull);
        cin.getline(s, 30);
        if(!stricmp(s, "lista de comenzi")|| !stricmp(s, "comenzi") || !stricmp(s, "lista comenzi"))
            listacomenzi();
        else if(!stricmp(s, "vector bfs") || !stricmp(s, "1"))
        {
            cout<<"Vector BFS: \n";
            for(int i=0;i<=dimens; i++)
                cout<<vect[i]<<' ';
            cout<<endl;
        }

        else if(!stricmp(s, "vector de tati") || !stricmp(s, "tati") || !stricmp(s, "vector tati") || !stricmp(s, "2"))
        {
            q=temp;
            for(int i=0; i<=dimens; i++)
            vtata[i]=0;
            vectortati(q, vtata);
            cout<<"Vector de tati: \n";
            for(int i=0; i<=dimens; i++)
            {
                if(vtata[i])
                {
                    if(vtata[i]==-1)
                        cout<<"Nodul cu informatia "<<i<<" este radacina si nu are tata"<<'\n';
                    else
                        cout<<"Tatal nodului, avand informatia "<<i<<" este nodul cu informatia "<<vtata[i]<<'\n';
                }
            }
        }

        else if(!stricmp(s, "numar frunze") || !stricmp(s, "numar de frunze") ||!stricmp(s, "frunze") || !stricmp(s, "3"))
        {
            cout<<"Arborele dat are "<<dimv[1]<<" frunze: \n";
            for(int i=1; i<=dimv[1]; i++)
                cout<<frunze[i]<<' ';
            cout<<'\n';
        }

        else if(!stricmp(s, "noduri cu un fiu") || !stricmp(s, "noduri un fiu") || !stricmp(s, "un fiu") || !stricmp(s, "4"))
        {
            cout<<"Arborele dat are "<<dimv[2]<<" noduri cu un fiu: \n";
            for(int i=1; i<=dimv[2]; i++)
                cout<<unFiu[i]<<' ';
            cout<<'\n';
        }

        else if(!stricmp(s, "noduri cu doi fii") || !stricmp(s, "noduri doi fii") || !strcmp(s, "doi fii") || !stricmp(s, "5"))
        {
            cout<<"Arborele dat are "<<dimv[3]<<" noduri cu doi fii: \n";
            for(int i=1; i<=dimv[3]; i++)
                cout<<doiFii[i]<<' ';
            cout<<'\n';
        }

        else if(!stricmp(s, "numar de noduri") || !stricmp(s, "numar noduri") || !stricmp(s, "6"))
            cout<<"Arborele dat dare "<<dimv[1]+dimv[2]+dimv[3]<<" noduri \n";

        else if(!stricmp(s, "arbore strict") || !stricmp(s, "verificare arbore strict") || !stricmp(s, "verificare strict") || !stricmp(s, "7"))
        {
            if(!dimv[2])
                cout<<"Arborele binar dat este strict \n";
            else
                cout<<"Arborele binar dat nu este strict! \n";
        }

        else if(!stricmp(s, "arbore echilibrat") || !stricmp(s, "verificare arbore echilibrat") || !stricmp(s,"avl") || !stricmp(s, "verificare avl") || !stricmp(s, "8"))
        {
            q=temp;
            int echilibrat=1;
            AVL(q, 0, echilibrat);
            if(echilibrat)
                cout<<"Arborele dat este echilibrat! \n";
            else
                cout<<"Arborele dat nu este echilibrat! \n";
        }

        else if(!stricmp(s, "inaltimea arborelui") || !stricmp(s, "inaltime") || !stricmp(s, "height") || !stricmp(s, "9"))
        {
            q=temp;
            cout<<"Inaltimea arborelui este "<<inaltime(q)<<'\n';
        }

        else if(!stricmp(s, "parcurgere preordine") || !stricmp(s, "preordine") || !stricmp(s, "rsd") || !stricmp(s, "10"))
        {
            q=temp;
            cout<<"Parcurgere preordine: \n";
            parcurgePreordine(q);
            cout<<'\n';
        }

        else if(!stricmp(s, "parcurgere postordine") || !stricmp(s, "postordine") || !stricmp(s, "sdr") || !stricmp(s, "11"))
        {
            q=temp;
            cout<<"Parcurgere postordine: \n";
            parcurgePostordine(q);
            cout<<'\n';
        }

        else if(!stricmp(s, "parcurgere inordine") || !stricmp(s, "inordine") || !stricmp(s, "srd") || !stricmp(s, "12"))
        {
            q=temp;
            cout<<"Parcurgere inordine: \n";
            parcurgeInordine(q);
            cout<<'\n';
        }

        else if(!stricmp(s, "parcurgere bfs") || !stricmp(s, "adancime") || !stricmp(s, "bfs") || !stricmp(s, "13"))
        {
            q=temp;
            cout<<"Parcurgere BFS: \n";
            parcurge_BFS(q);
            cout<<'\n';
        }
        else if(stricmp(s, "stop") && validare==1)
        {
            cout<<"Comanda introdusa este invalida! \n";
            cout<<"Introduceti o comanda valida! \n";
            cout<<"Pentru a afisa lista de comenzi scrieti <lista de comenzi> \n";
        }
        else if(!stricmp(s, "stop"))
            cout<<"Programul se va opri \n";
        validare=1;
    }
    //char continua[20];
    cout<<"Vrei sa mai faci teste? (Da/Nu) \n";
    strcpy(continua, sirnull);
    cin.getline(continua, 15);
    if(!stricmp(continua, "Da"))
    {
        goto start;
    }
    else
        goto finishs;
//#endif // library
    finishs:
        cout<<"Testarea programului s-a incheiat";
    return 0;
}

void stergere(nod *father, nod *frunza)
{
	if(!father || !frunza)
	{
		cout<<"Nu se poate efectua stergerea";
		return;
	}
	else
	{
		if(father->stanga==frunza)
			father->stanga=NULL;
		else if (father->dreapta==frunza)
			father->dreapta=NULL;
		return;
	}
}


void insertionNode(nod*&tata,char tip[],nod*inserat)
{
    char stanga[8]="stanga",dreapta[8]="dreapta";
    if(tata)
    {
        cout<<"nodul este vid";
        return;
    }
    else
    {
       if(strcmp(tip,stanga)==1)
       {
            if(tata->stanga==NULL)
        {
            cout<<"nu se poate insera nodul la stanga";
        }
        else
            tata->stanga=inserat;

       }
       else
       {
         {
            if(tata->dreapta==NULL)
        {
            cout<<"nu se poate insera nodul la dreapta";
        }
        else
            tata->dreapta=inserat;

       }
       }
    }

}



#endif // FUNCTIARB_H_INCLUDED
