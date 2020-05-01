#include "stdafx.h"
#include "Materii.h"


Materii::Materii()
{
	nume = new char;
	nume[0] = '\0';
	media = 0;
}

void Materii::Set(float medie)
{
	media = medie;
}

void Materii::GetAll()
{
	cout <<"Media la "<< nume << " este: " << media << '\n';
}

void Materii::NumeMaterie(int i)
{
	switch (i)
	{
	case 0:
		strcpy(nume, "Matematica"); break;
	case 1:
		strcpy(nume, "Romana"); break;
	case 2:
		strcpy(nume, "Engleza"); break;
	case 3:
		strcpy(nume, "Istorie"); break;
	case 4:
		strcpy(nume, "Geografie"); break;
	default:
		strcpy(nume, "no name"); break;
	}

}