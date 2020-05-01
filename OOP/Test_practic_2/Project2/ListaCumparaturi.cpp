#include "ListaCumparaturi.h"
#include <iostream>

using namespace std;


ListaCumparaturi::ListaCumparaturi()
{
}


ListaCumparaturi::~ListaCumparaturi()
{
}

ListaCumparaturi & ListaCumparaturi::operator+=(Cumparaturi b)
{
	this->vec.push_back(b);
	return *this;
}

ListaCumparaturi & ListaCumparaturi::operator-=(const char b[20])
{
	
	this->vec.erase(vec.end() - 1);
	return *this;
}

ListaCumparaturi & ListaCumparaturi::operator|(ListaCumparaturi a)
{
	ListaCumparaturi *lista = new ListaCumparaturi();
	vector<Cumparaturi>::iterator it;
	for (it = this->vec.begin(); it != this->vec.end(); ++it)
		lista->vec.push_back(*it);

	vector<Cumparaturi>::iterator it2;
	for (it2 = a.vec.begin(); it2 != a.vec.end(); ++it2)
		lista->vec.push_back(*it2);

	return *lista;

}


void ListaCumparaturi::Print()
{
	vector<Cumparaturi> ::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << (*it);
}

