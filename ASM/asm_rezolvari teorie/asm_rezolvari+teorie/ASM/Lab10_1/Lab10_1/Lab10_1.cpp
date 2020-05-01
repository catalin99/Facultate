// Lab10_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int nr, sol;
int f(int){
	_asm{
		mov ebx,2
		mov eax,1
		mov ecx,[ebp+8]
	_loop:
		mul ebx
		push eax
		add ebx,2
		loop _loop
		
		mov ebx,0
		mov ecx, [ebp+8]
	_loop2:
		pop ebx
		add ebx,eax
		loop _loop2
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cin >> nr;
	_asm{
		push nr
		call f
		add esp,4
		mov sol,eax
	}
	cout << sol;
	return 0;
}

/*
Sa se scrie o functie f(int n) ce primeste ca parametru variabila int n si returneaza rezultatul calculului:
2 + 2*4 + 2*4*6 + 2*4*6*8 + … +2*4*6*8*…*2n.
Functia trebuie sa fie apelata din limbaj de asamblare.
*/