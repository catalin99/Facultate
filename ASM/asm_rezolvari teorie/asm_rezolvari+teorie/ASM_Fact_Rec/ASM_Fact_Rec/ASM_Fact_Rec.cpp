// ASM_Fact_Rec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
using namespace std;
unsigned int fact_rec(unsigned int nr){
	_asm{
		//completati
		mov ebx, [ebp+8]
		cmp ebx,0
		je _zero
		mov edx,ebx
		dec edx
		push edx
		call fact_rec
		add esp,4
		pop ecx
		mul ecx
		jmp _fin
	_zero:
		push 1
		mov eax,1
	_fin:
	}
}
/*

	3
*/
int _tmain(int argc, _TCHAR* argv[])
{
	int nr, fact;
	printf("nr = ");
	scanf_s("%u", &nr);
	_asm{
		//completati
		push nr
		call fact_rec
		add esp, 4
		mov fact, eax
		
	}
	printf("%u! = %u", nr, fact);
	return 0;
}

