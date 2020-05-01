#include<string.h>

struct variabila{
	int valoare;
	char nume[100];
	int initializat;
};

struct variabila variabile[100];
int contor=0;
char buffer[3000]="";

int maxim(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int minim(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int modul(int a)
{
	if(a<0)
		return (-a);
	else
		return a;
}

int cmmdc(int a,int b)
{
	while(a!=b)
	if(a>b) a=a-b;
		else b=b-a;
	return b;
}

int cmmmc(int a, int b)
{
	int rez;
	rez = a*b / cmmdc(a,b);
	return rez;
}

void decl_cu_init(char x[],int v)
{	
	strcpy(variabile[contor].nume,x);
	variabile[contor].initializat=1;
	variabile[contor].valoare=v;
	contor++;
}
void decl_fara_init(char x[])
{
	strcpy(variabile[contor].nume,x);
	variabile[contor].initializat=0;
	contor++;
}
int declarat(char x[])
{
    int i;
    for(i=0;i<=contor;i++)
        if(strcmp(x,variabile[i].nume)==0) return i;
    return -1;
}
void atribuire(char x[],int v)
{
    int p=declarat(x);
    variabile[p].valoare=v;
    variabile[p].initializat=1;
}

int initializat(char x[])
{
    int i;
    for(i=0;i<=contor;i++)
        if(strcmp(x,variabile[i].nume)==0) 
        	if(variabile[i].initializat==0)
        		 return 0;
        	else return 1;
    return 0;
}

void scrie_buffer_int(int intreg)
{
	char buffer1[30];
	sprintf(buffer1,"%d",intreg);
	strcat(buffer,buffer1);
	strcat(buffer,"\n");
}

void scrie_buffer(char afisare[])
{
	strcat(buffer,afisare);
}

void printspecial(char x[])
{
    int p=declarat(x);
    scrie_buffer("\n id ");
    scrie_buffer(variabile[p].nume);
    scrie_buffer(" = ");
    scrie_buffer_int(variabile[p].valoare);
    scrie_buffer("\n");
}