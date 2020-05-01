#pragma once
#include <iostream>
#include "vector"
#include "Student.h"
#include "initializer_list"

using namespace std;
class Studenti {
private:
	int count;
	int sumaNote;
	
public:
	vector<Student> stud;
	friend Studenti operator+ (Studenti&,Studenti&);
	friend ostream &operator<<(ostream &output, Studenti&);
	int operator[] (int note);
	int operator[] (char nume[20]);
	char* operator() (int note);
	Studenti();
	Studenti(initializer_list<Student>);
	int GetCount();
	~Studenti();

};