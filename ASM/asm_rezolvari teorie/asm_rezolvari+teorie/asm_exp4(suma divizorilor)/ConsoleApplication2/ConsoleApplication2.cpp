#include <iostream>
using namespace std;
//Suma divizorilor unui numar (fara 1 si insasi numarul)
int main()
{
	int a,b,c;
	cin>>a;
	_asm
	{
		mov esi,0
		mov eax,a
		sar eax,1
		mov c,eax
		mov ebx,2
		start_for:
		mov eax,a
		mov edx,0
		div ebx
		cmp edx,0
		jne nu_egal_incrementare
		add esi,ebx
		nu_egal_incrementare:
		cmp ebx,c
		je sfarsit
		inc ebx
		jmp start_for
		sfarsit:
		mov b,esi
	}
	cout<<b<<endl;
}