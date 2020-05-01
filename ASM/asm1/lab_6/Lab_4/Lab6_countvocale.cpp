// Lab6_countvocale.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int countVocale (char *)
{
_asm
	{
	mov eax,0;//i
	mov ebx,[ebp+8];//caracterul pe i
	
cat_timp:
	cmp byte ptr [ebx], 0
		je rez;
	cmp byte ptr [ebx], 'a' // cl in loc de cmp verifica litera mare si mica
		je voc;
	cmp byte ptr [ebx], 'e'
		je voc;
	cmp byte ptr [ebx], 'i'
		je voc;
	cmp byte ptr [ebx], 'o'
		je voc;	
	cmp byte ptr [ebx], 'u'
		je voc;	
	inc ebx;

voc: inc eax;
	 inc ebx;
	 jmp cat_timp;

rez: 
	 

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[100];
	scanf("%s", &s);
	printf ("%d", countVocale(s));
	return 0;
}

