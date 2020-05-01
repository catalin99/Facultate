#include <iostream>
#include <cstring>
using namespace std;
typedef int dim;
#define MaxElem 100000

bool bubblesort(int vect[], int nr)
{
    if(nr<=0)
        return 0;
    char dobubble[10];
    int i;
    int copie;
    do
    {
        strcpy(dobubble, "Nop");
        for(i=1; i<=nr-1; i++)
            if(vect[i]>vect[i+1])
            {
                strcpy(dobubble, "Continua");
                copie=vect[i];
                vect[i]=vect[i+1];
                vect[i+1]=copie;
            }
    }while(!strcmp(dobubble, "Continua"));
    return 1;
}
int main()
{
    int vect[MaxElem];
    int NrElem;
    cin>>NrElem;
    unsigned int i;
    for(i=1; i<=NrElem; i++)
        cin>>vect[i];
    bubblesort(vect, NrElem);
    for(i=1; i<=NrElem; i++)
        cout<<vect[i]<<" ";
    return 0;
}
