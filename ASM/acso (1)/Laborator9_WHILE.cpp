//WHILE

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int a, b;						//unsigned int a, b;

	/*
	while(a<b){
		//instructiuni while
	}
	*/

	_asm {
		MOV eax, a
		MOV ebx, b
		_while :
		CMP eax, ebx
		JGE _end_while				//JAE _end_while
			//instructiuni while
		JMP _while
		_end_while :
	}

	system("PAUSE");
	return 0;
}