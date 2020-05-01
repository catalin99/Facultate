// Lab11_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
using namespace std;
//Determinati numarul de vocale dintr-un sir de caractere
int lungime(char *)
{
	_asm{
		//completati
		mov esi, [esp+8]
		mov eax,0
	_loop:
		cmp[esi], 'a'
		je _vocala
		cmp[esi], 'e'
		je _vocala
		cmp[esi], 'i'
		je _vocala
		cmp[esi], 'o'
		je _vocala
		cmp[esi], 'u'
		je _vocala
	_ret :
		inc esi
		cmp[esi],0
		jne _loop
		jmp _fin
	_vocala:
		inc eax
		jmp _ret
	_fin:

	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *sir = "Numarul de vocale";
	int l;

	_asm{
		mov ebx,sir
		push ebx
		call lungime
		add esp,4
		mov l,eax
	}
	printf("Numarul de vocale este: %d\n", l);
	return 0;
}

