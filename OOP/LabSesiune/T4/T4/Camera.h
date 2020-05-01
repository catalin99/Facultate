#pragma once
#include "SpatiuInchis.h"
class Camera: public SpatiuInchis
{
	string miros;
	bool lumina;
	string nume;
public:
	Camera(string m, bool lum, string n);
	~Camera();
	void AddSpatiu(SpatiuInchis* i){}
	void PrintInfo();
};

