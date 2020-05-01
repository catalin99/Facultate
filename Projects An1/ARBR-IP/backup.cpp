#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <cstring>

#define graphicpart
#define library

//Start_Resolution
#define rh 1366 //inaltime
#define rl 700//768  //lungime
#define mijh 683 //rh/2
#define mijl 350//384 //rl/2
//End_Resolution

//Start_MenuData
#define xstart 1180
#define xend 1360 //xstart+180 --> end lenght (-(0..5))
#define xstarttext 1200 //xstart+20
#define ystart 5
#define yend 30 //ystart+20
#define ystarttext 9 //ystart+4
//END_MenuData

//Start_Design
#define sv 100 //time
#define svnull 10 //null time
//END_Design

using namespace std;

#ifdef graphicpart //structures
struct node
{

	node*left;
	char info[20];
	node*right;
};
node*root, *radacina;

struct listArb
{
	node*elemNode;
	listArb*up;
	listArb*down;
};
listArb*first = NULL;
listArb*last = NULL;

struct dateMemorate
{
    short pozMem,pozY;
    char cheie[20]="  ";
    short razaMem;
    short tip=0;
    int culoare=0;
    node * nodeMem;
}x[1100];

struct date
{
       short pozX, pozY;//punct
       short raza = 15;//raza
       short lung=-1;//pozitii anterioare
       short midx=mijh;
       short a=0;
       short lastPozX,lastPozY;
       short linie=1;
       short mij=mijl;
	   bool modificat=false;

}d;
#endif

#ifdef library //structures
struct nod
{
    int value;
    nod *stanga;
    nod *dreapta;
};
#endif

#ifdef graphicpart
void erori(short eroare)//6
{
    switch (eroare)
    {
        case 1:showerrorbox("Ati ales o coordonata nevalida.");break;
        case 2:showerrorbox("Nu exita nici un nod in arbore.");break;
        case 3:showerrorbox("Arborele este vid.");break;
        case 4:showerrorbox("Nu se poate sterge deoarece nu exista noduri in arbore.");break;
        case 5:showerrorbox("Parcurgere nereusita.");break;
        case 6:showerrorbox("Nu se poate insera nodul deoarece tatal acestuia are deja 2 fii.");break;
    }
}

void push(node*pointer)//3
{
	if (first == NULL)
	{
		first = new listArb;
		first->elemNode = pointer;
		first->up = NULL;
		first->down = NULL;
		last = new listArb;
		last = first;

	}
	else
	{
		listArb*aux;
		aux = new listArb;
		aux->elemNode = pointer;
		aux->down = last;
		last->up = aux;
		aux->up = NULL;
		last = aux;
	}
}

void pop(node*&pointer)//5
{
	listArb*aux;
	aux = new listArb;
	aux = first;
	pointer = first->elemNode;
	first = first->up;
	delete aux;
}

bool vid()//4
{
	if (first == NULL)
		return true;
	else
		return false;
}

void nodNext(int &contor,int &nrNode)//8
{
    contor++;
    nrNode--;
    while(x[contor].tip!=1 && nrNode!=0)
        {
            contor++;
            if(x[contor].tip==2)
            {
                nrNode--;
            }
            if(x[contor].tip==0)
            {
                x[contor].tip=3;
            }
        }
    nrNode--;
}

int nr(node*aux)                         ////adugat
{
    if(aux==NULL )
        return 1;
    else
        return 1+nr(aux->left)+nr(aux->right);
}

void conversie()//7
{
    int i;
    i=nr(root);
	char null[] = "0";
	int contor = 0;
	x[0].tip = 1;
	x[0].nodeMem=root;
    //x[0].cheie='/0';
	strcpy(x[0].cheie, root->info);
	if (i == 3)
	{
	    x[1].tip=2;
	    x[2].tip=2;
		return ;
	}
	node*pointL;
	node*poz;
	node*pointR;

	poz = new node;
	poz = root;
	push(poz);

	while (vid() == false)
	{
		pointL = new node;
		poz = new node;
		pointR = new node;
		pop(poz);
		pointL = poz->left;
		pointR = poz->right;

		if (pointL != 0)
		{
			x[2 * contor + 1].tip = 1;
			strcpy(x[2 * contor + 1].cheie, pointL->info);
			x[2*contor+1].nodeMem=pointL;
			push(pointL);
		}
		else
		{
			x[2 * contor + 1].tip = 2;
		}

		if (pointR != 0)
		{
			x[2 * contor + 2].tip = 1;
			strcpy(x[2 * contor + 2].cheie, pointR->info);
			x[2*contor+2].nodeMem=pointR;
			push(pointR);
		}
		else
		{
			x[2 * contor + 2].tip = 2;

		}
		nodNext(contor, i);
	}

}

