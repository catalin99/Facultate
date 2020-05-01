#include<iostream.h>
int main()
{
/*	unsigned a,b,x;
	a=3;b=1;
 _asm{
		mov eax,b
			shr a,cl
			mov eax,a
			mov x,eax
	}
	cout<<x;
	int a,b,c;
	b=2;c=3;
	_asm{
		mov eax,b
			imul c
			mov a,eax
	}
	cout<<a;
	unsigned a,b;
	b=34;
	_asm{
		mov ecx,10
			mov eax,b
			mov edx,0
			div ecx
			mov a,eax

	}
	cout<<a;*/
	unsigned n=5148,nr;
	char s[10];
	_asm{
		mov eax,n
			mov esi,10
			mov ebx,0
bucla:
		mov edx,0
			div esi
			add edx,'0'
			mov s[ebx],dl
			inc ebx
			cmp eax,0
			ja bucla
			mov s[ebx],0
			mov nr,ebx
	
		
			mov eax,nr
			sub eax,1
			mov edx,0
			mov esi,2
			div esi
			mov edi,eax
			mov eax,nr
			dec eax
			mov ebx,0
			mov bx,eax
			
			
bucl:
		
			mov ax,s[ebx]
			mov edx,0
			div esi
			mov s[ebx],s[eax]
			mov s[eax],ax
			inc ebx
			dec bx
			mov eax,bx
			cmp ebx,edi
			ja bucl
	}
	cout<<s;








			

	return 0;
}



