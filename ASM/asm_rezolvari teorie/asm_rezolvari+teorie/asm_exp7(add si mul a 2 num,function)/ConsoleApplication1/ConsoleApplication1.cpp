#include <iostream>
using namespace std;
//Functii de adunare si de inmultire a doua numere
int f1(int a,int b)
{
	_asm
	{
	mov eax,[ebp+12]
	mul [ebp+8]
	}
}

int f2(int x,int y)
{
	_asm
	{
		mov eax,[ebp+12]
			add eax,[ebp+8]
	}
}


int main()
{
	int x,y,s,p;
	cin>>x;
	cin>>y;
	_asm
	{   
		push x
		push y
		call f1
		add esp,8
	    mov p,eax
		push x
		push y
	    call f2
		add esp,8
	    mov s,eax
	}
	cout<<"p= "<<p<<endl;
	cout<<"s= "<<s<<endl;
	return 0;
}