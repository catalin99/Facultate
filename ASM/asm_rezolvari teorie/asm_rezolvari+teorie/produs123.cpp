#include<iostream.h>
int n;
/* int produs(int n)
{
	int i;
	i=1;int p=1;
	while(p<=n)
	{
		p=p*i;
		i++;
	}
	return p;
}
*/
int produs(int n)
{
	int p;
	_asm{
		mov eax,1 //produs
			mov ecx,1 //i
bucla:
			cmp eax,n
			ja afara
			imul eax,ecx
			inc ecx
			jmp bucla
afara:
			mov p,eax
				}
	return p;
}

int main()
{
	cout<<"n=";cin>>n;
	cout<<produs(n);
	return 0;
}

