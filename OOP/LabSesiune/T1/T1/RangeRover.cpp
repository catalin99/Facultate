#include "stdafx.h"
#include "RangeRover.h"


RangeRover::RangeRover()
{
	consum = 0;
}


RangeRover::~RangeRover()
{
}

void RangeRover::setConsum(int x)
{
	consum = x;
}

int RangeRover::getConsum(int x)
{
	return consum;
}

string RangeRover::getName()
{
	return name;
}
