#include<iostream.h>
int n;
/*int FactorialRec(int n)
{
	int fact=1;
	if(n<=1)
		return 1;
		fact=n*factorial(n-1);
	return fact;
/*int FactorialNormal(int n)
{
	int i=1;
	int P=1;
	while(i<=n)
	{
		P=P*i;
		i++;
	}
	return P;
}
*/
int FactorialNormal(int n)
{
	int P;
	_asm{
		mov ebx,1 //i
			mov eax,1 //P
while_i:
		cmp ebx,n
			ja afara
			mul ebx
			inc ebx
			jmp while_i
afara:
		mov P,eax
	}
	return P;
}
/*int factorial(int n)
{
	

		 _asm
        {
                push ecx;
 
                cmp n, 1;
                ja general;
 
                mov EAX, 1;
                jmp final;
 
general:
                mov ECX, n;
                dec ECX;
                push ECX;
                call fact_asm;
                add ESP, 4;
                mul n;
 
final:
                pop ecx;
        }
}
	}
}
*/

int main()
{
	cin>>n;
	cout<<FactorialNormal(n);
	return 0;
}

		