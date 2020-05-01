#pragma once
#include "Item.h"
class Food: public Item
{
	float quantity;
public:
	Food();
	~Food();
	void setQuantity(float quant);
	string getInfo();
};

