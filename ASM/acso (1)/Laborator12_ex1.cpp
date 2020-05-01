//Construiti matricea unitate (1 pe diagonala, 0 in rest)

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Str1 {
	char c;
	short s;
	int i;
};

struct Str2 {
	char c;
	int i;
	short s;
};

void generate(char, short, int, Str1*)
{
	_asm {
		mov esi, [ebp + 20]
		mov eax, [ebp + 16]
		mov[esi + 4], eax
		mov ax, [ebp + 12]
		mov[esi + 2], ax
		mov al, [ebp + 8]
		mov[esi], al
	}
}

void generate_2(char, short, int, Str2*)
{
	_asm {
		mov esi, [ebp + 20]
		mov eax, [ebp + 16]
		mov[esi + 4], eax
		mov ax, [ebp + 12]
		mov[esi + 8], ax
		mov al, [ebp + 8]
		mov[esi], al
	}
}

void main() {
	Str1* s1 = new Str1;
	Str2* s2 = new Str2;
	_asm {
		push s1
		push 4
		push 3
		push 'a'
		call generate
		add esp, 16
		push s2
		push 2
		push 1
		push 'b'
		call generate_2
		add esp, 16
	}
	cout << s1->i << s1->s << s1->c << endl;
	cout << s2->i << s2->s << s2->c << endl;
	system("pause");
}