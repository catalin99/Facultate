#include<iostream.h>
/*int fib(int n)
{
	if(n==1 || n==2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}*/
int fib(int  n){
	_asm{
push ebx
mov eax, n //n
cmp eax,1
jbe finish
dec eax //n-1
push eax
dec eax //n-2
push eax
call fib
add esp,4
mov ebx,eax
call fib
add esp,4
add eax,ebx
finish:
pop ebx
	}
}
int main()
{
	int  n;
	cin>>n;
	cout<<fib(n);
	return 0;
}
