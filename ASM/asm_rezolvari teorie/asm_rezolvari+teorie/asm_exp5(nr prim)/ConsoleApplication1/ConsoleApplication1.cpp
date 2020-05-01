#include <iostream>
using namespace std;
//Verificarea daca numarul este prim
int main()
{
	int a,b;
	cin>>a;
	b=a/2;

	_asm
	{
		mov ebx,b
		mov ecx,1
	start_while:
		cmp ecx,ebx
		jg finis
		inc ecx
		mov eax,a
		mov edx,0
		div ecx
		cmp edx,0
		jne start_while
		mov eax,1
		jmp finis_1
	finis:
		mov eax,0
		finis_1:
		   mov a,eax
	}
	if (a==1)
		cout<<"Nu este prim"<<endl;
	else cout<<"Este prim"<<endl;


}