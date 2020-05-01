#include "stdafx.h"
#include "Kaufland.h"


void Kaufland::AddItem(HyperMarket * mc)
{
	L.push_back(mc);
}

void Kaufland::Print()
{
	for (auto i : L)
	{
		cout << "Oras: " << i->oras << "; Chirie: " << i->chirie << "; Costuri: " << i->costuri << "; Spatiu: " << i->spatiu << endl;
	}
}

string Kaufland::getOras()
{
	return oras;
}

int Kaufland::getChirie()
{
	return chirie;
}

int Kaufland::getCosturi()
{
	return costuri;
}

int Kaufland::getSpatiu()
{
	return spatiu;
}

Kaufland::Kaufland(string o, int c, int cst, int sp)
{
	oras = o;
	chirie = c;
	costuri = cst;
	spatiu = sp;
}

Kaufland::~Kaufland()
{
}
