#pragma once
class Masina
{
	string name;
public:
	Masina();
	~Masina();
	virtual string getName() {
		return name;
	}
};

