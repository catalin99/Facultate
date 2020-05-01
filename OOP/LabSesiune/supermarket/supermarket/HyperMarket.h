#pragma once
class HyperMarket
{
public:
	string oras;
	int chirie;
	int costuri;
	int spatiu;
public:
	HyperMarket();
	~HyperMarket();
	virtual void AddItem(HyperMarket *mc) = 0;
	virtual void Print()=0;
};

