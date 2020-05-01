#include "Multime.h"
#include <algorithm>


Multime::Multime()
{
}

Multime::Multime(initializer_list<Punct>lista)
{
	for (auto it = lista.begin(); it != lista.end(); it++)
		vec.push_back(*it);
}

Multime & Multime::operator+=(Punct punct)
{
	vec.push_back(punct);
	return *this;
}

Multime & Multime::operator-=(Punct punct)
{
	vec.erase(vec.end() - 1);
	return *this;
}

Multime & Multime::operator+=(Multime m)
{
	int ok = 1;
	vector<Punct>::iterator p;
	for (auto it = this->vec.begin(); it != this->vec.end(); it++)
		mult.push_back(*it);
	for (auto it = m.vec.begin(); it != m.vec.end(); it++)
	{
		ok = 1;
		for (auto it2 = this->vec.begin(); it2 != this->vec.end(); it2++)
			if (((*it).x == (*it2).x) && (*it).y == (*it2).y) ok = 0;
		if(ok == 1)
		mult.push_back(*it);
	}
		

	return *this;

}

void Multime::distanta_maxima_intre_puncte()
{
	double  p, maxi = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		for (auto it2 = vec.begin(); it2 != vec.end(); it2++)
		{
			p = (*it) | (*it2);
			if (p > maxi) {
				maxi = p;
			}
		}
	}
	cout << "Distanta maxima dintre 2 puncte este " << maxi << endl;
}

void Multime::afisare()
{
	for (auto it = mult.begin(); it != mult.end(); it++)
		cout << (*it).x << " " << (*it).y << endl;
}

Multime::~Multime()
{
}
