#include<iostream.h>
int n;
/*int f(int n)
{
	int S=0,P=1,i=1,j;
	for(j=1;j<=n;j++)
	{
		
		P=P*2*i;
		S=S+P;
		i++;
		
	}
	return S;
}
*/
void afisare(int P)
{
	cout<<P<<endl;
}
int f(int n)
{
	int S,i,P;
	_asm{
		mov eax,1 //P
			mov ebx,0 //S
			mov i,1  //i
			mov ecx,1 //j
bucla:
			cmp ecx,n
				ja afara
				mov edx,2
				imul edx
				imul i
				add ebx,eax
				inc i
				inc ecx
				jmp bucla
afara:
	mov S,ebx
	}
	return S;
}



int main()
{
	cout<<"n=";cin>>n;
	cout<<f(n);
	return 0;
}