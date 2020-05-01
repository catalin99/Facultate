#pragma once
#include "Advertisment.h"
class HouseAdvertisment: virtual public Advertisment
{
	int nrFloors
public:
	HouseAdvertisment();
	~HouseAdvertisment();
	void SetNrFloors(int nr);
};

