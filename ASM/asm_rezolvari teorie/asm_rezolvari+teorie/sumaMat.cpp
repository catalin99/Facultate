#include<iostream.h>
int n,m;
/*int suma(int a[10][10],int n,int  m)
{
	int S=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			 S=S+a[i][j];
		return S;
}*/

int suma(int a[10][10],int n,int m)
{
	int S=0;
	_asm{
			mov ebx,[ebp+8]
			mov esi,0 //s
			mov ecx,0 //i
for_i:
		cmp ecx,[ebp+12]
			jae afara_i
for_j:
			 mov edx,0 //j
			 cmp edx,[ebp+12]
			 jae afara_j
	mov eax,[ebp+16] 
	mul ecx 
	shl eax,2
	add eax,ebx
	mov edi,[eax+edx*4] //a[i][j]
	add esi,edi
			 inc edx
			 jmp for_j
afara_j:
			 inc ecx
			 jmp for_i
			 
afara_i:
			 mov S,esi
	}
	return S;
}



int main()
{
	int a[10][10];
	int i,j;
	cout<<"n=";cin>>n;
	cout<<"m=";cin>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cout<<"a[i][j]=";cin>>a[i][j];
		}
	cout<<suma(a,n,m);
	return 0;
}

