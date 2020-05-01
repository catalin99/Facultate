#pragma once
#include "SpatiuInchis.h"
class Casa: public SpatiuInchis
{
	string miros;
	bool lumina;
	string nume;
	list<SpatiuInchis*> L;
	int counter = 0;
public:
	Casa(string m, bool lum, string n);
	~Casa();
	void AddSpatiu(SpatiuInchis *i);
	void PrintInfo();
};

