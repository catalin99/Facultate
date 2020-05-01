#include <iostream>
using namespace std;
typedef unsigned int ui;
struct nod
{
    int elt;
    nod*succ;
};

void citire (nod*&L, ui &n)
{
	int i, x;
	nod *p;
	cout<<"n="; cin>>n;;
	L=NULL;
	for(i=1; i<=n; i++)
	{
		cout<<"dati elem nr "<<i<<":";
		cin>>x;
		p=new nod;
		p->elt=x;
		p->succ=L;
		L=p;
	}
}
void afisare (nod *L)
{
	nod *p;
	p=L;
	while(p!=NULL)
	{
		cout<<p->elt<<";";
		p=p->succ;
	}
	cout<<endl;
}
int main()
{
    ui n;
	nod *L;
	citire(L, n);
	afisare(L);
	return 0;
}
