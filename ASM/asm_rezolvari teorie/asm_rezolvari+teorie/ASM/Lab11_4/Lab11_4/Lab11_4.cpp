// Lab11_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
using namespace std;

void matrice_unitate(int *, int)
{
	_asm{
		mov edi, [ebp+8]
		mov ecx, [ebp+12]
		dec ecx
		//for (int i = 0; i <= 4; ++i) for (int j = 0; j <= 4; ++j) m[i][j] = 0;
		mov esi,edi
		mov eax,4
		mov ebx,5
		mul ebx
		mul ebx
		sub eax,4
		add esi,eax
	_for:
		mov dword ptr [esi], 0
		sub esi,4
		cmp esi,edi
		jnl _for
		//for(int i=0;i<=4;++i)m[i][i]=1, ca sa fie mai frumos exercitiul
	_loop:
		mov esi,edi
		mov eax,20
		mul ecx
		add esi,eax
		mov eax,4
		mul ecx
		add esi,eax
		mov[esi],1
		dec ecx
		cmp ecx,0
		jnl _loop
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;
	int m[5][5];
	int *p = m[0];
	//for (int i = 0; i <= 4; ++i) for (int j = 0; j <= 4; ++j) m[i][j] = 0;
	_asm
	{
		//completati
		push n
		lea edi,m
		push edi
		call matrice_unitate
		add esp,8
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	return 0;
}

