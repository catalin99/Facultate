//DO WHILE

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int a, b;				//unsigned int a, b;
	
	/*
	do{
		//instructiuni do while
	}while(a<b);
	*/

	_asm {
		MOV eax, a
		MOV ebx, b
		_do_while :
		//instructiuni do while
		CMP eax, ebx
		JL _do_while		//JB _do_while
	}

	system("PAUSE");
	return 0;
}