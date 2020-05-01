#include "stdafx.h"
#include "StudentScoalaDeSoferi.h"



StudentScoalaDeSoferi::StudentScoalaDeSoferi(string NAME, int z[2])
{
	nume = NAME;
	note.push_back(z[0]);
	note.push_back(z[1]);
}

StudentScoalaDeSoferi::~StudentScoalaDeSoferi()
{
}

void StudentScoalaDeSoferi::getInfo()
{
	string var;
	if (note[0] >= 22 && note[1]<21)
		var = "Admis";
	else
		var = "Respins";
	cout << nume << ": note " << note[0] << note[1] << "; " << var << endl;
}
