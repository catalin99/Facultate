// suma_nr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
int n, sum;
scanf ("%d", &n);

_asm
{
	mov eax,0; /nr de adaugat
	mov ebx,0; /suma
cat_timp:

	cmp eax,n
		je rez;
	add ebx,eax;
	inc eax;
	jmp cat_timp;
rez:
	add ebx,eax;
	mov sum, ebx;
}

printf ("%d", sum);

	return 0;
}

