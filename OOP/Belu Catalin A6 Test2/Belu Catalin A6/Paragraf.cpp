#include "stdafx.h"
#include "Paragraf.h"



void Paragraf::Afiseaza()
{
	for (auto i : texte)
	{
		i->Afiseaza();
	}
}

void Paragraf::Add(Text * txt)
{
	texte.push_back(txt);
}