void readAndConv() //2
{
	char st[20], dr[20], null[] = "0";
	int nrNode = 1;
	node*pointL;
	node*poz;
	node*pointR;
	int i = 0;
	root = new node;
	cout << "Nume radacina: ";
	cin >> root->info;
	if(root->info[0]=='0' && root->info[1]==NULL)
    {
        erori(3);
        return;
    }
	cout << endl;
	push(root);
	while (vid() == false)
	{

		pointL = new node;
		poz = new node;
		pointR = new node;
		pop(poz);
		cout << "Nodul cu numarul " << i << " contine informatia: " << poz->info << endl;
		cout << "Fiul stang al nodului " << i << " contine informatia: ";
		cin >> st;
		cout << "Fiul drept al nodului " << i << " contine informatia: ";
		cin >> dr;
		cout << endl;
		i++;

		if (strcmp(st, null) != 0)
		{
		    //pointL->info=NULL;
			strcpy(pointL->info, st);
			poz->left = pointL;
			push(poz->left);
			nrNode++;
		}
		else
		{
			poz->left = NULL;
			nrNode++;
		}
		if (strcmp(dr, null) != 0)
		{
		    //pointR->info=NULL;
			strcpy(pointR->info, dr);
			poz->right = pointR;
			push(poz->right);
			nrNode++;
		}
		else
		{
			poz->right = NULL;
			nrNode++;
		}


	}
	//conversie(nrNode);
}

void citire(node*&radacina) //1
{
	root= new node;
	last= new listArb;
	readAndConv();
	radacina=root;

}

int srd(node*poz) //complete
{
	if (poz == NULL)
		return 0;

	srd(poz->left);
	cout  << poz->info<<"   ";
	srd(poz->right);
}

int sdr(node*poz) //complete
{
	if (poz == NULL)
		return 0;

	sdr(poz->left);
    sdr(poz->right);
	cout  << poz->info<<"   ";

}

int rsd(node*poz) //complete
{
	if (poz == NULL)
		return 0;

    cout  << poz->info<<"   ";
	rsd(poz->left);
	rsd(poz->right);
}

void coordonate()//complet
{
    int i=0;
    while(x[i].tip!=0)
    {
        cout<<"nodul "<<i<<" :"<<x[i].pozMem<<" " <<x[i].pozY<<" " <<x[i].razaMem<<" " <<x[i].tip<<endl;
        i++;
    }
}

int xCautat(int px,int py)//complet
{
    short i=0,ok=0,nod=0;
    while(ok==0 && x[i].tip!=0)
    {
        if(x[i].tip==1)
        {
            nod++;
            if(x[i].pozY-x[i].razaMem<=py && x[i].pozY+x[i].razaMem>=py)
               {
                   if(x[i].pozMem-x[i].razaMem<=px && x[i].pozMem+x[i].razaMem>=px)
                    {
                        ok=1;
                    }
               }
       }
       i++;
    }
   if(ok)
        return nod;
    else return -1;

}

int xCautatOp(int px,int py)//complet
{
    short i=0,ok=0;
    while(!(x[i].pozY-x[i].razaMem<=py && x[i].pozY+x[i].razaMem>=py) && x[i].tip!=0)
    {
        i=i*2+1;
    }
    while(x[i].tip!=0 && ok==0)
    {
        if(x[i].pozMem-x[i].razaMem<=px && x[i].pozMem+x[i].razaMem>=px)
        {
            ok=1;
        }
        i++;
    }
    return i;
}

void clickNode() //Numarul nodului
{
    int px,py;
    click:
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
        ///////esc
    }
    getmouseclick(WM_LBUTTONDOWN, px, py);
    int cautat;
    cautat=xCautat(px,py);
    if(cautat>0)
    {
        if(cautat==1)
            cout<<"Nodul pe care ati apasat este radacina arborelui! \n";
        else
            cout<<"Numarul nodului pe care ati apasat, conform parcurgerii BFS este: "<<cautat-1<<endl;
    }
    else if(cautat==-1)
    {
        cout<<"Nu exista niciun nod la coordonatele unde ati apasat click! \n";
        goto click;
    }
}

int adancime(node *aux)
{
    if (!aux) return -1;

    return 1 + max(adancime(aux->left), adancime(aux->right));
}

