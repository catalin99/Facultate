#pragma once
#include "Dreptunghi.h"
class DreptunghiRotit: public Dreptunghi
{
	int unghi;
public:
	DreptunghiRotit();
	~DreptunghiRotit();
	void set(int X, int Y, int LUNGIME, int LATIME, int UNGHI);
	void Paint();
};

