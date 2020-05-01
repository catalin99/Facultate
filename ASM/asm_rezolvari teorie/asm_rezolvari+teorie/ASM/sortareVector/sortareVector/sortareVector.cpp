// sortareVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a[50], n;
void sortare(int *v, int n){
	int i, j;
	_asm{
		mov eax, v;
		mov i, 0;
		mov ecx, i;
		mov j, ecx;
		inc j;
	_for1:
		mov ebx, eax;
		add ebx, 4;
	_for2:
		mov ecx, [eax];
		mov edx, [ebx];
		cmp ecx,edx;
		jg _change;
	_retChange:
		add ebx, 4;
		inc j;
		mov edx, n;
		cmp j, edx;
		jle _for2;

		inc i;
		mov ecx, i;
		mov j, ecx;
		inc j;
		add eax, 4;
		mov edx, n;
		cmp i, edx;
		jne _for1;
		jmp _fin;
	_change:
		mov ecx, [ebx];
		mov edx, [eax];
		mov [eax], ecx;
		mov [ebx], edx;
		jmp _retChange;
	
	_fin:
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sortare(a,n-1);
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';

	return 0;
}

