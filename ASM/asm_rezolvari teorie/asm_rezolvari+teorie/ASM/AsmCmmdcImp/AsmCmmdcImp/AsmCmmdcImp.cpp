// AsmCmmdcImp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int a,b;
int cmmdc(int a,int b){
	int ret;
	_asm{
		mov ebx,a;
		mov ecx,b;
	_while:
		mov eax,ebx;
		cdq; //EDX|EAX (concatenate) : b => catul in EAX, restul in EDX. CDQ Face concatenarea
		div b; //eax=eax/ecx, edx=eax%ecx 
		mov ebx,ecx;
		mov ecx,edx;
		mov a,ebx;
		mov b,ecx;
		cmp ecx,0;
		jne _while;
		mov ret,ebx;
	}
	return ret;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin>>a; cin>>b;
	cout<<cmmdc(a,b)<<'\n';
	return 0;
}

