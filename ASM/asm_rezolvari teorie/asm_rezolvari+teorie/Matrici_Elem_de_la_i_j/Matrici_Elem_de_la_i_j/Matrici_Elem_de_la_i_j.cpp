// Matrici_Elem_de_la_i_j.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a[32][32], x, y, n;
int caut(int a[32][32], int x, int y){
	int sol;
	_asm{
		mov ebx, a;
		mov eax, x;
		mov ecx, 4;
		mul ecx;
		mov ecx, 32;
		mul ecx;
		add ebx, eax;
		mov eax, y;
		mov ecx, 4;
		mul ecx;
		add ebx, eax;
		mov ecx, [ebx];
		mov sol, ecx;
	}
	return sol;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
	cin >> x >> y;
	cout << caut(a, x, y) << '\n';
	return 0;
}

