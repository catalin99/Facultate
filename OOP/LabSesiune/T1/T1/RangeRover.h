#include "SUV.h"
#pragma once

class RangeRover:public SUV
{
	int consum;
	string name = "RangeRover";
public:
	RangeRover();
	~RangeRover();
	void setConsum(int x);
	int getConsum(int x);
	string getName();
};

