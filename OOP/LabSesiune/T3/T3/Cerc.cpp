#include "stdafx.h"
#include "Cerc.h"


Cerc::Cerc()
{
}


Cerc::~Cerc()
{
}

void Cerc::set(int X, int Y, int RAZA)
{
	x = X;
	y = Y;
	raza = RAZA;
}

void Cerc::Paint()
{
	printf("Cerc(%d,%d,%d)\n", x, y, raza);
}
