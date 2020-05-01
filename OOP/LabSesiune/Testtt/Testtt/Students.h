#pragma once
class Students
{
public:
	string nume;
	vector<int> note;
public:
	Students();
	~Students();
	virtual void getInfo() = 0;
};

