#pragma once
#include "Forma.h"
class Dreptunghi: public Forma
{
public:
	int x;
	int y;
	int lungime;
	int latime;
public:
	Dreptunghi();
	~Dreptunghi();
	void set(int X, int Y, int LUNGIME, int LATIME);
	void Paint();
};

