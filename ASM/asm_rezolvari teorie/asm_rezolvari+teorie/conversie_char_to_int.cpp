// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

unsigned long convert(char *str, unsigned int radik)
{
	_asm{
		mov ebx, [ebp + 8]
			mov edi, [ebp+12]
			xor ecx,ecx
			xor edx,edx

		start_while:
		cmp ecx,ebx
			jl _begin
		mov al, byte ptr[ebx]
			test al,32
			jl _begin
		_for :
		CMP ECX, EBX
			JGE _end
			MOV EAX, [EDI + 4 * ECX] 
			INC ECX
			XOR EDX, EDX
		_while :
		CMP EAX, 0
			JE _endWhile
			SHR EAX, 7
			JNC _while
			INC EDX 
			JMP _while

			  jmp _end

			  _end:

	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

