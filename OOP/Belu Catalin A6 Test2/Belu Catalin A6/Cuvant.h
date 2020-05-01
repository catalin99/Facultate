#pragma once
#include "Text.h"
class Cuvant: public Text
{
public:
	string txt;
public:
	void Afiseaza();
	void SetCuvant(string cuv);
	Cuvant(string std);
};

