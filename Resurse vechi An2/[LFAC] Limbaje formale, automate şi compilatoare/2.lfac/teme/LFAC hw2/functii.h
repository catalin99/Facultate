#include<string.h>
char vars[100][100];
int val[100];
int initializat[100];
int variabile=-1;
int max(int a,int b,int c)
{
	if(a>=b&&a>=c) return a;
	else if (b>=a&&b>=c) return b;
	return c;
}
int min(int a,int b,int c)
{
	if(a<=b&&a<=c) return a;
	else if (b<=a&&b<=c) return b;
	return c;
}
void add2(char x[],int v)
{	
	variabile++;
	strcpy(vars[variabile],x);
	initializat[variabile]=1;
	val[variabile]=v;
}
void add1(char x[])
{	variabile++;
	strcpy(vars[variabile],x);
	initializat[variabile]=0;
}
void afis()
{
    int i;
    printf("\nVariabile definite :\n");
    for(i=0;i<=variabile;i++) 
	if(initializat[i])printf("\n %s = %i",vars[i],val[i]);
	else printf("\n %s fara val",vars[i]);
    printf("\n");
}
int declarat(char x[])
{
    int i;
    for(i=0;i<=variabile;i++)
        if(strcmp(x,vars[i])==0) return i;
    return 0;
}
void atribuire(char x[],int v)
{
    int p=declarat(x);
    val[p]=v;
    initializat[p]=1;
}
void printspecial(char x[])
{
    int p=declarat(x);
    printf("\n id %s = %d",vars[p],val[p]);
}