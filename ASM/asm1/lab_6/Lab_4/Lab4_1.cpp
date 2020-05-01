// Lab4_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int a[100],n,i;
int suma (int*a, int n)
{ int sum;

_asm
{
	mov eax, 1; //i
	mov ecx, 0; //suma
	mov edx, [ebp+8]; //primul elem din vector
	mov ebx, [ebp+12]; // n
	
cat_timp:
	cmp eax, ebx
		ja rez;
		add ecx, [edx];
		add edx,4;
		inc eax;
		jmp cat_timp;
rez: mov sum, ecx;
}

return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
scanf ("%d", &n);
for (i=0; i<n; i++) scanf ("%d", &a[i]);
	
printf ("%d", suma (a, n));

	return 0;

}

