#include<iostream>
using namespace std;

int f(int t[], int n)
{ _asm{
		mov edi,t;
		mov eax,0; //pt suma
		mov ebx,0;
E1: cmp ebx,n;
		jge EXIT_FOR1;
		add eax,[edi+ebx*4];
		inc ebx;
		jmp E1;
EXIT_FOR1: mov edx,0;
		div n;   //in eax acum se afla media
		mov ecx,eax; //punem media in ecx
		mov eax,1;   //eax va fi pt produs
	    mov ebx,-1;
E2: inc ebx;
		cmp ebx,n;
		jge EXIT_FOR2;
		cmp [edi+ebx*4],0;
		je E2;
		cmp [edi+ebx*4],ecx;
		jle E2;
		mul [edi+ebx*4];
		jmp E2;
EXIT_FOR2:
	}
	
}

void main()
{int t[20],n,P;
 cout<<"n=";
 cin>>n;
 cout<<"dati elementele tabloului "<<endl;
 for(int i=0;i<n;i++)
	 cin>>t[i];
 int *p=t;
 _asm{
	push n;
	push p;
	call f;
	add esp,8;
	mov P,eax;
    }
 cout<<"produsul cerut este "<<P<<endl;

}