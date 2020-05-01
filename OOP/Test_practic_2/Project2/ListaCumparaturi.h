#pragma once
#include "Cumparaturi.h"
#include "vector"
class ListaCumparaturi 
{
private:
	vector<Cumparaturi>vec;
public:
	ListaCumparaturi();
	~ListaCumparaturi();
	ListaCumparaturi &operator+= (Cumparaturi b);
	ListaCumparaturi &operator-= (const char b[20]);
	ListaCumparaturi &operator| (ListaCumparaturi a);
	void Print();
};
