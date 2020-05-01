#include "stdafx.h"
#include "Profesor.h"




Profesor::Profesor(string n, string m, string t)
{
	nume = n;
	materie = m;
	tip = t;
}

Profesor::~Profesor()
{
}

void Profesor::myInfo()
{
	cout << "Date profesor: " << nume << ' ' << materie << ' ' << tip << endl;
	for (auto i : L)
	{
		cout << i->nume <<" "<< i->note[0] <<" "<< i->note[1] << endl;
	}
}

void Profesor::AddStudent(Students * x)
{
	L.push_back(x);
}
