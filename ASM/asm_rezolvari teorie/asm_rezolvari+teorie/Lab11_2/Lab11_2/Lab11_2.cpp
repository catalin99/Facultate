// Lab11_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
using namespace std;
int suma_pare_vector(int *,int)
{
	_asm
	{
		mov eax,0
		mov ecx, [ebp+12]
		mov esi, [ebp+8]
	_loop:
		test [esi],1
		jz _adun
	_ret:
		add esi,4
		loop _loop
		jmp _fin
		//completati
	_adun:
		add eax, [esi]
		jmp _ret
	_fin:
		
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int v[5] = { 5, 1, 2, 3, 6 };
	int *p = v;
	int s;
	_asm{
		//completati
		lea ebx,v
		push 5
		push ebx
		call suma_pare_vector
		add esp,8
		mov s,eax
	}
	printf("Suma: %d", s);
	return 0;
}

