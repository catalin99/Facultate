#pragma once
#include "HyperMarket.h"
class Kaufland: public HyperMarket
{
	//string oras;
	//int chirie;
	//int costuri;
	//int spatiu;
	list<HyperMarket*> L;
public:
	void AddItem(HyperMarket *mc);
	void Print();
	string getOras();
	int getChirie();
	int getCosturi();
	int getSpatiu();
	Kaufland(string o, int c, int cst, int sp);
	~Kaufland();
};
