#include<iostream.h>
/*int prim(int n)
{
	int d;
	for(d=2;d<=n;d++)
		if(n%d==0)
			return 0;
	return 1;
}*/

int prim(int n)
{
	bool a;
	_asm{
		mov eax,n
			mov esi,2 //d
i_for:
		cmp esi,eax
			ja afara
			mov edx,0
			div esi
			cmp edx,0
			jne e1
			mov a,0
e1:
		inc esi
			jmp i_for
afara:
	}
	if(a==0)
		return 0;
	return 1;
}
		




int main()
{
	int n;

	cout<<"n=";cin>>n;
	if(prim(n)==1)
		cout<<"numar prim";
	else
		cout<<"nu este numar prim";
	return 1;
}