#include<iostream>
using namespace std;
char subsir(char *c1)
{_asm{
	mov ecx,c1
	mov edi,0
whilef:cmp[ecx+edi],0
	  je iesire1
	  mov esi,0
	  mov al,[ecx+edi]
	 
spatiu:cmp al,' '
	  je spatiu1
	  inc edi
conditie:cmp al,'0'
		 ja et1
		 cmp al,'9'
		 jb et1
		 
spatiu1: add al,1
	     cmp al,' '
	     je spatiu1
		 
	    jmp conditie
	     inc esi
	   jmp spatiu
iesire1:mov ebx,edi
		jmp final
et1:mov ebx,esi
    jmp final
final:
}
}
void main()
{int x;
	char c1[100]="f9c 78d 39  69a 7";

	_asm{lea ecx,c1
		 push ecx
		 call subsir
		 add esp,4
		 mov x,ebx}
cout<<x<<endl;}