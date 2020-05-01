#include <iostream>
#include <cstring>
using namespace std;
typedef int dim;
#define MaxElem 100000

bool sortareperechi(int vect[], int nr)
{
    if (nr<=0)
        return 0;
    unsigned int i, j;
    int copie;
    for(i=1; i<=nr-1; i++)
        for(j=i+1; j<=nr; j++)
            if(vect[i]>vect[j])
            {
                copie=vect[i];
                vect[i]=vect[j];
                vect[j]=copie;
            }
    return 1;
}
int main()
{
    int vect[MaxElem];
    int NrElem;
    cout<<"Introduceti numarul de elemente: ";
    cin>>NrElem;
    unsigned int i;
    cout<<"Introduceti elementele! \n";
    for(i=1; i<=NrElem; i++)
        cin>>vect[i];
    if(!(sortareperechi(vect, NrElem)))
        cout<<"Vectorul nu are elemente";
    else
    {
        cout<<"Elementele sortate crescator: ";
        for(i=1; i<=NrElem; i++)
            cout<<vect[i]<<" ";
    }
    return 0;
}
