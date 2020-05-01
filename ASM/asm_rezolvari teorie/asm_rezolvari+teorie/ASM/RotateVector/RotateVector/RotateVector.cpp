// RotateVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int v[25], n;
int pos;
void rotateVector(int *v, int pos){
	for (int i = 1; i <= pos; ++i){
		_asm{
			mov eax, v;
			mov ebx, n;
		_while:
			dec ebx;
			add eax, 4;
			cmp ebx, 0;
			jne _while;

			mov ebx, v;
			mov ecx, [ebx];
			mov [eax], ecx; //v[n]=v[0];

			mov ebx, n;
			mov eax, v;
			mov ecx, v;
			add ecx, 4;
		_for:
			mov edx, [ecx];
			mov [eax], edx;
			add eax, 4;
			add ecx, 4;
			dec ebx;
			cmp ebx, 0;
			jne _for;
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	n = 5; pos = 7; for (int i = 1; i <= n; ++i) v[i-1] = i;
	rotateVector(v,pos);
	for (int i = 0; i < n; ++i) cout << v[i] << ' ';
	return 0;
}

