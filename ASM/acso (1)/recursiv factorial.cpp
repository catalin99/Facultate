//Calculul factorialului unui numar - recursiv

#include "stdafx.h"
#include <iostream>
using namespace std;

unsigned int fact_rec(unsigned int nr) {
	_asm {
		mov esi, [ebp + 8]		//se pune nr in esi
		cmp esi, 2				//comparare nr cu 2
		jnb apel_recursiv		//Daca nr >= 2, se face saltul, altfel:
		mov eax, 1				// se returneaza 1
		jmp gata				//gata
		apel_recursiv :
		dec esi					// nr-1
			push esi			//punem esi pe stiva
			call fact_rec		//apelam recursiv fact_rec
			add esp, 4			//eax = fact(nr-1)
			mov esi, [ebp + 8]	//esi = nr
			mul esi				//return fact(nr-1)*nr
		gata:
	}
}

int main() {
	int nr=10, fact;
	_asm {
		push nr
		call fact_rec
		add esp, 4
		mov fact, eax
	}
	cout << nr << "!= " << fact << endl;

	system("PAUSE");
	return 0;
}