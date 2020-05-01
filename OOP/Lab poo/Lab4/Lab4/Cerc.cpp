#include "stdafx.h"
#include "Cerc.h"
typedef unsigned int ui;
#pragma warning(disable:4996)

Cerc::Cerc(int raza)
{
	Raza = raza;
}

double Cerc::ComputeArea()
{
	double r;
	r = double(Raza*Raza*3.14159);
	return r;
}

const char* Cerc::GetName()
{
	char *cc = new char[6];
	strcpy(cc, "Cerc:");
	return cc;
}