#pragma once
#include "Students.h"
class StudentScoalaDeSoferi: public Students
{
public:
	StudentScoalaDeSoferi(string NAME, int v[2]);
	~StudentScoalaDeSoferi();
	void getInfo();
};

