#include "stdafx.h"
#include "Opel.h"


Opel::Opel()
{
	capacitate = 0;
	culoare = "NON";
	anFabricatie = 0;
}


Opel::~Opel()
{
}

void Opel::setCapacitate(int x)
{
	capacitate = x;
}

void Opel::setCuloare(string s)
{
	culoare = s;
}

void Opel::SetAnFabricatie(int a)
{
	anFabricatie = a;
}

int Opel::getAnFabricatie()
{
	return anFabricatie;
}

int Opel::getCapacitate()
{
	return capacitate;
}

string Opel::getCuloare()
{
	return culoare;
}

string Opel::getName()
{
	return name;
}
