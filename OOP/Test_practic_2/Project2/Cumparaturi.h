#pragma once
#include <iostream>
#include <cstring>

using namespace std;
class Cumparaturi
{
private:
	
public:
	char nume[20];
	int cant;
	Cumparaturi();
	Cumparaturi(const char name[20], int canti);
	friend ostream & operator<< (ostream &output,Cumparaturi &c);
	~Cumparaturi();

};

