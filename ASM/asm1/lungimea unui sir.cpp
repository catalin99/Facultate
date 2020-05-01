// asm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

int lungime(char* s){
	int lg;
_asm{
		mov edx,[ebp+8]
		mov eax,0
swhile: cmp byte ptr [edx+eax],'/'
		je final
		inc eax
		jmp swhile
final:	mov lg,eax
}
printf("%d",lg);
return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* x="Ana Are Mere/";
	_asm{
		lea ebx,x
		push ebx
		call lungime
		add esp,4
}
	return 0;
}

