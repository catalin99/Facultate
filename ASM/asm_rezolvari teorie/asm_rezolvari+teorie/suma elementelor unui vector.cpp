// asm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
// aduna toate numere dintr-un vector
int suma(int* v, int n){
int x;
_asm{
	mov edx,[ebp+8]
	mov ebx,[ebp+12]
	mov ecx,0
	mov eax,0
sfor:cmp ecx,ebx
	je final
	add eax,[edx+ecx*4]
	inc ecx
	jmp sfor
final:
	mov x, eax
}
printf("%d",x);
return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{ 
	int v[]={0,1,2,3,4};
	_asm{
		push 5
		lea ebx,v
		push ebx
		call suma
		add esp,8
}
	
	return 0;
}

