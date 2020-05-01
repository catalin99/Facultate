#pragma once
#include <iostream>

using namespace std;

class Punct
{
private: 
	
public:
	int x;
	int y;
	Punct();
	Punct(int x, int y);
	friend double &operator| (Punct a, Punct b);
	~Punct();
};

