#pragma once
#include "Forma.h"
class Cerc: public Forma
{
	int x;
	int y;
	int raza;
public:
	Cerc();
	~Cerc();
	void set(int X, int Y, int RAZA);
	void Paint();
};

