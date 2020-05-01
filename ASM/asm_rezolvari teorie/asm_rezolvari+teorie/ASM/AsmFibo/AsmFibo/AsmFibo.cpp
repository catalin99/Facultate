// AsmFibo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a[100],n,nn;
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"Introduceti un nr mai mare ca 3 \nn=";
	cin>>n; nn=n;
	_asm{
		mov eax,1;
		mov ebx,1;
		mov ecx,2;
		lea edx,a;
		mov [edx],eax;
		add edx,4;
		mov [edx],ebx;
		add edx,4;
		mov [edx],ecx;
		add edx,4;
		sub n,3;
		
	_while:
		mov eax,ebx;
		mov ebx,ecx;
		mov ecx,0;
		add ecx,eax;
		add ecx,ebx;
		mov [edx],ecx;
		add edx,4;
		dec n;
		cmp n,0;
		jne _while;
	}
	for(int i=0;i<nn;++i) cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}

