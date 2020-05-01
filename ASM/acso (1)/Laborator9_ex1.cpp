//Completati exemplul urmator astfel incat functia max sa returneze maximun dintre a si b

#include "stdafx.h"
#include <iostream>
using namespace std;

int max(int a, int b) {
	int maxim=0;
	_asm {
		MOV eax,a
		MOV ebx,b
		CMP eax,ebx
		JLE _else
			MOV maxim,eax
		JMP _end_if
		_else:
			MOV maxim,ebx
		_end_if:
	}
	return maxim;
}

int main() {
	int a=5, b=3;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "MAX(a,b) = " << max(a, b) << endl;
	cout << "----------" << endl;
	a=2;b=7;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "MAX(a,b) = " << max(a, b) << endl;
	cout << "----------" << endl;
	a = 4; b = 4;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "MAX(a,b) = " << max(a, b) << endl;
	system("PAUSE");
	return 0;
}