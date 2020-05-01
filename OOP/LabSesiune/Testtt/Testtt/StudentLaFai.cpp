#include "stdafx.h"
#include "StudentLaFai.h"



StudentLaFai::StudentLaFai(string NAME, int z[2])
{
	nume = NAME;
	note.push_back(z[0]);
	note.push_back(z[1]);
}

StudentLaFai::~StudentLaFai()
{
}

void StudentLaFai::getInfo()
{
	int medie = (note[0] + note[1]) / 2;
	string var;
	if (medie >= 5)
		var = "Trecut";
	else
		var = "Picat";
	cout << nume << ": note " << note[0] << note[1] << "; " << var << endl;
}
