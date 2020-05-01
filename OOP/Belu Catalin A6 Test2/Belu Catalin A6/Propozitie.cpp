#include "stdafx.h"
#include "Propozitie.h"
#define _CRT_SECURE_NO_WARNINGS
void Propozitie::Afiseaza()
{
	for (auto i : cuvinte)
		cout << i.txt << ' ';
	cout << '.';
}

void Propozitie::AddCuvant(Cuvant cuv)
{
	cuvinte.push_back(cuv);
}

Propozitie::Propozitie(string prop)
{
	char s[50];
	char *next;
	for (int i = 0; i < prop.size(); i++)
	{
		s[i] = prop[i];
		s[i + 1] = '\0';
	}
	char *p = strtok_s(s," ",&next);
	
	while (p)
	{
		//cout << p << endl;
		string temp;
		temp = p;
		cuvinte.push_back(temp);
		//cout << temp << endl;
		p = strtok_s(NULL, " ", &next);
	}
}
