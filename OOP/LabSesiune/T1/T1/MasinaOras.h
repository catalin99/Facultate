#pragma once
#include "Masina.h"
class MasinaOras: public Masina
{
	int capacitate;
	string culoare;
	string name="Masina de oras";
public:
	MasinaOras();
	~MasinaOras();
	virtual int getCapacitate() {
		return capacitate;
	}
	virtual string getCuloare()
	{
		return culoare;
	}
	virtual string getName()
	{
		return name;
	}
};

