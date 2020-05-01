#include <iostream>
#include <cstring>
using namespace std;
typedef int dim;
#define MaxElem 100000

void insereaza_alKlea(int vect[], int nr, int k)
{
    int j=k;
    bool heap=false;
    while(2*j+1<nr && !heap)
    {
        int z=2*j+1;
        if(z<nr-1 && vect[j]<vect[j+1])
            z=z+1;
        if(vect[j]<vect[z])
        {
            swap(vect[j], vect[z]);
            j=z;
        }
        else
            heap=true;
    }
}

bool heapsort(int vect[], int nr)
{
    if(nr==0)
        return 0;
    for(int i=(nr-1)/2; i>=0; i--)
        insereaza_alKlea(vect, nr, i);
    int r=nr-1;
    while(r>0)
    {
        swap(vect[0], vect[r]);
        insereaza_alKlea(vect, r, 0);
        r--;
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
    if(!(heapsort(vect, NrElem)))
        cout<<"Vectorul nu are elemente";
    else
    {
        cout<<"Elementele sortate crescator: ";
        for(i=1; i<=NrElem; i++)
            cout<<vect[i]<<" ";
    }
    return 0;
}
