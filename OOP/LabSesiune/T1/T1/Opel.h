#pragma once
#include "MasinaOras.h"
class Opel: public MasinaOras
{
	int capacitate;
	string culoare;
	int anFabricatie;
	string name = "Opel";
public:
	Opel();
	~Opel();
	void setCapacitate(int x);
	void setCuloare(string s);
	void SetAnFabricatie(int a);
	int getAnFabricatie();
	int getCapacitate();
	string getCuloare();
	string getName();
};

