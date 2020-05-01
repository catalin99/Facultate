#include <iostream>
using namespace std;
//Numar prim prin functie
int prim(int a,int b)
{
	_asm
	{
		mov ebx,[ebp+12]
		mov ecx,2
	start_while:
		cmp ecx,ebx
		jg finis
		mov eax,[ebp+8]
		mov edx,0
		div ecx
		inc ecx
		cmp edx,0
		jne start_while
		mov eax,1
		jmp finis_1
	finis:
		mov eax,0
		finis_1:
	}
}

int main()
{
int a,b;
cin>>a;
b=a/2;
_asm
{
	push b
	push a
	call prim
	add esp,8
	mov a,eax
}
if (a==1)
cout<<"nu este prim"<<endl;
else
cout<<"este prim"<<endl;
}