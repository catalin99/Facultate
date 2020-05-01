#include "stdafx.h"
#include "Advertisment.h"


Advertisment::Advertisment()
{
}


Advertisment::~Advertisment()
{
}

void Advertisment::SetSurface(int s)
{
	surface = s;
}

int Advertisment::GetSurface()
{
	return surface;
}

void Advertisment::SetPrice(int p)
{
	price = p;
}

int Advertisment::GetPrice()
{
	return price;
}
