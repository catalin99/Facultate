// Catalog Electronic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Materii.h"
#include "Elev.h"
#pragma warning(disable:4996)

int main()
{
	/*Catalog _10A;
	_10A.SetMedii();
	_10A.AfisareMedieSem();
	_10A.AfisareMedieTotala();*/
	Elev b[20];
	b[0].SetData("Marius", "Dden");
	b[0].Settt();
	b[0].GetttAll();
    return 0;
}

