// ASMTemaVacanta.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include<string.h>
unsigned nrBits(int){
	_asm{
		//returneaza numarul de biti setati in reprezentarea interna a numarului primit ca parametru
		mov ebx, [ebp+8]
		mov eax,0
	_while:
		test ebx,1
		jnz _adun
	_ret:
		shr ebx,1
		cmp ebx,0
		jne _while
		jmp _fin
	_adun:
		inc eax
		jmp _ret
	_fin:
	}
}
unsigned isPrime(int){
	_asm{
		//returneaza 1 daca numarul primit ca parametru este prim, 0 in caz contrar
		mov ebx, [ebp+8]
		mov ecx,2
		cmp ebx,2
		jl _prim
	_while:
		mov eax,ebx
		mov edx,0
		div ecx
		cmp edx,0
		je _notprim
		inc ecx
		cmp ecx,ebx
		jl _while
		jmp _prim
	_prim:
		mov eax,1
		jmp _ret
	_notprim:
		mov eax,0
	_ret:

	}
}
int palindrom(unsigned int){
	_asm{
		//returneaza 1 daca numarul primit ca parametru este palindrom, 0 in caz contrar
		mov esi, [ebp+8]
		mov eax, [ebp+8]
		mov ebx,0
	_while:
		mov edx,0
		mov edi,10
		div edi
		imul ecx,10
		add ecx,edx
		cmp eax,0
		jne _while
		cmp ecx,esi
		je _pali
		mov eax,0
		jmp _ret
	_pali:
		mov eax,1
	_ret:

	}
}
unsigned short powerOf2(int, int*){
	_asm{
		//Se da un vector prin intermediul a doi parametri: primul reprezinta numarul de elemente din vector iar al II-lea este pointer catre primul element din vector.
		//Functia returneaza numarul de elemente din vector - puteri ale lui doi.
		mov ecx, [ebp+8]
		mov esi, [ebp+12]
		mov eax,0
		inc ecx
	_while:
		mov ebx, [esi]
		mov edx,0
		sub edx,ebx
		and ebx,edx
		cmp ebx, [esi]
		je _inc
	_ret:
		add esi,4
		loop _while
		jmp _fin
	_inc:
		inc eax
		jmp _ret
	_fin:

	}
}
int progresie_aritmetica(int, int*){
	_asm{
		//Se da un vector prin intermediul a doi parametri: primul reprezinta numarul de elemente din vector iar al II-lea este pointer catre primul element din vector.
		// Functia retuneaza 1 daca elementele vectorului formeaza o progresie aritmetica, 0 in caz contrar
		mov ecx, [ebp+8]
		mov esi, [ebp+12]
		mov ebx, [esi+4]
		sub ebx, [esi]
		mov eax,1
		dec ecx
	_while:
		mov edx, [esi+4]
		sub edx, [esi]
		cmp edx,ebx
		jne _nu
		add esi,4
		loop _while
		jmp _fin
	_nu:
		mov eax,0
	_fin:

	}
}

int toUpper(char*){
	_asm{
		//Faceti conversia sirului de caractere primit ca parametru, returnand numarul de caractere modificate.
		mov esi, [ebp+8]
		mov eax,0
		mov edx, 32
	_while:
		cmp [esi], 'a'
		jge _z
	_ret:
		add esi,4
		cmp[esi],0
		jne _while
		jmp _fin
	_z:
		cmp[esi], 'z'
		jle _up
		jmp _ret
	_up:
		sub [esi],edx
		inc eax
		jmp _ret
	_fin:

	}
}/*
int nrTok(char*){
	_asm{
		//Sa se returneze numarul de cuvinte din textul primit ca parametru. Separatorii sunt: ',',  ' ',   '.'
	}
}*/

int _tmain(int argc, _TCHAR* argv[])
{
	char *a = "lablaZa dsaZ,a";
	int x = toUpper(a);

	printf("%d%s", x,a);
	return 0;
}
