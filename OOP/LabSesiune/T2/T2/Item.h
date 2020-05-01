#pragma once
class Item
{
	string name;
public:
	Item();
	~Item();
	string getName();
	virtual string getInfo()=0;
	void setName(string NAME);
};

