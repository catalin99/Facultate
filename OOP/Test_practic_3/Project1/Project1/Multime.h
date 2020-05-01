#pragma once
#include <initializer_list>
#include <vector>
#include "Punct.h"
class Multime
{
private:
	vector<Punct> vec;
	vector<Punct> mult;
public:
	Multime();
	Multime(initializer_list<Punct>);
	Multime &operator += (Punct punct);
	Multime &operator -= (Punct punct);
	Multime &operator += (Multime m);
	void distanta_maxima_intre_puncte();
	void afisare();
	~Multime();

};

