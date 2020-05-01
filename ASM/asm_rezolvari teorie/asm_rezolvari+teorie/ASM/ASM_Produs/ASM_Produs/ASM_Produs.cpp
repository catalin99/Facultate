// ASM_Produs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a,b,prod=0;
__int8 c,d;
int _tmain(int argc, _TCHAR* argv[])
{
	cin>>a;
	cin>>b;
	_asm{ //Adunari repetate
		mov ecx,0; //Total
		mov eax,a;
		mov ebx,b;
	_loop:
		add ecx,eax;
		dec ebx;
		cmp ebx,0; //in zero flag avem 0 daca ebx si 0 sunt egale. Daca nu sunt egale, sarim pe loop.
		jnz _loop;

		mov prod,ecx; //Final
	}
	cout<<prod<<'\n';
}
