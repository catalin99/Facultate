// Testtt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Students.h"
#include "StudentLaFai.h"
#include "Profesor.h"
#include "StudentScoalaDeSoferi.h"

int main()
{
	int v[] = { 3,4 };
	int f[] = { 22, 21 };
	Profesor a("Marcel", "MATE", "gimnaziu");
	Students *b = new StudentLaFai("Andrei", v);
	Students *c = new StudentScoalaDeSoferi("Gigel", f);

	a.AddStudent(b);
	a.AddStudent(c);
	a.myInfo();
	//a.PrintList();

	return 0;
}

