// AsmTestPrim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a,d,ok=0;
int _tmain(int argc, _TCHAR* argv[])
{
	cin>>a;
	_asm{
		mov ebx,a;
		mov ecx,2;
		mov edx,0;
	_while:
		mov eax,ebx;
		cdq;
		div ecx;
		cmp edx,0;
		je _not_prim;
		inc ecx;
		cmp ecx,ebx-1;
		je _fin;
		jmp _while;
		jmp _fin;
	_not_prim:
		mov ok,1;
		mov d,ecx;
	_fin:
		;
	}
	if(ok==1) cout<<"Numarul "<<a<<" nu este prim intrucat se divide prin "<<d<<'\n';
	else cout<<"Numarul "<<a<<" este prim\n";
	return 0;
}

