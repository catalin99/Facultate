#include "stdafx.h"
#include "ListaCumparaturi.h"
#include <iostream>
#include <vector>

using namespace std;


ListaCumparaturi::ListaCumparaturi()
{
}


ListaCumparaturi::~ListaCumparaturi()
{
}

ListaCumparaturi & ListaCumparaturi::operator+=(Cumparaturi b)
{
	vec.push_back(b);
	return *this;
}

ListaCumparaturi & ListaCumparaturi::operator-=(const char* in)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (!strcmp(in, vec[i].nume))
		{
			vec.erase(vec.begin() + i);
		}
		
	}
	return *this;
}



ListaCumparaturi & ListaCumparaturi::operator|(ListaCumparaturi a)
{
	ListaCumparaturi *newlist=new ListaCumparaturi();
	for (int i = 0; i < vec.size();i++)
		newlist->vec.push_back(vec[i]);
	for (int j = 0; j < a.vec.size(); j++)
	{
		bool status = true;
		for (int k = 0; k < newlist->vec.size(); k++)
			if (!strcmp(newlist->vec[k].nume, a.vec[j].nume))
			{
				newlist->vec[k].cant += a.vec[j].cant;
				status = false;
				break;
			}
		if (status == true)
			newlist->vec.push_back(a.vec[j]);
	}
	return *newlist;
}

/*

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

*/
void ListaCumparaturi::Print()
{
	vector<Cumparaturi> ::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << (*it);
}

