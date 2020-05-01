#include <iostream>
using namespace std;

int f(char s[],int n) {
	_asm{
		mov ebx,0
		mov esi,s
		mov edx,0
		mov eax,0
		cmp n,1
		jne E10
		E8:cmp [esi+ebx],32
		je E7
		inc ebx
		inc edx
		mov eax,edx
		jmp E8
E10:    mov ebx,0
		mov esi,s
		mov edx,0
		mov eax,0
		mov ecx,1
E1:     
		cmp [esi+ebx],0
		je E7
		cmp [esi+ebx],32
		jne E3
		inc ecx
		cmp ecx,n
		je E5
		inc ebx
		jmp E1
E3:     
		inc ebx
		jmp E1
E5:     inc ebx
E2:
		cmp [esi+ebx],32
        je E4
		cmp [esi+ebx],0
		je E4
		inc ebx
		inc edx
		jmp E2
E4:
		mov eax,edx
E7:
	}
}

int main() {
	int n,m=0,x;
	char s[100];
	cin.getline(s,100);
	while (m!=6) {
	cout<<"Dati numarul: ";cin>>n;
	_asm{
		push n
        lea ecx,s
		push ecx
		call f
		add esp,8
		mov x,eax
	}
	cout<<"Numarul de caractere: "<<x<<endl;
	m++;
	}
	system("pause>nul");
}