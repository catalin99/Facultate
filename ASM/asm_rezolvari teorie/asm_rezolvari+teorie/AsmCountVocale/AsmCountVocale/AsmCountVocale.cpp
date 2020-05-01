// AsmCountVocale.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
char s[250];
int count(char *s){
	int retu=0;
	_asm{
		mov eax,s;
		mov ebx,0;
	_while:
		cmp [eax],'a';
		je _voc;
		cmp [eax],'e';
		je _voc;
		cmp [eax],'i';
		je _voc;
		cmp [eax],'o';
		je _voc;
		cmp [eax],'u';
		je _voc;
		cmp[eax],'\n';
		je _fin;
		cmp[eax],'$';
		je _fin;
		inc eax;
		jmp _while;
	_voc:
		inc eax;
		inc ebx;
		jmp _while;
	_fin:
		mov retu,ebx;
	}
	return retu;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin>>s;
	cout<<count(s)<<'\n';
	return 0;
}

