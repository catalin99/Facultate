#include "stdafx.h"
#include "Cumparaturi.h"
#pragma warning(disable:4996)


Cumparaturi::Cumparaturi()
{
	nume = new char[30];
	nume[0] = '\0';
	cant = 0;
}

Cumparaturi::Cumparaturi(const char* name, int canti)
{
	nume = new char[30];
	strcpy(nume, name);
	cant = canti;
}


Cumparaturi::~Cumparaturi()
{
}


ostream & operator<<(ostream & output, Cumparaturi & c)
{
	output << c.nume << " : " << c.cant<< " , ";
	return output;
}
