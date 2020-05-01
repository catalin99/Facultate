#include <iostream>
#include <cstring>
using namespace std;
typedef long long int lli;
typedef unsigned int ui;
#define dimensiune 15

    //declaratii:
    char c0[]="zero";
    char c1[]="unu";
    char c11[]="o";
    char c2[]="doi";
    char c22[]="doua";
    char c3[]="trei";
    char c4[]="patru";
    char c5[]="cinci";
    char c6[]="sase";
    char c7[]="sapte";
    char c8[]="opt";
    char c9[]="noua";
    char z10[]="zece";
    char z11[]="unsprezece";
    char z12[]="doisprezece";
    char z13[]="treisprezece";
    char z14[]="paisprezece";
    char z15[]="cincisprezece";
    char z16[]="saisprezece";
    char z17[]="saptesprezece";
    char z18[]="optsprezece";
    char z19[]="nouasprezece";
    char z20[]="douazeci";
    char z30[]="treizeci";
    char z40[]="patruzeci";
    char z50[]="cincizeci";
    char z60[]="saizeci";
    char z70[]="saptezeci";
    char z80[]="optzeci";
    char z90[]="nouazeci";
    char ssg[]="osuta";
    char smulti[]="sute";
    char msg[]="omie";
    char mmulti[]="mii";
    char milsg[]="unmilion";
    char milmulti[]="milioane";
    //separatori:
    char de[]="de";
    char si[]="si";

void vector(int vect[], lli numar)
{
    for(int i=9; i>=0; i--)
    {
        vect[i]=numar%10;
        numar/=10;
    }
}
int difzero(int vect[])
{
    for(ui i=0; i<=9; i++)
        if(vect[i]!=0)
            return i;
}

void milioane(ui a, ui b, ui c, char sirmilioane[])
{
    if(a)
    {
        switch(a)
        {
        case 1:
            strcat(sirmilioane, ssg); break;
        case 2:
            strcat(sirmilioane, c22); break;
        case 3:
            strcat(sirmilioane, c3); break;
        case 4:
            strcat(sirmilioane, c4); break;
        case 5:
            strcat(sirmilioane, c5); break;
        case 6:
            strcat(sirmilioane, c6); break;
        case 7:
            strcat(sirmilioane, c7); break;
        case 8:
            strcat(sirmilioane, c8); break;
        case 9:
            strcat(sirmilioane, c9); break;
        }
        if(a>1)
            strcat(sirmilioane, smulti);
    }
    if(b)
    {
    if(b==1)
        switch (c)
        {
        case 0:
            strcat(sirmilioane, z10); break;
        case 1:
            strcat(sirmilioane, z11); break;
        case 2:
            strcat(sirmilioane, z12); break;
        case 3:
            strcat(sirmilioane, z13); break;
        case 4:
            strcat(sirmilioane, z14); break;
        case 5:
            strcat(sirmilioane, z15); break;
        case 6:
            strcat(sirmilioane, z16); break;
        case 7:
            strcat(sirmilioane, z17); break;
        case 8:
            strcat(sirmilioane, z18); break;
        case 9:
            strcat(sirmilioane, z19); break;
        }
    else
        switch(b)
        {
        case 2:
            strcat(sirmilioane, z20); break;
        case 3:
            strcat(sirmilioane, z30); break;
        case 4:
            strcat(sirmilioane, z40); break;
        case 5:
            strcat(sirmilioane, z50); break;
        case 6:
            strcat(sirmilioane, z60); break;
        case 7:
            strcat(sirmilioane, z70); break;
        case 8:
            strcat(sirmilioane, z80); break;
        case 9:
            strcat(sirmilioane, z90); break;
        }
    }
    //if(b>=2)
        //strcat(sirmilioane, de);
    if(b!=1)
    {
        if(c!=0 && b!=0)
            strcat(sirmilioane, si);
        switch (c)
        {
        case 1:
            strcat(sirmilioane, c1);break;
        case 2:
            strcat(sirmilioane, c22);break;
        case 3:
            strcat(sirmilioane, c3);break;
        case 4:
            strcat(sirmilioane, c4);break;
        case 5:
            strcat(sirmilioane, c5);break;
        case 6:
            strcat(sirmilioane, c6);break;
        case 7:
            strcat(sirmilioane, c7);break;
        case 8:
            strcat(sirmilioane, c8);break;
        case 9:
            strcat(sirmilioane, c9);break;
        }
    }
    if(b>0)
    {
        strcat(sirmilioane, de);
        strcat(sirmilioane, milmulti);
    }
    else
        strcat(sirmilioane, "milioane");


}

