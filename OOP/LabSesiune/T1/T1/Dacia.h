#pragma once
#include "MasinaOras.h"
class Dacia: public MasinaOras
{
	int capacitate;
	string culoare;
	string name = "Dacia";
public:
	Dacia();
	~Dacia();
	void setCapacitate(int x);
	void setCuloare(string s);
	int getCapacitate();
	string getCuloare();
	string getName();
};

