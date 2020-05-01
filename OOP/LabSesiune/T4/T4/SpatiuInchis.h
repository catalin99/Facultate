#pragma once
class SpatiuInchis
{
public:
	SpatiuInchis();
	~SpatiuInchis();
	virtual void AddSpatiu(SpatiuInchis* Sp)=0;
	virtual void PrintInfo()=0;
};