void adancimeMenu() //working progress
{
    int px,py;
    click:
    while (!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(500);
    }
    getmouseclick(WM_LBUTTONDOWN, px, py);
    short i=0,ok=0,nod=0;
    while(ok==0 && x[i].tip!=0)
    {

        if(x[i].tip==1)
        {
            nod++;
            if(x[i].pozY-x[i].razaMem<=py && x[i].pozY+x[i].razaMem>=py)
               {
                   if(x[i].pozMem-x[i].razaMem<=px && x[i].pozMem+x[i].razaMem>=px)
                    {
                        ok=1;
                    }
               }
       }
       i++;

    }
    i--;
    int nivel=0,valMax=0;
    if(x[i].nodeMem)
    {
        valMax=adancime(x[i].nodeMem);
        if(i)
            cout<<"Adancimea nodului "<<i<<", avand informatia "<<x[i].cheie<<", este: "<<valMax<<endl ;
        else
            cout<<"Adancimea radacinii este: "<<valMax<<endl;
    }
    else
    {
        cout<<"Eroare!!! \n";
    }
}


void  stMenu() //complet //14 //
{
    cleardevice();
    setbkcolor(15); //white
    setcolor(16); //black
    setlinestyle(0, 0, 2);
    short ys=0, ye=0, yst=0;
//start_test
    char text1[]="Exit";
    rectangle(xstart,ystart+ys,xend,yend+ye);
    settextstyle(1,HORIZ_DIR ,1.5);
    outtextxy(xstarttext,ystarttext+yst,text1);
    ye+=25;
    ys=ye;
    yst+=25;
    char text2[]="Numar nod";
    rectangle(xstart,ystart+ys,xend,yend+ye);
    settextstyle(1,HORIZ_DIR , 1.5);
    outtextxy(xstarttext,ystarttext+yst,text2);
    ys=ye;
    ye+=25;
    yst+=25;
    char text3[]="Adancime"; //Adancime
    rectangle(xstart,ystart+ys,xend,yend+ye);
    settextstyle(1,HORIZ_DIR , 1.5);
    outtextxy(xstarttext,ystarttext+yst,text3);
    ys=ye;
    ye+=25;
    yst+=25;
    char text4[]="SDR";
    rectangle(xstart,ystart+ys,xend,yend+ye);
    settextstyle(1,HORIZ_DIR , 1.5);
    outtextxy(xstarttext,ystarttext+yst,text4);
    ys=ye;
    ye+=25;
    yst+=25;
    char text5[]="SRD";
    rectangle(xstart,ystart+ys,xend,yend+ye);
    settextstyle(1,HORIZ_DIR , 1.5);
    outtextxy(xstarttext,ystarttext+yst,text5);
    ys=ye;
    ye+=25;
    yst+=25;
    char text6[]="RSD";
    rectangle(xstart,ystart+ys,xend,yend+ye);
    settextstyle(1,HORIZ_DIR , 1.5);
    outtextxy(xstarttext,ystarttext+yst,text6);
    ys=ye;
    ye+=25;
    yst+=25;
//end_test
//status test: complete

}


void clickF() //12 //Click meniu
{
    int px,py,astept=0;
    click:
    while (!ismouseclick(WM_LBUTTONDOWN))
        delay(500);
    getmouseclick(WM_LBUTTONDOWN, px, py);
    if( px>xstart &&px<xend)
    {
        if( py>=ystart&& py<=yend)
            closegraph();
        else
        {
            if(py>30 && py<55)
            {
                clickNode();
                goto click;
            }
            else if(py>55 && py<80)
            {
                adancimeMenu();
                goto click;
            }
            else if(py>80 && py<105)
            {
                cout<<"Parcurgerea Stanga-Dreapta-Radacina a arborelui este: ";
                sdr(radacina);
                cout<<endl;
                goto click;
            }
            else if(py>105 && py<130)
            {
                cout<<"Parcurgerea Stanga-Radacina-Dreapta a arborelui este: ";
                srd(radacina);
                cout<<endl;
                goto click;
            }
            else if(py>130 && py<155)
            {
                cout<<"Parcurgerea Radacina-Stanga-Dreapta a arborelui este: ";
                rsd(radacina);
                cout<<endl;
                goto click;
            }
            else
                goto click;
        }

    }
    else
        goto click;
}


void voidNode(short x,short y)
{
    //start_test_color
    //setcolor(1); //blue
    //setcolor(2); /green
    //setcolor(3); //turcuaz
    //setcolor(4); //brown..cred
    //setcolor(5); //mov
    //setcolor(6); //mustar =))
    //setcolor(7); //gri
    //setcolor(8);//gri...
    setcolor(1); //culoare linii nod null - blue
    y+=4;
    line(x+30,y,x-30,y);
    Sleep(svnull);
    line(x-30,y,x-20,y+15);
    Sleep(svnull);
    line(x-10,y,x,y+15);
    Sleep(svnull);
    line(x+10,y,x+20,y+15);
    Sleep(svnull);
    line(x+30,y,x+40,y+15);
    Sleep(svnull);
}

