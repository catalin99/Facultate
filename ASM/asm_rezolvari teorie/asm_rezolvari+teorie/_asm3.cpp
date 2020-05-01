#include<iostream>
using namespace std;

int f(char s[], int n)
{ 
	_asm{
		mov edi,s;
		mov ecx,1;
		mov ebx,0;
		mov eax,0;   // va numara caracterele din al n-ulea cv
		cmp ecx,n;  // cazul cand n=1
		je E3;
	E0: cmp [edi+ebx],'\0'
			je E1;
		cmp [edi+ebx],' '
			je E2;
	E5: inc ebx;
		jmp E0;
	E2: inc ecx;
		cmp ecx,n;
		je E1;
		jmp E5;
	E1: inc ebx;
	E3: cmp [edi+ebx],' ';
		je E4;
		cmp [edi+ebx],'\0';
		je E4;
		inc eax;
		inc ebx;
		jmp E3;
	E4: 
}}


int main()
{int n,j;
char s[100];
cout<<"S="; cin.get(s,99); 
cout<<"n=";cin>>n;
char *p=s;

 _asm
 {
	 push n;
	  lea ecx,s;
	  push ecx;
	  call f;
	  add esp,8;
	  mov j,eax;
 }
  cout<<f(s,n)<<endl;
	return 0;
}