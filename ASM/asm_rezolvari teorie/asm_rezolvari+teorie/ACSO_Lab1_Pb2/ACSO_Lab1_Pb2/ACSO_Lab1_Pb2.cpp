// ACSO_Lab1_Pb2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char number;
	number = 140;

	_asm{
		mov cl, number;
		mov bl, 0;
		mov al, 0;
		mov dl, 128;
	_while:
		mov bl, cl;
		and bl, 1;
		cmp bl, 1;
		je _adun;
	_ret:
		shr dl, 1;
		shr cl, 1;
		cmp dl, 0;
		jne _while;
		jmp _fin;
	_adun:
		add al, dl;
		jmp _ret;
	_fin:
		mov number, al;
	}
	if (number != 49)
		printf("Failed! Your result is %d\n", number);
	else
		printf("OK!");
	return 0;
}

