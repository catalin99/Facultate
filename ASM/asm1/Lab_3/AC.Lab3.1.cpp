// AC.Lab3.1.cpp : Defines the entry point for the console application.
// AC. LAboratorul 2. Suma a n numere folosind stiva

#include "stdafx.h"
int suma (int n)
{
	_asm
	{
		mov ecx, [ebp+8];
		mov eax,0;
		mov ebx,0;
cat_timp:
		cmp eax,ecx
			ja rez;
			add ebx, eax;
			inc eax;
			jmp cat_timp;
	rez:
			mov eax,ebx;
	
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	scanf("%d", &n);
	printf ("%d",suma (n));
	
	return 0;
}

