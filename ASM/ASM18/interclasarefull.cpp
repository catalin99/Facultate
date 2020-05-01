// interclasare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void interclasare(int *, int *, int *, int, int)
{
	_asm
	{
		mov eax,[ebp+8]
		mov ebx,[ebp+12]
		mov ecx,[ebp+16]
		mov edx,0///contorul pentru primul vector
		mov esi,0///contorul pentru al2lea vector
		mov edi,0///contorul pentru vectorul 3
		while1:
				cmp edx,[ebp+20]
				jge stopwhile1
				cmp esi,[ebp+24]
				jge stopwhile1
				
				push edi
				mov edi,[eax+4*edx]
				cmp edi,[ebx+4*esi]
				jl puneprimu
				pop edi
				push edi
				mov edi, [eax+4*edx]
				cmp edi,[ebx+4*esi]
				jge pune2
				pop edi

					puneprimu:
								pop edi
								push esi
								mov esi,[eax+4*edx]
								mov [ecx+4*edi],esi
								pop esi
								inc edi
								inc edx
								jmp while1
					
					pune2:
								pop edi
								push edx
			      				  mov edx , [ebx + 4 * esi]
								mov [ecx+4*edi],edx
								pop edx
								inc edi
								 inc esi
							jmp while1
		stopwhile1:


			
							
							
		while2:cmp edx,[ebp+20]
			   jge stopwhile2
				
			   mov esi,[eax+4*edx]
			   mov [ecx+4*edi],esi
			   inc edx
			   inc edi
			   jmp while2
			stopwhile2:

		   while3:cmp esi,[ebp+24]
				  jge stopwhile3
			     mov edx,[ebx+4*esi]
			   mov [ecx+4*edi],edx
			   inc edi
			   inc esi
			   jmp while3
			stopwhile3:




	}
}

int main()
{
	int a[101], b[101], c[101];
	int n, m;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf_s("%d", &b[i]);
	interclasare(a, b, c, n, m);
	for (int i = 0; i < m+n; i++)
		printf("%d ", c[i]);
    return 0;
}