#include "stdafx.h"
#include "Dreptunghi.h"


Dreptunghi::Dreptunghi()
{
}


Dreptunghi::~Dreptunghi()
{
}

void Dreptunghi::set(int X, int Y, int LUNGIME, int LATIME)
{
	x = X;
	y = Y;
	lungime = LUNGIME;
	latime = LATIME;
}

void Dreptunghi::Paint()
{
	printf("Dreptunghi(%d,%d,%d,%d)\n", x, y, lungime, latime);
}
