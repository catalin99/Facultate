#pragma once
class Advertisment
{
	int surface;
	int price;
public:
	Advertisment();
	~Advertisment();
	void SetSurface(int s);
	int GetSurface();
	void SetPrice(int p);
	int GetPrice();
	void PrintInfo();
};

