#include<iostream>
using namespace std;

void main()
{int n,t[100],S,P;
 cout<<"n=";
 cin>>n;
 cout<<"dati elementele tabloului "<<endl;
 for(int i=0;i<n;i++)
	 cin>>t[i];
 int *p=t;
_asm{mov edi,p;
	mov ebx,0;
	mov eax,0;
 E1:cmp ebx,n;
	jge EXIT;
	add eax,t[ebx*4];
	inc ebx;
	jmp E1;
EXIT:
	mov edx,0;
	div n;
	mov S,eax;
    mov ebx,-1;
	mov eax,1;
E2: inc ebx;
	cmp ebx,n;
	jge EXIT2;
	cmp t[ebx*4],4;
	jge E2;
    mul t[ebx*4];
	jmp E2; 
EXIT2: mov P,eax;
}
cout<<"suma este "<<S<<endl<<"produsul este "<<P<<endl;
}