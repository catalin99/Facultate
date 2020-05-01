// Vacanta_Fact.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int nr, fact;
int fact_rec(int){
	_asm{
		mov ebx, [ebp + 8] 
		cmp ebx,1
		je _done
		mov ecx, ebx
		dec ecx
		push ecx
		call fact_rec
		mov ecx, [esp]
		add esp, 4
		mul ecx
		jmp _fin
	_done:
		mov eax,nr
	_fin:
		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	printf("nr = ");
	//scanf_s("%u", &nr);
	nr = 3;
	_asm{
		//completati
		push nr
		call fact_rec 
		add esp, 4 
		mov fact,eax
	}
	printf_s("%u! = %u\n", nr, fact);
	return 0;
}

