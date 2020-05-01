#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int functvocale(char *, char*)
{
	_asm
	{
		MOV EAX, [EBP + 8]//sirul de caractere
		XOR EDI, EDI//counter sir
		XOR ESI, ESI//numar vocale
		MOV EDX, [EBP + 12]//sir de vocale
		_parcsir:
			MOV BL, [EAX + EDI]//elementul curent din sir
			CMP BL, '\0' //daca elementul e null, se termina forul
			JE _endfunct
				push EDI//retinem counterul sirului nostru
				XOR EDI, EDI
				_parcvocale :
					MOV CL, [EDX + EDI]//elementul curent din sirul de vocale
					CMP CL, '\0'//daca elementul e null inseamna ca nu este vocala
					JE _novocala
						CMP BL, CL//compara elementul din sir cu elementul din sirul vocalelor
						JE _plusvocala//daca sunt egale va creste nr voc
							INC EDI//altfel creste i-ul parcurgerii sirul vocalelor
							JMP _parcvocale//parcurge mai departe sirul vocalelor
						_plusvocala :
						INC ESI//creste nr voc
					_novocala :
					pop EDI//scoate copia din stiva
					INC EDI//creste i-ul pentru sirul nostru
					JMP _parcsir//reia forul
			_endfunct :
			MOV EAX, ESI//muta in eax, numarul de vocale pentru return
	}
}
int main()
{
	char vocale[] = "aeiouAEIOU";
	char s[30];
	//char vocale[15];
	int x = 0;
	//cin.get(vocale, 15);
	//cin.get();
	cin.get(s, 25);
	x = functvocale(s, vocale);
	cout << x << '\n';
	return 0;
}