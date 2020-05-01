// interclasare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
/**
void interclasare(int a[101], int n1, int b[101], int n2, int c[202])
{
	int i = 1, j = 1, k = 1;
	while (i <=n1 && j <=n2)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}
	while (i <=n1)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <=n2)
	{
		c[k] = b[j];
		k++;
		j++;
	}
} **/

void interclasare(int a[101], int n1, int b[101], int n2, int c[202])
{
	_asm
	{
			mov esi,1
			mov edi, 1
			mov edx, 1
			mov eax, [ebp + 8]
			mov ebx, [ebp + 16]
			mov ecx, [ebp + 24]
		start_while:
			cmp esi, [ebp + 12]
			ja exit_while
			cmp edi, [ebp+20]
			ja exit_while
			push ecx
			push edx
			mov ecx, [eax+esi*4]
			mov edx, [ebx+edi*4]
			cmp ecx,edx
			jb int1
			ja int2

		int1:
			pop edx
			pop ecx
			push ebx
			mov ebx, [eax+esi*4]
			mov[ecx + edx * 4],ebx
			pop ebx
			inc edx
			inc esi
			jmp start_while

		int2:
			pop edx
			pop ecx
			push eax
			mov eax, [ebx+edi*4]
			mov[ecx + edx * 4],eax
			pop eax
			inc edx
			inc edi
			jmp start_while

		start_while2:
			cmp esi, [ebp+12]
			ja exit_while2
			push ebx
			mov ebx, [eax+esi*4]
			mov[ecx+edx*4],ebx
			pop ebx
			inc edx
			inc esi
			jmp start_while2

		start_while3:
			cmp edi, [ebp + 20]
				ja exit_while3
				push eax
				mov eax, [ebx+edi*4]
				mov[ecx+edx*4],eax
				pop eax
				inc edx
				inc edi
				jmp start_while3

			exit_while:
				jmp start_while2
				exit_while2:
				jmp start_while3
				exit_while3:
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[101], b[101], c[202], dim;
	int n1, n2, i, j, k;
	cin >> n1;
	for (i = 1; i <= n1; i++)
		cin >> a[i];
	cin >> n2;
	for (j = 1; j <= n2; j++)
		cin >> b[j];
	interclasare(a, n1, b, n2, c);
	dim = n1 + n2;
	for (k = 1; k <= dim;k++)
		cout << c[k];
	return 0;
}

