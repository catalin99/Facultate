#include<iostream>
using namespace std;
int c;

int cmmdc(int a, int b)
{
	_asm
	{
		mov eax,a
		mov ebx,b
bucla:
		cmp eax,ebx
		je EXIT
		
		cmp eax,ebx
			ja E1
			sub ebx, eax
			jmp bucla
		E1:sub eax,ebx
		jmp bucla
EXIT:
		mov c,eax
	}
	return c;}

int main()
{
	cout<<cmmdc(3,7);
}
