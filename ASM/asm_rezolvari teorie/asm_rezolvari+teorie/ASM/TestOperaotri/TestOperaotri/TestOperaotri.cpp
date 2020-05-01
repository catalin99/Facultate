// TestOperaotri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 6, b = 5;
	_asm{
		mov eax, b;
		imul eax, a,b;
		mov b, eax;
	}
	cout << b;
	return 0;
}

