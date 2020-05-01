#include "stdafx.h"
#include "Pestera.h"


Pestera::Pestera(string m, bool lum, string n) 
{
	miros = m;
	lumina = lum;
	nume = n;
}

Pestera::~Pestera()
{
}

void Pestera::PrintInfo()
{
	string lum;
	if (lumina)
		lum = "luminos";
	else
		lum = "intunecat";
	for (auto i : L)
		cout << nume << " are " << counter << " camere, miros " << miros << " , "<<lum << '\n';
}

void Pestera::AddSpatiu(SpatiuInchis* i)
{
	L.push_back(i);
	counter++;
}
