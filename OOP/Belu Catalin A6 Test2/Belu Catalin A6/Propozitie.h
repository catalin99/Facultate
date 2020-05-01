#pragma once
#include "Text.h"
#include "Cuvant.h"
#define _CRT_SECURE_NO_WARNINGS
class Propozitie: public Text
{
protected:
	vector<Cuvant> cuvinte;
public:
	void Afiseaza();
	void AddCuvant(Cuvant cuv);
	Propozitie(string prop);
};

