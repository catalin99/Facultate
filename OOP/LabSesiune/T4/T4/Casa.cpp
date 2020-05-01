#include "stdafx.h"
#include "Casa.h"

Casa::Casa(string m, bool lum, string n)
{
	miros = m;
	lumina = lum;
	nume = n;
}

Casa::~Casa()
{
}

void Casa::PrintInfo()
{
	string lum;
	if (lumina)
		lum = "luminos";
	else
		lum = "intunecat";
	for (auto i : L)
		cout << nume << " are " << counter << " camere, miros " << miros << " , "<<lum << '\n';
}

void Casa::AddSpatiu(SpatiuInchis *i)
{
	L.push_back(i);
	counter++;
}
