#include "Studenti.h"


int Studenti::operator[](int contor)
{
	return stud.at(contor).nota;
}

int Studenti::operator[](char nume[20])
{
	vector<Student> ::iterator it;
	for (it = stud.begin(); it != stud.end(); it++)
		if ((*it).name == nume)
			return (*it).nota;
}

char* Studenti::operator()(int contor)
{
		return stud.at(contor).name;
}

Studenti::Studenti()
{
	count = 0;
	//for (auto it = stud.begin(); it != stud.end(); it++)
		//stud.at(it) = new Student();
}

Studenti::Studenti(initializer_list<Student> init)
{
	count = 0;
	for (auto it = init.begin(); it != init.end(); it++,count++)
		stud.push_back(*it);
}
		
int Studenti::GetCount()
{
	return count;
}

Studenti::~Studenti()
{

}

Studenti operator+(Studenti &a,Studenti &b)
{
	Studenti *suma = new Studenti();

	vector<Student>::iterator it;

	for (it = a.stud.begin(); it != a.stud.end(); it++)
		suma->stud.push_back(*it);
	for (it = b.stud.begin(); it != b.stud.end(); it++)
		suma->stud.push_back(*it);
	

	vector<Student>::iterator it2;
	bool updated;

	for (it = a.stud.begin(); it != a.stud.end(); it++)
	{
		updated = false;
		for (it2 = suma->stud.begin(); it2 != suma->stud.end(); it2++)
			if (strcmp(it->name, it2->name) == 0)
			{
				it2->nota += it->nota;
				updated = true;
			}

		if (updated == false)
			suma->stud.push_back(*it);
	}

	for (it = b.stud.begin(); it != b.stud.end(); it++)
	{
		updated = false;
		for (it2 = suma->stud.begin(); it2 != suma->stud.end(); it2++)
			if (strcmp(it->name, it2->name) == 0)
			{
				it2->nota += it->nota;
				updated = true;
			}

		if (updated == false)
			suma->stud.push_back(*it);
	} 
	suma->count = a.count + b.count;
	return *suma;
	
}

ostream & operator<<(ostream & output, Studenti &a)
{
	output << a.count;
	return output;
}
