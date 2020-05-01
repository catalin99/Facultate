//Sa se scrie codul in limbaj de asamblare care oglindeste bitii  unui numar

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
	unsigned int number;
	number = 140;
	_asm {
		mov ebx, number		//ebx=number;
		xor eax, eax		//eax=0000 0000 0000 0000 b;
		mov ecx, 0			//ecx=0;
		_loop:
			cmp ecx, 32		//compara ecx cu 32
			jz _done		//la egal sare la _done
			shl eax, 1		//shift left eax
			shr ebx, 1		//shift right ebx
			jnc _next_bit	//jump if not carry la _next_bit
			or eax, 1		//eax=bitwise_or eax,1
		_next_bit:
			inc ecx
			jmp _loop
		_done :
		mov number, eax
	}
	if (number != 822083584)
		cout << "Failed! Your result is: " << number << endl;
	else
		cout << "Ok! Your result is: " << number << endl;
	system("PAUSE");
	return 0;
}