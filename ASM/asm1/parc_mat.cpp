#include<iostream>
using namespace std;
int a[20][20];
void main()
{ int n,m,i,j;
  int *p=a[0];
cout<<"n=";cin>>n;
cout<<"m=";cin>>m;
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		cin>>a[i][j];
for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
		cout<<a[i][j]<<" ";
cout<<endl;}

_asm{
	mov edi,p;
	mov ebx,-1;//i=-1;
E1: inc ebx;
	cmp ebx,n;
	mov ecx,0; //j=0
	jge F2;
E2: cmp ecx,m;
	jge E1;
	mov eax,ebx;
	mov esi,20;
	mul esi;
	add eax,ecx;
	mov [edi+eax*4],10;
	inc ecx;
	jmp E2;
F2: 
    }
cout<<endl;
for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
		cout<<a[i][j]<<" ";
cout<<endl;}
}