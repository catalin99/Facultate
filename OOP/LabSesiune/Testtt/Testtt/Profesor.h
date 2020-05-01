#pragma once
#include "Students.h"
class Profesor
{
	string nume;
	string materie;
	string tip;
	list<Students* >L;
public:
	Profesor(string n, string m, string t);
	~Profesor();
	void myInfo();
	void AddStudent(Students* x);
};

