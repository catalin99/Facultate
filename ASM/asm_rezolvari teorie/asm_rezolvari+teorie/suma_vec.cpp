#include<iostream.h>
int v[100];
/*int suma(int v[100],int n)
{
	int i,s=0;
	for(i=1;i<=n;i++)
		 s=s+v[i];
	return s;
}
*/
int suma(int *v,int n)
{
	int s=0;
	_asm{
		mov ebx,[ebp+8]
		mov ecx,0 //i
			mov eax,0 //s
for_i:
		cmp ecx,[ebp+12]
			ja afara
			add eax,[ebx+ecx*4]
			inc ecx
			jmp for_i
afara:
		mov s,eax
	}
	return s;
}
int main()
{
	int i,n;
	cout<<"n=";cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"v[i]=";cin>>v[i];
	}
	cout<<suma(v,n);
	return 1;
}