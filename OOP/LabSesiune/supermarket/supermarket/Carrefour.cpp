#include "stdafx.h"
#include "Carrefour.h"


void Carrefour::AddItem(HyperMarket * mc)
{
	L.push_back(mc);
}

void Carrefour::Print()
{
	for (auto i : L)
	{
		cout << "Oras: " << i->oras << "; Chirie: " << i->chirie << "; Costuri: " << i->costuri << "; Spatiu: " << i->spatiu << endl;
	}
}

string Carrefour::getOras()
{
	return oras;
}

int Carrefour::getChirie()
{
	return	chirie;
}

int Carrefour::getCosturi()
{
	return costuri;
}

int Carrefour::getSpatiu()
{
	return spatiu;
}

Carrefour::Carrefour(string o, int c, int cst, int sp)
{
	oras = o;
	chirie = c;
	costuri = cst;
	spatiu = sp;
}


Carrefour::~Carrefour()
{
}
