#pragma once
#include "Materii.h"
#pragma warning(disable:4996)
class Elev
{
	char* nume;
	char* prenume;
	Materii vect[5];

public:
	Elev();
	void SetData(const char *name,const char *pren);
	void MatNames();
	void Settt();
	void GetttAll();
};

