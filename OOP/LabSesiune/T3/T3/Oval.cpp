#include "stdafx.h"
#include "Forma.h"
#include "Oval.h"


Oval::Oval()
{
}


Oval::~Oval()
{
}

void Oval::set(int X, int Y, int RAZA1, int RAZA2)
{
	x = X;
	y = Y;
	raza1 = RAZA1;
	raza2 = RAZA2;
}

void Oval::Paint()
{
	printf("Oval(%d,%d,%d,%d)\n", x, y, raza1, raza2);
}
