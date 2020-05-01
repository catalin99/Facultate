#include "stdafx.h"
#include "Studenti.h"


Studenti::Studenti(initializer_list<Student> studi)
{
	initializer_list<Student>::iterator it;
	int i = 0;
	for (it = studi.begin(); it < studi.end(); it++)
	{
		stud[i++] = it;
	}
}


Studenti::~Studenti()
{
}
