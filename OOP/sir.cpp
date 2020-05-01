#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

//ifstream f("a.in");
//ofstream g("a.out");
int main()
{
    char s[100];
    char null[2]="";
    int v[1001];
    int i=0, b, j, k;
    FILE *pFile;
    pFile = fopen ("a.in" , "r");
    while(fgets (s , 99 , pFile) != NULL)
    {
        /*
        strcpy(s, null);
        fscanf(pFile,"%s",s); */
        b=atoi(s);
        v[++i]=b;
    }
    for(j=1; j<i; j++)
        for(k=j+1; k<=i; k++)
            if(v[j]>v[k])
                swap(v[j], v[k]);
    for(j=1; j<=i; j++)
        cout<<v[j]<<' ';
        fclose (pFile);
    return 0;
}
