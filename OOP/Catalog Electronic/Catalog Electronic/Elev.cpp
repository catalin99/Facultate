#include "stdafx.h"
#include "Elev.h"
#include "Materii.h"

Elev::Elev()
{
	nume = new char;
	prenume = new char;
	nume[0] = '\0';
	prenume[0] = '\0';
	MatNames();
	
}

void Elev::SetData(const char* name, const char* pren)
{
	strcpy(nume, name);
	strcpy(prenume, pren);
}

void Elev::MatNames()
{
	for (int i = 0; i <= 4; i++)
		vect[i].NumeMaterie(i);
}
void Elev::Settt()
{
	vect[0].Set(8.f);
	vect[1].Set(5.f);
	vect[2].Set(7.f);
	vect[3].Set(8.f);
	vect[4].Set(10.f);
}

void Elev::GetttAll()
{
	cout << nume << ' ' << prenume << ":\n";
	for (int i = 0; i <= 4; i++)
		vect[i].GetAll();
}