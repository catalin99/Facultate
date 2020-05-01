#include "stdafx.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#include <bitset>

//returneaza numarul de biti setati in reprezentarea interna a numarului primit ca parametru
unsigned nrBits(int number) {
	_asm {
		MOV eax, number
		xor ecx,ecx
		_while :
		CMP eax, 0
		JE _end_while
			shr eax, 1
			JNC _else
				inc ecx
			JMP _end_if
			_else :
		_end_if:
			JMP _while
			_end_while :
		mov eax,ecx
	}
}

//returneaza 1 daca numarul primit ca parametru este prim, 0 in caz contrar
unsigned isPrime(int number) {
	_asm {
		mov eax, number				//eax=numar
		cmp eax, 1					//nr=1 => prim
		JNE _else1end
		inc ecx
		JMP _end
		_else1end :
		cmp eax, 2					//nr=2 => prim
		JNE _else2end
		inc ecx
		JMP _end
		_else2end:
		xor ecx,ecx					//ecx=0
		xor edx,edx					//edx=0
		mov ebx,eax					//ebx=numar
		_loop:
			dec ebx					//ebx--, ebx=numar-1
			push eax				//salvam pe stiva eax-ul
			div ebx					//edx eax/ebx=eax(cat) and edx(rest)
			pop eax					//readucem de pe stiva eax-ul=nr
			cmp edx,0				//daca edx=0, eax se imparte exact la ebx=nr nu e prim
			JE _end
			xor edx,edx				//resetam edx
			cmp ebx,2				//ne oprim cand ebx=2
			JNZ _loop				//re-intram in loop
		mov ecx,1					// daca nu se imparte la nimic de la nr-1 la 2, number e prim
		_end:
			mov eax, ecx		//returnam exc
	}
}

//returneaza 1 daca numarul primit ca parametru este palindrom, 0 in caz contrar
int palindrom(unsigned int number) {
	_asm {
		xor esi,esi
		mov ecx,number
		push ecx
		_while:
		pop ecx
		cmp ecx,0
		je _end_while
			mov ebx, 10
			mov eax,ecx
			xor edx, edx
			div ebx		//edx eax/ebx=eax(cat) and edx(rest)
			mov ecx,eax
			push ecx
			push edx
			mov eax,esi
			mov ecx,10
			mul ecx
			pop edx
			add eax,edx
			mov esi,eax
			jmp _while
		_end_while:
			cmp esi,number
			JNE _else
				mov eax,1
				JMP _end_if
			_else:
				mov eax,0
			_end_if:
	}
}

//Se da un vector prin intermediul a doi parametri: primul reprezinta numarul de elemente din vector iar al II-lea este pointer catre primul element din vector.
//Functia returneaza numarul de elemente din vector - puteri ale lui doi.
unsigned short powerOf2(int n, int* a) {
	_asm {
		xor edx,edx				//initializam edx cu 0
		mov ebx, a				//punem adresa lui v[0] in ebx

		xor esi, esi			//initializam esi cu zero
		_for:
		cmp esi,n				//cat timp esi < n
		jge _end_for
			mov eax, [ebx][esi]	//eax=v[i]
			mov ecx,eax
			dec ecx				//ecx=eax-1
			and ecx,eax			//bitwise_and eax,ecx
			cmp ecx,0
			JNE _end_if
			inc edx				//incrementam edx daca eax e putere a lui 2
			_end_if:
			inc esi
		jmp _for
		_end_for:
		mov eax,edx
	}
}


//Se da un vector prin intermediul a doi parametri: primul reprezinta numarul de elemente din vector iar al II-lea este pointer catre primul element din vector.
// Functia retuneaza 1 daca elementele vectorului formeaza o progresie aritmetica, 0 in caz contrar
int progresie_aritmetica(int, int*) {
	_asm {
		
	}
	return 0;
}

//Faceti conversia sirului de caractere primit ca parametru, returnand numarul de caractere modificate.
int toUpper(char*) {
	_asm {
		
	}
	return 0;
}

//Sa se returneze numarul de cuvinte din textul primit ca parametru. Separatorii sunt: ',',  ' ',   '.'
int nrTok(char*) {
	_asm {
		
	}
	return 0;
}

void main() {
	cout << "Problema 1: " << endl;
	for (int i = 1; i < 10; i++) {
		cout << i << ": " << nrBits(i) << " - " << bitset<16>(i) << endl;
	}
	
	cout << endl << "Problema 2: " << endl;
	for (int i = 1; i < 30; i++) {
		int x = isPrime(i);
		if (x == 1) cout << i << ": Prim" << endl;
		else cout << i << ": Nu e deloc prim" << endl;
	}

	cout << endl << "Problema 3: " << endl;
	cout << palindrom(12321) << endl;
	cout << palindrom(12231) << endl;

	cout << endl << "Problema 4: " << endl;
	int v[3] = { 5,2,16 };
	cout << powerOf2(3, &v[0]) << endl;
	system("PAUSE");
}