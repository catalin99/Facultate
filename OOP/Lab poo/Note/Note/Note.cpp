// Note.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Student.h"
#include "Studenti.h"
#include <iostream>
using namespace std;
int main()
{

	Studenti noteMatematica = { Student{ "Popescu", 10 } , Student{ "Ionescu", 9 }, Student{ "Georgescu", 8 } };
	Studenti noteFizica = { Student{ "Popescu", 7 }, Student{ "Ionescu" , 6 } , Student{ "Marin" , 4 } };
	//Studenti mediiMatematicaFizica = noteMatematica + noteFizica;
	cout << noteMatematica.stud[0].nume << ' ' << noteMatematica.stud[0].nota;
	//cout << "Georgescu: [Matematica = " << noteMatematica["Georgescu"] << "]     " << endl;
	//cout << "Ionescu : [Fizica = " << noteFizica["Ionescu"] << "]" << endl;

	//for (int tr = 0; tr < mediiMatematicaFizica.GetCount();tr++) {

		//cout << "Student " << mediiMatematicaFizica(tr) << "  Medie " << mediiMatematicaFizica[tr] << endl;
	//}

}