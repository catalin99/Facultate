#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int putere(int n)
{
    int j; float p=1;
    for (j=1;j<=n;j++)
        p*=10;
    return p;
}


float decodificaDupaVirgula( char nr[100])
{
    char *r;
    double n=0, sute=0, milioane=0, mii=0 , numar;
    int i=0;
    float j;
    r=strtok(nr," ");
    while (r!=NULL)
    {
        if (!strcmp(r,"zero")) i++;
        if (!strcmp(r, "o")) { n=1; i++;};
        if (!strcmp(r, "unu")) { n=n+1; i++;};
        if (!strcmp(r, "un")) { n=1; i++;};
        if (!strcmp(r, "doua")) { n=2; i++;};
        if (!strcmp(r, "doi")) { n=n+2; i++;};
        if (!strcmp(r, "trei")){ n=n+3; i++;};
        if (!strcmp(r, "patru")) { n=n+4; i++;};
        if (!strcmp(r, "cinci")) { n=n+5; i++;};
        if (!strcmp(r, "sase")) { n=n+6; i++;};
        if (!strcmp(r, "sapte")) { n=n+7; i++;};
        if (!strcmp(r, "opt")) { n=n+8; i++;};
        if (!strcmp(r, "noua")) { n=n+9; i++;};
        if (!strcmp(r, "zece")) { n=10; i+=2;};
        if (!strcmp(r, "unsperezece")) { n=11;i+=2;};
        if (!strcmp(r, "doisprezece")) {n=12; i+=2;};
        if (!strcmp(r, "treisprezece")) {n=13; i+=2;};
        if (!strcmp(r, "paisprezece")) {n=14;i+=2;};
        if (!strcmp(r, "cinsprezece")) {n=15; i+=2;};
        if (!strcmp(r, "saisprezece")) {n=16; i+=2;};
        if (!strcmp(r, "saptesprezece")) {n=17;i+=2;};
        if (!strcmp(r, "optisprezece")) {n=18;i+=2;};
        if (!strcmp(r, "nouasprezece") ){n=19;i+=2;};
        if (!strcmp(r, "douazeci") ){n=20; i++;};
        if (!strcmp(r, "treizeci") ) {n=30; i++;};
        if (!strcmp(r, "patruzeci")) {n=40; i++;};
        if (!strcmp(r, "cincizeci")) {n=50; i++;};
        if (!strcmp(r, "saizeci")) {n=60; i++;};
        if (!strcmp(r, "saptezeci")) {n=70;i++;};
        if (!strcmp(r, "optzeci")) {n=80;i++;};
        if (!strcmp(r, "nouazeci")) {n=90;i++;};
        if (!strcmp(r, "sute")) {sute=n*100; n=0;};
        if (!strcmp(r, "suta")) {sute=n*100; n=0;};
        if (!strcmp(r, "mie")) {mii=n*1000; n=0;};
        if (!strcmp(r, "mii")) {mii=mii*1000; n=0;};
        if (!strcmp(r, "milioane")) {milioane=n*1000000; n=0;};
        if (!strcmp(r, "milion")) {milioane=n*1000000; n=0;};
        if (!strcmp(r, "si")) n=n+0;
        if (!strcmp(r, "de")) { mii=sute+n; n=0;}
        r=strtok(NULL," ");
        numar=milioane+mii+sute;
    };
    numar=numar+n;
    j= putere(i);
    numar=numar/j;
    return numar;
};
void decodifica(char nr[200])
{
    char *p ;
    char v[100]="";
    char zak[100];
    double n=0, sute=0, milioane=0, mii=0 , numar;
    int i;
    float c;
    //int z=0;
    strcpy(zak, nr);
    for(int q=0; q<strlen(zak); q++)
    {
        if(zak[q]=='v' && zak[q+1]=='i' && zak[q+4]=='u')
        {
            strcpy(zak, zak+q+8);
            break;
        }
    }
    p=strtok(nr," ");
    //cout<<z++<<' '<<p<<'\n';
    while (p!=NULL)
    {
        if (!strcmp(p,"minus")) i=1;
        if (!strcmp(p,"zero")) n=0;
        if (!strcmp(p, "o")) n=n+1;
        if (!strcmp(p, "unu"))n=n+1;
        if (!strcmp(p, "un")) n=n+1;
        if (!strcmp(p, "doua")) n=n+2;
        if (!strcmp(p, "doi")) n=n+2;
        if (!strcmp(p, "trei")) n=n+3;
        if (!strcmp(p, "patru")) n=n+4;
        if (!strcmp(p, "cinci")) n=n+5;
        if (!strcmp(p, "sase")) n=n+6;
        if (!strcmp(p, "sapte")) n=n+7;
        if (!strcmp(p, "opt")) n=n+8;
        if (!strcmp(p, "noua")) n=n+9;
        if (!strcmp(p, "zece")) n=10;
        if (!strcmp(p, "unsperezece")) n=11;
        if (!strcmp(p, "doisprezece")) n=12;
        if (!strcmp(p, "treisprezece")) n=13;
        if (!strcmp(p, "paisprezece")) n=14;
        if (!strcmp(p, "cinsprezece")) n=15;
        if (!strcmp(p, "saisprezece")) n=16;
        if (!strcmp(p, "saptesprezece")) n=17;
        if (!strcmp(p, "optisprezece")) n=18;
        if (!strcmp(p, "nouasprezece") )n=19;
        if (!strcmp(p, "douazeci") )n=20;
        if (!strcmp(p, "treizeci") )n=30;
        if (!strcmp(p, "patruzeci")) n=40;
        if (!strcmp(p, "cincizeci")) n=50;
        if (!strcmp(p, "saizeci")) n=60;
        if (!strcmp(p, "saptezeci")) n=70;
        if (!strcmp(p, "optzeci")) n=80;
        if (!strcmp(p, "nouazeci")) n=90;
        if (!strcmp(p, "sute")) {sute=n*100; n=0;};
        if (!strcmp(p, "suta")) {sute=n*100; n=0;};
        if (!strcmp(p, "mie")) {mii=n*1000; n=0;};
        if (!strcmp(p, "mii")) {mii=mii*1000; n=0;};
        if (!strcmp(p, "milioane")) {milioane=n*1000000; n=0;};
        if (!strcmp(p, "milion")) {milioane=n*1000000; n=0;};
        if (!strcmp(p, "si")) n=n+0;
        if (!strcmp(p, "de")) { mii=sute+n; n=0;}
        if (!strcmp(p, "virgula"))
        {
            //strcpy(v, p);
            //cout<< p<<endl;
            //p=strtok(NULL, " ");
            c=decodificaDupaVirgula(zak);
            cout<<c<<endl;
        }
        p=strtok(NULL," ");
        //cout<<z++<<' '<<p<<'\n';
        numar=milioane+mii+sute;
    };
    numar=numar+n+c;
    if (i==1) numar*=-1;
    cout<<fixed<<numar;
    return;
}
int main()
{
    char numar[200];
    gets(numar);
    decodifica(numar);
}
