#include "stdafx.h"
#include "Lidl.h"


void Lidl::AddItem(HyperMarket * mc)
{
	L.push_back(mc);
}

void Lidl::Print()
{
	for (auto i : L)
	{
		cout << "Oras: " << i->oras << "; Chirie: " << i->chirie << "; Costuri: " << i->costuri << "; Spatiu: " << i->spatiu << endl;
	}
}

string Lidl::getOras()
{
	return oras;
}

int Lidl::getChirie()
{
	return chirie;
}

int Lidl::getCosturi()
{
	return costuri;
}

int Lidl::getSpatiu()
{
	return spatiu;
}

Lidl::Lidl(string o, int c, int cst, int sp)
{
	oras = o;
	chirie = c;
	costuri = cst;
	spatiu = sp;
}


Lidl::~Lidl()
{
}
