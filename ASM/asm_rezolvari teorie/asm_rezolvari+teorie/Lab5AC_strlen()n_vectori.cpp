// Lab5AC_strlen()n_vectori.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int strlen (char *s)
{
_asm
{
	
	mov eax,0; //nr de elemente
	mov ecx,[ebp+8]; // caracterul
cat_timp:
	cmp byte ptr [ecx], 0 
		je rez;
		inc eax;
		add ecx,1;
		jmp cat_timp
rez:

}
}

int _tmain(int argc, _TCHAR* argv[])
{

char s[100];
scanf ("%s",&s);


printf("%d", strlen(s));

	return 0;
}

