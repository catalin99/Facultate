#pragma once
#include "HyperMarket.h"
class Carrefour:public HyperMarket 
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
	Carrefour(string o, int c, int cst, int sp);
	~Carrefour();
};

