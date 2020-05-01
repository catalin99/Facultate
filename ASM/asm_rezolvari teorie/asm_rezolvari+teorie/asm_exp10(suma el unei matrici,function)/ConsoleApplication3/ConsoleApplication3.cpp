#include <iostream>
using namespace std;
int n,m;
int suma(int a[][3],int n,int m)
{
	_asm
	{
		mov ecx,0
			mov esi,0
		 start_for_1:
			    cmp esi,[ebp+12]
				jge exit_for_1
				mov edi,0
			start_for_2:
			    cmp edi,[ebp+16]
				jge exit_for_2
				mov eax,[ebp+16]
				mul esi
				shl eax,2
				add eax,[ebp+8]
				add ecx,dword ptr [eax + edi*4]
				inc edi
				jmp start_for_2
			exit_for_2:
				inc esi
				jmp start_for_1
			exit_for_1:
				mov eax,ecx
	}
}

int main()
{
	int n,m,i,j,a[3][3],s;
	cin>>n;
	cin>>m;
	cout<<endl;
	for (i=0;i<n;i++)
	{for(j=0;j<m;j++)
	{cin>>a[i][j];}
	cout<<endl;}
	_asm
	{
		push m
			push n
			lea ebx,a
			push ebx
		call suma
		add esp,8
		mov s,eax
	}
	cout<<s;
}