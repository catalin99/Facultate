#pragma once
#include "Text.h"
#include "Cuvant.h"
#include "Propozitie.h"
class Paragraf:virtual public Text
{
protected:
	vector<Text*> texte;
public:
	//Paragraf();
	//~Paragraf();
	void Afiseaza();
	void Add(Text* txt);
};

