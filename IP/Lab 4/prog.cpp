#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_ELEM 100
struct matrice
{
    unsigned int nrLinii;
    unsigned int nrColoane;
    int celula[MAX_ELEM][MAX_ELEM];
};

void citeste(matrice &M, char nume)
{
    unsigned int linie, coloana;
    cout<<"Citim matricea "<<nume<<endl;
    cout<<"Dati nr de linii ";
    cin>>M.nrLinii;
    cout<<"Dati nr de coloane ";
    cin>>M.nrColoane;
    for(linie=0; linie<M.nrLinii; linie++)
        for(coloana=0; coloana<M.nrColoane; coloana++)
        {
            cout<<"Dati "<<nume<<"["<<linie<<","<<coloana<<"]=";
            cin>>M.celula[linie][coloana];
        }
}

void aduna(matrice A, matrice B, matrice &C)
{
    unsigned int linie, coloana;
    for(linie=0; linie<A.nrLinii; linie++)
        for(coloana=0; coloana<A.nrColoane; coloana++)
           {
               C.celula[linie][coloana]=B.celula[linie][coloana]+A.celula[linie][coloana];
               //cout<<C.celula[linie][coloana]<<" ";
           }
    C.nrLinii=A.nrLinii;
    C.nrColoane=A.nrColoane;

}
void afiseaza(matrice M, char nume)
{
    unsigned int linie, coloana;
    cout<<"Matricea"<<nume<<"este \n";
    for(linie=0; linie<M.nrLinii; linie++)
    {
        for(coloana=0; coloana<M.nrColoane; coloana++)
        {
            cout<<setw(4);
            cout<<M.celula[linie][coloana];
        }
        cout<<"\n";
    }
}

int main()
{
    matrice A, B, C;
    citeste(A, 'A');
    afiseaza(A, 'A');
    citeste(B, 'B');
    afiseaza(B, 'B');
    if(A.nrLinii!=B.nrLinii || A.nrColoane!=B.nrColoane)
        cout<<"A si B nu se pot aduna";
    else{
        aduna(A, B, C);
        afiseaza(C, 'C');
    }
    return 0;
}

