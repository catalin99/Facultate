#include <iostream>
#include <cstring>
using namespace std;
typedef int dim;
#define MaxElem 100000

bool insertsort(int vect[], int nr)
{
    if(nr==0)
        return 0;
    int i, j, temp;
    for(i=2; i<=nr; i++)
    {
        j=i-1;
        temp=vect[i];
        while((j>=1) && (vect[j]>temp))
        {
            vect[j+1]=vect[j];
            j--;
        }
        if(vect[j+1]!=temp)
            vect[j+1]=temp;
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
    if(!(insertsort(vect, NrElem)))
        cout<<"Vectorul nu are elemente";
    else
    {
        cout<<"Elementele sortate crescator: ";
        for(i=1; i<=NrElem; i++)
            cout<<vect[i]<<" ";
    }
    return 0;
}
