#include <iostream>
#include <cstring>

using namespace std;

#pragma pack(3)
class account
{
    private:
        char *nume=new char[200];
        int *v=new int[200];
        short varsta;
        float deposit;
        int x;
    public:
        void name(char b[]);
        void xvarsta(short v);
        void xdeposit(float d);
        void fillvect(int nr);
        void afisare(int nr, ...);
        const int& getx();
        account();
};

const int& account::getx()
{
    x=1;
    return x;
}

void account::name(char b[])
{
    strcpy(this->nume, b);
}

void account::xvarsta(short v)
{
    this->varsta=v;
}

void account::xdeposit(float d)
{
    this->deposit=d;
}

void account::fillvect(int nr)
{
    for(int i=0; i<=nr; i++)
        this->v[i]=i*i;
}

account::account()
{
    strcpy(this->nume, "No name");
    this->varsta=0;
    this->deposit=0;
    this->v[0]=0;
    this->getx();
}

void account::afisare(int nr, ...)
{
    cout<<"Numele persoanei: "<<this->nume<<"\nVarsta persoanei: "<<this->varsta<<"\nSuma de bani depozitata: "<<this->deposit<<" euro \n";
    cout<<"Primele "<<nr<<" numere patrate perfecte: \n";
    for(int i=0; i<=nr; i++)
        cout<<this->v[i]<<' ';
    cout<<'\n';
    cout<<"X = "<<this->x<<'\n';
}

int main()
{
   account pers;
   cout<<"Test initializare date: \n";
   pers.afisare(0); cout<<"Sfarsit test \n";
   char *cc=new char[30];
   short ii;    float ff;   unsigned int nr;
   cout<<"Introduceti numele persoanei! "; cin.getline(cc,29);
   cout<<"Introduceti varsta, apoi banii depozitati: ";
   cin>>ii; cin>>ff;
   cout<<"Cate numere patrate perfecte vreti sa afisati? "; cin>>nr;
   pers.name(cc);
   pers.xvarsta(ii);
   pers.xdeposit(ff);
   pers.fillvect(nr);
   pers.afisare(nr, ii, cc);
   cout<<"Sizeof class: "<<sizeof(account)<<'\n';
   cout<<pers.getx()<<'\n';

}

