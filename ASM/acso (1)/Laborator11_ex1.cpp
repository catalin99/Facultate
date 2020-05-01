//interschimbati valorile variabilelor a si b

#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	_asm {
		mov eax, [ebp + 8]	//&a
		mov ebx, [ebp + 12]	//&b
		mov ecx, [eax]		//a
		mov edx, [ebx]		//b
		mov[eax], edx
		mov[ebx], ecx
	}
}

void main() {
	int a = 2, b = 3;
	cout << "Before SWAP: a=" << a << " b=" << b << endl;
	swap(&a, &b);
	cout << "After  SWAP: a=" << a << " b=" << b << endl;
	system("pause");
}