void cerc(short pozX,short pozY,char cheie[],short &raza)//complet //16
{
    short lungime;
    char pattern[8] = {0x00, 0x70, 0x20, 0x27, 0x24, 0x24, 0x07, 0x00};
    lungime=strlen(cheie);
    settextstyle(1,HORIZ_DIR ,1);
    setfillstyle(EMPTY_FILL, 15);
    setbkcolor(15);
    if(lungime>5)
        lungime=6;
    setcolor(0); //culoare cerc - black
    setlinestyle(0,0,2);
    circle(pozX, pozY, raza+6*lungime);
    raza=raza+6*lungime;
    Sleep(sv);
    setcolor(4); //culoare text - red
    outtextxy(pozX-7*lungime,pozY-7,cheie);
    Sleep(sv);
}

void linii(short lung,short  Y) //complet //11
{
   short rand=0,putere=2;
   for(short index=0;index<=(lung-1)/2;index++)
   {
       if(x[index].tip==1)
       {
           setcolor(3); //culoare linie intrerupta - cyan
           setlinestyle(4, 10, 4);
           line(x[index].pozMem,Y+x[index].razaMem,x[index*2+1].pozMem,Y+125-x[index].razaMem);
           Sleep(sv);
           setcolor(2); //culoare linie - green
           setlinestyle(0, 0, 2);
           line(x[index].pozMem,Y+x[index].razaMem,x[index*2+2].pozMem,Y+125-x[index].razaMem);
           Sleep(sv);
       }
       rand+=2;
       if(rand==putere)
       {
           putere*=2;
           Y+=125;
           rand=0;
       }
   }
}

void functie2(short &pozX,short &lastPozX,short &lastPozY,short &pozY,short &index,short &midx,short &linie)//13
{
    pozX=lastPozX;
    pozX=pozX/2;
    lastPozY=pozY;
    pozY+=125;
    if(index!=1)
    {
        midx/=2;
    }
    linie=linie*2;
}

void afisare(short height,short lenght)//10
{

    { //initializare windows
    int gdriver = EGA, gmode = EGAHI, errorcode;
    initwindow(height, lenght);    setbkcolor(15); //color=white
    //setbkcolor(16); -black
    errorcode = graphresult();
    if (errorcode != grOk)
        {
            printf("Graphics error: %s\n", grapherrormsg(errorcode));
            printf("Press any key to halt:");
            getch();
            exit(1);               /* terminate with an error code*/
        }
   }
   stMenu();
}

void initializare()
{
    int i=0;
    while(x[i].tip!=0)
    {
        x[i].nodeMem=NULL;
        x[i].pozMem=0;
        x[i].pozY=0;
        x[i].razaMem=0;
        x[i].tip=0;
        i++;
    }
    d.lung=-1;
    d.linie=1;
    d.pozX=1366;
    d.lastPozX=683;
    d.midx=mijh;
}

int desenareArbore() //9
  {
        if(d.modificat==true)
        {
            initializare();
        }
        conversie();
        stMenu();
        char cheie[]="1245458";

        d.pozX= mijh;
        d.pozY= 100;//30+10*strlen(cheie);
        x[0].pozMem=d.pozY;
        short Y=d.pozY;
        Sleep(sv);

    for(short index=1;index<=10;index++)
    {
       d.lastPozX=d.pozX;
       for(short jndex=1;jndex<=d.linie;jndex++)
       {
           d.raza=15;
           d.lung++;
           if(x[d.lung].tip==1)
           {
               cerc(d.pozX,d.pozY,x[d.lung].cheie,d.raza);
               x[d.lung].razaMem=d.raza;
               x[d.lung].pozY=d.pozY;
               //strcpy(x[d.lung].cheie,cheie);
           }
           else
           {
               if(x[d.lung].tip==2)
               {
                   voidNode(d.pozX,d.pozY-25);
                   x[d.lung].razaMem=0;
                   x[d.lung].pozY=d.lastPozY;
               }
           }
           x[d.lung].pozMem=d.pozX;
           d.pozX+=d.midx;
       }

       if(x[d.lung].tip==1 || x[d.lung].tip==2)
            Sleep(sv);
       //strcpy(cheie,cheie+1);
       functie2(d.pozX,d.lastPozX,d.lastPozY,d.pozY,index,d.midx,d.linie);
       strcpy(cheie,cheie+1);
    }
    x[0].pozY=Y;
   //cout<<x[0].pozY;

    linii(d.lung,Y);

    //cout<<" Desenare Ok!"<<endl;
    coordonate();
    clickF();
   //getch();
    return 0;
}

void afisareArbore(node*&aux)
{
        short height=rh,lenght=rl;
        afisare(height,lenght);
        setbkcolor(15);
        desenareArbore();
        aux=root;

}
#endif

#ifdef library

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
#endif
int main()
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

#ifdef graphicpart
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
#endif
#ifdef library
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
#endif // library
    finishs:
        cout<<"Testarea programului s-a incheiat";
    return 0;
}
