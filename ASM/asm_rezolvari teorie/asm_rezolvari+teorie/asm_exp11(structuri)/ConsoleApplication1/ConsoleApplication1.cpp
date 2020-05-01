// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

struct test
{
	char x;
	int y;
	short z;
	int z;
};

void set_struct(test* a)
{
	_asm
	{
		mov eax,[ebp+8]
	    mov byte ptr [eax],1
		mov dword ptr [eax+4],2
		mov word ptr [eax+8],3
		mov dword ptr [eax+12],4
	}

}

int main()
{
	_asm
	{
		push test
	    call set_struct(test)
		add esp,4
	}

}

