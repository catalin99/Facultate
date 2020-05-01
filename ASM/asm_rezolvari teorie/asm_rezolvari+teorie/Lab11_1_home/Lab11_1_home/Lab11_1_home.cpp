// Lab11_1_home.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
using namespace std;
void swap(int *a, int *b)
{
	_asm{
		mov eax, [ebp+8] //adresa lui a
		mov ebx, [ebp+12] //adresa lui b
		mov ecx, [eax] //valoarea lui a 
		mov edx, [ebx] //valoarea lui b
		mov [eax],edx //in adresa lui a scriu val lui b si invers
		mov[ebx],ecx
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 2, b = 3;
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

