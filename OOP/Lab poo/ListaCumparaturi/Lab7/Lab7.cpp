#include "stdafx.h"
#include "ListaCumparaturi.h"
#include "Cumparaturi.h"
int main() {

	ListaCumparaturi L;
	((L += Cumparaturi("paine", 5)) += Cumparaturi("peste", 2)) += Cumparaturi("zahar", 10);
	L.Print();
	cout << '\n';
	L -= "peste";
	L.Print();
	cout << '\n';
	ListaCumparaturi L2;
	(L2 += Cumparaturi("lapte", 4)) += Cumparaturi("paine", -2);
	(L | L2).Print();
	cout << '\n';
	//Operatorul “ | ” relizează reuniunea a doua liste de cumparaturi, iar în cazul elementelor duplicate
		//se aduna valorile corespunzătoare.
	return 0;
}