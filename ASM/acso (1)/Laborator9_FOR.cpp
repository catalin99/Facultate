//FOR

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	short limit;					//unsigned short limit;

	/*
	for(short i=0;i<limit;i++){
		//instructiuni for
	}
	*/

	_asm {
		MOV dx, limit
		XOR cx, cx					//i=0
		_for :
		CMP cx, dx
		JGE _end_for				//JAE _end_for
			//instructiuni for
		INC cx
		JMP _for
		_end_for :
	}

	system("PAUSE");
	return 0;
}