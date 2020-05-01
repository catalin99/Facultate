#pragma once
#include <initializer_list>
#include "Studenti.h"

#pragma warning(disable:4996)
using namespace std;
class Student
{
	char *nume;
	int nota;
public:

	Student();
	Student(const char* b, int grade);
	~Student();
};

