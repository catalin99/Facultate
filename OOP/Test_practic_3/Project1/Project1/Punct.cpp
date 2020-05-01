#include "Punct.h"
#include <math.h>
Punct::Punct()
{
	x = 0;
	y = 0;
}

Punct::Punct(int x, int y)
{
	this->x = x;
	this->y = y;
}


Punct::~Punct()
{
}

double & operator|(Punct a, Punct b)
{
	double myd= sqrt(pow(b.x - a.x,2) + pow(b.y - a.y,2));
	return myd;
}
