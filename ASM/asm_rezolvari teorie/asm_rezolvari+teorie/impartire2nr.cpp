#include<iostream.h>
int main()
{
	int c;
	_asm{
		mov edx,0
			mov esi,5
			mov eax,11
			div esi
			mov c,eax
	}
	cout<<c;
	return 0;
}