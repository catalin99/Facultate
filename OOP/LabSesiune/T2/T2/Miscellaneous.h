#pragma once
#include "Item.h"
class Miscellaneous: public Item
{
	int count;
public:
	Miscellaneous();
	~Miscellaneous();
	void setCount(int xcount);
	string getInfo();
};

