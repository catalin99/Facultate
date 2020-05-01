#include "stdafx.h"
#include "Forme.h"


Forme::Forme()
{
}


Forme::~Forme()
{
}

void Forme::Add(Forma * F)
{
	L.push_back(F);
}

void Forme::Paint()
{
	for (auto i : L)
		i->Paint();
}
