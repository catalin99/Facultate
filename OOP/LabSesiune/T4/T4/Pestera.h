#pragma once
#include "SpatiuInchis.h"
class Pestera: public SpatiuInchis
{
	string miros;
	bool lumina;
	string nume;
	list<SpatiuInchis*> L;
	int counter = 0;
public:
	Pestera(string m, bool lum, string n);
	~Pestera();
	void AddSpatiu(SpatiuInchis* i);
	void PrintInfo();
};

