// AsmCmmdcScaderi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a,b;
int cmmdc(int a,int b){
	_asm{
		mov eax,a;
		mov ebx,b;
		cmp eax,ebx;
		je _fin;
	_while:
		cmp eax,ebx;
		jg _ab;
		jl _ba;
	_ret:
		cmp eax,ebx;
		jne _while;
		jmp _fin;
	_ab:
		sub eax,ebx;
		jmp _ret;
	_ba:
		sub ebx,eax;
		jmp _ret;
	_fin:
		mov a,eax;
	}
	return a;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin>>a; cin>>b;
	cout<<cmmdc(a,b)<<'\n';
	return 0;
}

