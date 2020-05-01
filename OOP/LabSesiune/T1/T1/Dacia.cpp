#include "stdafx.h"
#include "Dacia.h"


Dacia::Dacia()
{
	capacitate = 0;
	culoare = "NON";
}


Dacia::~Dacia()
{
}

void Dacia::setCapacitate(int x)
{
	capacitate = x;
}

void Dacia::setCuloare(string s)
{
	culoare = s;
}

int Dacia::getCapacitate()
{
	return capacitate;
}

string Dacia::getCuloare()
{
	return culoare;
}

string Dacia::getName()
{
	return name;
}
