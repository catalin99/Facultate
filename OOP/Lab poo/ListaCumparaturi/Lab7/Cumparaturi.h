#pragma once
#include <iostream>
#include <cstring>

using namespace std;
class Cumparaturi
{
private:

public:
	char* nume;
	int cant;
	Cumparaturi();
	Cumparaturi(const char* name, int canti);
	friend ostream & operator<< (ostream &output, Cumparaturi &c);
	~Cumparaturi();

};

