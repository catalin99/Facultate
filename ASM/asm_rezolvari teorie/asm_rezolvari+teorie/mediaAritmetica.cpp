#include<iostream.h>
int  media(int *v,int n)
{
	int medie;
	_asm{
		mov ebx,[ebp+8] //v[0]
		mov ecx,0 //i
			mov eax,0 //s
for_i:
		cmp ecx,n
			ja afara
			add eax,[ebx+ecx*4]
			inc ecx
			jmp for_i
afara:
			mov edx,0
			mov esi,n
			div esi
			mov medie,eax
		}
	return medie;
}
int main()
{
	int i,v[10];
for(i=1;i<=5;i++)
	{
		cout<<"v[i]=";
		cin>>v[i];
	}
	cout<<media(v,5);

	return 0;
}