// SumVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a[20],n,sum;
int _tmain(int argc, _TCHAR* argv[])
{
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	_asm{
		mov eax,n;
		mov ebx,0;
		lea ecx,a;
	_while:
		add ebx,[ecx];
		add ecx,4;
		dec eax;
		cmp eax,0;
		jne _while;
	done:
		mov sum,ebx;
	}
	cout<<sum;
	return 0;
}

