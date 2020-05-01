#include "Student.h"

Student::Student()
{
	name = "";
	nota = 0;
}

Student::Student(char* nume, int nota)
{
	
	name = nume;
	this->nota = nota;
	
	//map[nume] = nota;
}

Student::~Student()
{
}

/*
int operator+(Student a, Student b)
{
	return a.nota + b.nota;
}
*/
