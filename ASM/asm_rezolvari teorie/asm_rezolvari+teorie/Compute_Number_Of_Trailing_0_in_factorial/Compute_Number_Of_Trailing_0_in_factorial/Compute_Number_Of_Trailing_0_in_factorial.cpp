// Compute_Number_Of_Trailing_0_in_factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int n;
int trailing(int n){
	int nr = 0;
	_asm{
		mov ebx, 5;
	_while:
		cdq;
		mov eax, n;
		mov edx, 0;
		div ebx;
		add nr, eax;
		imul ebx, 5;
		cmp ebx, n;
		jle _while;
	}
	return nr;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin >> n;
	cout << trailing(n) << '\n';
	return 0;
}

