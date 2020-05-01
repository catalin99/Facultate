#include "stdafx.h"
#include "Student.h"


Student::Student()
{
	nume[0] = '\0';
	nota = 0;
}

Student::Student(const char* b, int grade) : nume(b), nota(grade)
{
}

Student::~Student()
{
}
