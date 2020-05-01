#pragma once
#include "Advertisment.h"
class Agency
{
	const char* name;
	vector<Advertisment*> agentie;
public:
	Agency();
	~Agency();
	void AddAdvertisment(Advertisment a);
	void PrintOffers(int minSurface, int maxPrice);
};

