// asmjb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
int n,s,i,k,ok;

cin>>n;

_asm
	{
		mov s,0
		mov i,2
start:	mov ok,1
		mov k,2
start2:	mov ecx,i
		mov edx,0
		mov eax,ecx
		mov ebx,k
		div ebx
		cmp edx,0
		je incr
cond:	mov eax,i
		mov edx,0
		mov ebx,2
		div ebx
		add k,1
		cmp eax,k
		jbe start2
		cmp ok,1
		jne incr
		mov eax,s
		add eax,i
		mov s,eax
		jmp cond
incr:	add i,1
		mov eax,i
		cmp eax,n
		jbe start

}
	cout<<"Suma este "<< s << endl;
	return 0;
}

