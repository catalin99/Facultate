#include "stdafx.h"
#include "Dreptunghi.h"
typedef unsigned int ui;
#pragma warning(disable:4996)


Dreptunghi::Dreptunghi(int lungime, int latime)
{
	Lungime = lungime;
	Latime = latime;
	//cout << "Constructorul clasei <Dreptunghi> a fost apelat \n";
}

double Dreptunghi::ComputeArea()
{
	//cout << "Compute Area @Dreptunghi : Complete \n";
	double area = 0;
	area = double(Lungime*Latime) / 2;
	return area;
}

const char* Dreptunghi::GetName()
{
	char *dd = new char[15];
	strcpy(dd, "Dreptunghi:");
	return dd;
}