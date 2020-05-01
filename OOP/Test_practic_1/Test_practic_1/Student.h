#pragma once
#include <initializer_list>
#include <iostream>
#include "map"

using namespace std;

class Student {
public:
	//map <char*, int> map;
	char* name; 
	int nota;
	//friend int operator+(Student, Student);
	Student();
	Student(char* nume, int nota);
	~Student();

};
