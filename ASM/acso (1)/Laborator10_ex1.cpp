//Sa se scrie o functie f(int n) ce primeste ca parametru variabila int n si returneaza rezultatul calculului
//2 + 2 * 4 + 2 * 4 * 6 + 2 * 4 * 6 * 8 + … + 2 * 4 * 6 * 8 * … * 2n.
//Functia trebuie sa fie apelata din limbaj de asamblare.

#include "stdafx.h"
#include <iostream>
using namespace std;

int f(int n) {
	_asm {
		mov esi, [ebp + 8]	//esi=n
		mov ecx, 1			//ecx=1; counter
		xor edi, edi		//rezultat final
		mov eax, 1			//factorial
		_while:
			cmp ecx, esi
			jg gata
			mul ecx			//factorial* counter
			add edi, eax	//noul rezultat partial
			inc ecx
			jmp _while
		gata :
			mov eax, edi
			shl eax, 1
	}
}

int main() {
	int n=5;
	cout <<n << ": " << f(n) << endl;
	system("PAUSE");
	return 0;
}