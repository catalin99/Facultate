// ASM_Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a,b,sum;
int _tmain(int argc, _TCHAR* argv[])
{
	cin >> a;
	cin >> b;

	_asm{
		mov eax,a;
		mov ebx,b;
		mov ecx,0;
		add ecx,a;
		add ecx,b;
		mov sum,ecx;
	}
	cout<<sum<<'\n';
	return 0;
}

