#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define newline f1();
void f1()
{
	cout << '\n';
}

int prim(int)
{
	int a = 2;
	_asm
	{
		MOV EBX, [EBP + 8] //numar
		CMP EBX, 1
		JE _neprim
		MOV ECX, a//contor
		_for :
		MOV EAX, EBX //numar
			CMP ECX, EAX //contor>=numar
			JGE _stopfor
			XOR EDX, EDX //intializam restul cu 0
			DIV ECX //impartim numarul la contor
			CMP EDX, 0
			JE _neprim //daca nu avem rest, numarul nu este prim
			INC ECX //creste contorul
			JMP _for
			_stopfor :
		MOV EAX, 1 //numar prim
			JMP _fin
			_neprim : //numar neprim
		MOV EAX, 0
			_fin :
	}
}

int suma(int *, int)
{

	_asm
	{
		MOV EBX, [EBP + 8] //vectorul
		MOV ESI, [EBP + 12] //nr elemente
		XOR EDI, EDI //counter
		MOV EDX, 0 //suma
		_for:
		CMP EDI, ESI //daca counterul depaseste numarul de elemente iese
			JGE _endfor
			MOV ECX, [EBX + 4 * EDI] //muta in ebx elementul curent
									 //face copii ale registrilor in stiva
			push EBX
			push ESI
			push EDI
			PUSH EDX
			push ECX  //elementul pe care il foloseste functia prim
			call prim
			pop ECX
			pop EDX
			pop EDI
			pop ESI
			pop EBX
			//scoate copiile din stiva ^^^^
			CMP EAX, 1//daca prim != 1 nu face suma
			JNE _nothing
			ADD EDX, ECX
			_nothing :
		INC EDI
			JMP _for
			_endfor :
		MOV EAX, EDX
	}
}
int main()
{
	int v[100];
	int n, vprim = 0;
	cout << "Introduceti n \n";
	cin >> n;
	cout << "Introduceti elementele vectorului \n";
	//vprim = prim(n);
	/*if (vprim)
	cout << "prim";
	else
	cout << "neprim"; */
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << "Suma elementelor prime din vector este: ";
	cout << suma(v, n);
	newline;
	system("Pause");

}