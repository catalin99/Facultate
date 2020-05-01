#include "stdafx.h"
#include "Cuvant.h"


void Cuvant::Afiseaza()
{
	cout << txt;
}

void Cuvant::SetCuvant(string cuv)
{
	txt = cuv;
}

Cuvant::Cuvant(string std)
{
	txt = std;
}
