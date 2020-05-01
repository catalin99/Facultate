#pragma once
#include "Masina.h"
class SUV: public Masina
{
	int consum;
	string name = "SUV";
public:
	SUV();
	~SUV();
	virtual int getConsum() {
		return consum;
	}
	virtual string getName()
	{
		return name;
	}
};

