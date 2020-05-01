#include<iostream.h>
/*int cmmdc(int a,int b)
{
	while(a!=b)
		if(a>b)
			a=a-b;
		else
			b=b-a;
	return a;
}
*/
int cmmdc(int a,int b)
{

	_asm{
		mov eax,a //a
			mov ebx,b //b
i_while:
		cmp eax,ebx
			je afara
			cmp eax,ebx
			jb afara_if
			sub eax,ebx
afara_if:sub ebx,eax
		 jmp i_while
afara:
		
		mov a,eax
	}
	return a;
}
int main()
{
	int a,b;
	cout<<"a=";cin>>a;
	cout<<"b=";cin>>b;
	cout<<cmmdc(a,b);
	return 0;
}
