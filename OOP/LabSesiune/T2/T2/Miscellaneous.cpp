#include "stdafx.h"
#include "Miscellaneous.h"


Miscellaneous::Miscellaneous()
{
	count = 0;
}


Miscellaneous::~Miscellaneous()
{
}

void Miscellaneous::setCount(int xcount)
{
	count = xcount;
}

string Miscellaneous::getInfo()
{
	string temp;
	temp = to_string(count);
	return temp+" items";
}
