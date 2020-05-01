#include "stdafx.h"
#include "Video.h"


Video::Video(string name, int lung)
{
	nume = name;
	lungime = lung;
}

string Video::getName()
{
	return nume;
}

int Video::getLung()
{
	return lungime;
}

void Video::set(string a, int b)
{
	nume += a;
	lungime += b;
}

void Video::init()
{
	nume = "Film: ";
	lungime = 0;
}

ostream & operator<<(ostream & out, Video v)
{
	out << "Film: " << v.nume << " (" << v.lungime << ")" << '\n';
	return out;
}

Video & operator|(Video & unu, Video & doi)
{
	unu.set(doi.getName(), doi.getLung());
	return unu;
}
