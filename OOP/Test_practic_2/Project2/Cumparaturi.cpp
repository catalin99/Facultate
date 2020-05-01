#include "Cumparaturi.h"



Cumparaturi::Cumparaturi()
{

}

Cumparaturi::Cumparaturi(const char name[20], int canti)
{
	strcpy(nume, name);
	cant = canti;
}


Cumparaturi::~Cumparaturi()
{
}


ostream & operator<<(ostream & output, Cumparaturi & c)
{
	output << c.nume << " " << c.cant << endl;
	return output;
}
