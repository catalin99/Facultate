#pragma once
#include "Forma.h"
class Oval:public Forma
{
	int x;
	int y;
	int raza1;
	int raza2;
public:
	Oval();
	~Oval();
	void set(int X, int Y, int RAZA1, int RAZA2);
	void Paint();
};

