//IF

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	int a, b;						//unsigned int a, b;

	/*
	if( a > b){
		//instructiuni if
	}else{
		//instructiuni else
    }
	*/

	_asm {
		MOV eax, a
		MOV ebx, b
		CMP eax, ebx
		JLE _else					//JBE _else
			//instructiuni if
		JMP _end_if
		_else :
			//instructiuni else
		_end_if:
	}

	system("PAUSE");
	return 0;
}