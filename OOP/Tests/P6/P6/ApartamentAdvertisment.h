#pragma once
#include "Advertisment.h"
class ApartamentAdvertisment:virtual public Advertisment
{
	int atLevel;
public:
	ApartamentAdvertisment();
	~ApartamentAdvertisment();
	void SetLevel(int lvl);
};

