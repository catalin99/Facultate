#include <windows.h>
#include <iostream>

#ifndef BIBIOTECAGRAFICA_H_INCLUDED
#define BIBIOTECAGRAFICA_H_INCLUDED



#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <cstring>

#define graphicpart
//#define library

//Start_Resolution
#define rh 1366 //inaltime
#define rl 768  //lungime
#define mijh 683 //rh/2
#define mijl 384 //rl/2
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
#define sv 400 //time
#define svnull 100 //null time
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
    i=nr(root);                          ////adaugat
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
	//conversie();                                      ////eliminat
}

void citire(node*&radacina) //1
{
	root= new node;
	last= new listArb;
	cout<<"\t";
    cout<<"Notatia pentru nodul NULL este '0'"<<endl;
    d.modificat=true;
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

/*int fAdancime( node *aux,int &nivel,int &valMax) //working progress
{
    if(valMax<nivel)
        valMax=nivel;
    if(aux->left!='\0')
    {
        nivel++;
        fAdancime(aux->left,nivel,valMax);
    }
        nivel--;
    if(aux->right!='\0')
    {
        nivel++;
        fAdancime(aux->right,nivel,valMax);
    }
    return valMax;
}
*/

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


void  stMenu() //complet //14
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


void voidNode(short x,short y) //complet //15
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
   cout<<" Linii Ok "<<endl;
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
   cout<<" Afisare Ok !"<<endl;
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
    cout<<" Initializare Ok!"<<endl;
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
    cout<<" Desenare Ok!"<<endl;
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
/*
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

nod *creare_arbore(short &z) ///creeaza arbore pana cand toti fii sunt nuli //preordine
{
    int valoare;
    if(!z)
        cout<<"Numele radacinii este: ";
    else
        cout<<"Informatia nodului cu numarul este: "<<z<<' ';
    z++;
    cin>>valoare;
    nod *arbore=new nod;
    if(valoare!=0)
    {
        arbore->value=valoare;
        arbore->stanga=creare_arbore(z);
        arbore->dreapta=creare_arbore(z);
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
/*
#endif

int main()
{

#ifdef graphicpart

    citire(radacina); //1-8
    afisareArbore(radacina);
    d.modificat=true;
    citire(radacina);
    //coordonate();
    afisareArbore(radacina);
    //`1
    //cout<<endl<<nr(radacina); //9-16
    //getch();
    delay(10000);
#endif
#ifdef library
    short z=0;
    nod *temp;
    cout<<"Se creeaza arborele prin metoda preordine \n";
    nod *q=creare_arbore(z);

    temp=q;

    q=temp;
    cout<<"Parcurgere preordine: \n";
    parcurgePreordine(q);
    cout<<'\n';

    q=temp;
    cout<<"Parcurgere postordine: \n";
    parcurgePostordine(q);
    cout<<'\n';

    q=temp;
    cout<<"Parcurgere inordine: \n";
    parcurgeInordine(q);
    cout<<'\n';

    q=temp;
    cout<<"Parcurgere BFS: \n";
    parcurge_BFS(q);
    cout<<'\n';
#endif // library
    return 0;
}
*/




#endif // BIBIOTECAGRAFICA_H_INCLUDED
