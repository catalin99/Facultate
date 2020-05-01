//suma a+b+c

#include "stdafx.h"
#include <iostream>
using namespace std;

int suma(int, int, int) {
	_asm {
		mov eax, [ebp + 8]	//primul parametru
		add eax, [ebp + 12]	// al II-lea parametru
		add eax, [ebp + 16]	// al III-lea parametru
							//se returneaza prin intermediul registrului EAX
	}
}

int main() {
	int sum,a=10,b=20,c=30;
	_asm {
		push c //se pun pe stiva parametrii in ordine inversa
		push b
		push a
		call suma //apelul procedurii
		add esp, 12 //eliminarea parametrilor de pe stiva
		mov sum,eax
	}
	cout << a << "+" << b << "+" << c << "= " << sum << endl;
	system("PAUSE");
	return 0;
}