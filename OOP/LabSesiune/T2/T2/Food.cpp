#include "stdafx.h"
#include "Food.h"


Food::Food()
{
	quantity = 0.0f;
}


Food::~Food()
{
}

void Food::setQuantity(float quant)
{
	quantity = quant;
}

string Food::getInfo()
{
	string temp;
	temp = to_string(quantity);
	int a = temp.size();
	while (temp[--a] == '0')
		temp.pop_back();
	return temp + " kg";
}
