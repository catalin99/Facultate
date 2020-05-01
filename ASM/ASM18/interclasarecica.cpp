#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
using namespace std;

void formarevector(int *, int*, int, int, int*)
{
	_asm
	{
		XOR EDI, EDI // count fin
		MOV EDX, [EBP+24] //vectorul fin
		//vector x // incepe sa puna elementele din vectorul x in vectorul fin
		MOV EAX, [EBP+8]//vector x
		MOV EBX, [EBP+16]//nr elemente x
		XOR ECX, ECX//counter x
		_forx:
			CMP ECX, EBX //compara i-ul pt vect x cu nr elemente din x
				JGE _starty
			MOV ESI, [EAX+4*ECX] //pune in esi elementul curent din vectorul x
			MOV [EDX+4*EDI], ESI //pune pe pozitia curenta din vectorul fin elementul curent din vectorul x
			INC EDI //inc i din fin
			INC ECX //creste i din x
			JMP _forx //reia
		//pune elementele din vectorul y, dupa elementele din vectorul x, in vectorul fin
		//la fel ca la vectorul x:
		_starty:
		MOV EAX, [EBP + 12]//vector y
		MOV EBX, [EBP + 20]//nr elemente y
		XOR ECX, ECX//counter y
		_fory:
			CMP ECX, EBX
				JGE _endfory
				MOV ESI, [EAX+4*ECX]
				MOV[EDX + 4 * EDI], ESI
				INC EDI
				INC ECX
				JMP _fory
		_endfory:
	}
}

int sortare(int *, int)
{
	_asm
	{
		MOV EAX, [EBP + 8] //vectorul
		MOV EBX, [EBP + 12] //numarul de elemente
		XOR ECX, ECX //i
		XOR EDX, EDX //j
		XOR ESI, ESI //aux
		XOR EDI, EDI //pnm..sa fie
		_fori : //forul pentru i
			DEC EBX //scadem 1 din nr de elemente pentru ca i sa mearga pana la n-1
			CMP ECX, EBX // compara i cu n-1 -> daca e mai mare or = iese
			JGE _endfori
			INC EBX //creste ebx inapoi pentru j
			INC ECX	//creste i, pentru ca j pleaca de la i+1
			MOV EDX, ECX //retine in EDX, j-ul (care pleaca de la i+1)
			_forj :
				CMP EDX, EBX//compara j cu n -> daca e mai mare sau egal iese
				JGE _endforj
				MOV ESI, [EAX + 4 * ECX] //retine elementul de pe pozitia i
				MOV EDI, [EAX + 4 * EDX] //retine elementul de pe pozitia j
				CMP	 ESI, EDI //le compara
				JLE _nextop //daca elementul de pe pozitia i <= decat elem de pe poz j
					MOV[EAX + 4 * EDX], ESI //interschimba cele doua elemente
					MOV[EAX + 4 * ECX], EDI //^^
				_nextop :
			INC EDX //creste j
			JMP _forj //reia forul pt j
			_endforj :
		//INC ECX
		JMP _fori //reia forul pentru i
		_endfori : //gata sortareaaa ?
	}
}
int main()
{
	int x[100];
	int y[100];
	int fin[200];
	cout << "Introduceti nr elem x, nr elem y, apoi cei doi vectori" << endl;
	int nx, ny;
	cin >> nx >> ny;
	for (int i = 0; i < nx; i++)
		cin >> x[i];
	for (int j = 0; j < ny; j++)
		cin >> y[j];
	formarevector(x, y, nx, ny, fin);
	cout << "Vectorul format este:" << endl;
	for (int i = 0; i < nx + ny; i++)
		cout << fin[i] << ' ';
	cout << endl;
	sortare(fin, nx+ny);
	cout << "Vectorul sortat este: " << endl;
	for (int i = 0; i < nx + ny; i++)
		cout << fin[i] << ' ';
	cout << endl;

}