void mii(ui a, ui b, ui c, char sirmii[])
{
    if(a)
    {
        switch(a)
        {
        case 1:
            strcat(sirmii, ssg); break;
        case 2:
            strcat(sirmii, c22); break;
        case 3:
            strcat(sirmii, c3); break;
        case 4:
            strcat(sirmii, c4); break;
        case 5:
            strcat(sirmii, c5); break;
        case 6:
            strcat(sirmii, c6); break;
        case 7:
            strcat(sirmii, c7); break;
        case 8:
            strcat(sirmii, c8); break;
        case 9:
            strcat(sirmii, c9); break;
        }
        if(a>1)
            strcat(sirmii, smulti);
    }
    if(b)
    {
    if(b==1)
        switch (c)
        {
        case 0:
            strcat(sirmii, z10); break;
        case 1:
            strcat(sirmii, z11); break;
        case 2:
            strcat(sirmii, z12); break;
        case 3:
            strcat(sirmii, z13); break;
        case 4:
            strcat(sirmii, z14); break;
        case 5:
            strcat(sirmii, z15); break;
        case 6:
            strcat(sirmii, z16); break;
        case 7:
            strcat(sirmii, z17); break;
        case 8:
            strcat(sirmii, z18); break;
        case 9:
            strcat(sirmii, z19); break;
        }
    else
        switch(b)
        {
        case 2:
            strcat(sirmii, z20); break;
        case 3:
            strcat(sirmii, z30); break;
        case 4:
            strcat(sirmii, z40); break;
        case 5:
            strcat(sirmii, z50); break;
        case 6:
            strcat(sirmii, z60); break;
        case 7:
            strcat(sirmii, z70); break;
        case 8:
            strcat(sirmii, z80); break;
        case 9:
            strcat(sirmii, z90); break;
        }
    }
    //if(b>=2)
        //strcat(sirmii, de);
    if(b!=1)
    {
        if(c!=0 && b!=0)
            strcat(sirmii, si);
        switch (c)
        {
        case 1:
            strcat(sirmii, c1);break;
        case 2:
            strcat(sirmii, c22);break;
        case 3:
            strcat(sirmii, c3);break;
        case 4:
            strcat(sirmii, c4);break;
        case 5:
            strcat(sirmii, c5);break;
        case 6:
            strcat(sirmii, c6);break;
        case 7:
            strcat(sirmii, c7);break;
        case 8:
            strcat(sirmii, c8);break;
        case 9:
            strcat(sirmii, c9);break;
        }
    }
    if(b>0)
    {
        strcat(sirmii, de);
        strcat(sirmii, mmulti);
    }
    else
        strcat(sirmii, "mii");
}

void sute(ui a, ui b, ui c, char sirsute[])
{
    if(a)
    {
        switch(a)
        {
        case 1:
            strcat(sirsute, ssg); break;
        case 2:
            strcat(sirsute, c22); break;
        case 3:
            strcat(sirsute, c3); break;
        case 4:
            strcat(sirsute, c4); break;
        case 5:
            strcat(sirsute, c5); break;
        case 6:
            strcat(sirsute, c6); break;
        case 7:
            strcat(sirsute, c7); break;
        case 8:
            strcat(sirsute, c8); break;
        case 9:
            strcat(sirsute, c9); break;
        }
        if(a>1)
            strcat(sirsute, smulti);
    }
    if(b)
    {
    if(b==1)
        switch (c)
        {
        case 0:
            strcat(sirsute, z10); break;
        case 1:
            strcat(sirsute, z11); break;
        case 2:
            strcat(sirsute, z12); break;
        case 3:
            strcat(sirsute, z13); break;
        case 4:
            strcat(sirsute, z14); break;
        case 5:
            strcat(sirsute, z15); break;
        case 6:
            strcat(sirsute, z16); break;
        case 7:
            strcat(sirsute, z17); break;
        case 8:
            strcat(sirsute, z18); break;
        case 9:
            strcat(sirsute, z19); break;
        }
    else
        switch(b)
        {
        case 2:
            strcat(sirsute, z20); break;
        case 3:
            strcat(sirsute, z30); break;
        case 4:
            strcat(sirsute, z40); break;
        case 5:
            strcat(sirsute, z50); break;
        case 6:
            strcat(sirsute, z60); break;
        case 7:
            strcat(sirsute, z70); break;
        case 8:
            strcat(sirsute, z80); break;
        case 9:
            strcat(sirsute, z90); break;
        }
    }
    //if(b>=2)
        //strcat(sirmilioane, de);
    if(b!=1)
    {
        if(c!=0 && b!=0)
            strcat(sirsute, si);
        switch (c)
        {
        case 1:
            strcat(sirsute, c1);break;
        case 2:
            strcat(sirsute, c22);break;
        case 3:
            strcat(sirsute, c3);break;
        case 4:
            strcat(sirsute, c4);break;
        case 5:
            strcat(sirsute, c5);break;
        case 6:
            strcat(sirsute, c6);break;
        case 7:
            strcat(sirsute, c7);break;
        case 8:
            strcat(sirsute, c8);break;
        case 9:
            strcat(sirsute, c9);break;
        }
    }

}

int main()
{
    lli numar;
    ui start;
    char sir[200]="";
    char sirmilioane[50]="";
    char sirsute[50]="";
    char sirmii[50]="";
    cin>>numar;
    if (numar==1000)
        strcpy(sir, "omie");
    else if(numar==10000)
        strcpy(sir, "zecemii");
    else
    {
    int vect[dimensiune];
    vector(vect, numar);
    start=difzero(vect);
    if(start!=0)
    {
        if(start>=1 && start<=3)
            start=1;
        else if(start>=4 && start<=6)
            start=2;
        else if(start>=7 && start<=9)
            start=3;
        else start=5;
    }

    switch (start)
    {
        case 0:
            strcat(sir, "unmiliard");
            break;
        case 1:
            milioane(vect[1], vect[2], vect[3], sirmilioane);
            strcat(sir, sirmilioane);
        case 2:
            mii(vect[4], vect[5], vect[6], sirmii);
            strcat(sir, sirmii);
        case 3:
            sute(vect[7], vect[8], vect[9], sirsute);
            strcat(sir, sirsute);
            break;
        default:
            strcat(sir, "zero");
            break;
    }
    }
    cout<<sir;
    return 0;
}
