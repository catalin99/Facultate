// Lab11_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
void swap(int *, int *)
{
	_asm{
		//completati
		mov eax, [ebp+8]
		mov ebx, [ebp+12]
		mov ecx, [eax]
		mov edx, [ebx]
		mov [eax], edx
		mov [ebx], ecx
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 2, b = 3;
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

