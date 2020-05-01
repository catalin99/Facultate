// Lab6_matrice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void matrice(int *)
{
	_asm
	{
		mov ebx,0;
		mov ecx,0;
		mov eax, [ebp+8];
cat_timp:
	cmp ebx, 8
		je rez;
	cmp ecx, 8
		je linie_noua; 
		jne valoare;


linie_noua: mov ecx,0; 
		inc ebx; 
		jmp cat_timp;
valoare: 
		cmp ebx, ecx
			je unu;
			jb doi;
			ja trei;
		

unu: mov dword ptr [eax],1; 
			jmp pas;
doi: mov dword  ptr [eax],2; 
			jmp pas;
trei: mov dword  ptr [eax],3; 
			jmp pas;

pas: inc ecx; 
	add eax,4;
	jmp cat_timp;

rez:
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[8][8],i,j;
	
	matrice(&a[0][0]);

	for (i=0;i<8;i++)
	{
		for (j=0; j<8; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

