#include "stdafx.h"
#include "DreptunghiRotit.h"


DreptunghiRotit::DreptunghiRotit()
{
}


DreptunghiRotit::~DreptunghiRotit()
{
}

void DreptunghiRotit::set(int X, int Y, int LUNGIME, int LATIME, int UNGHI)
{
	x = X;
	y = Y;
	lungime = LUNGIME;
	latime = LATIME;
	unghi = UNGHI;
}

void DreptunghiRotit::Paint()
{
	printf("Dreptunghi(%d,%d,%d,%d) rotit la %d grade\n", x, y, lungime, latime, unghi);
}
