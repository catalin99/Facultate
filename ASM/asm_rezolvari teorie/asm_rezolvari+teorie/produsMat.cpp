#include<iostream.h>
int a[10][10];
/*int produs(int a[10][10],int n,int m)
{
	int i,j,p=1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			p=p*a[i][j];
	return p;
}
*/
int produs(int a[10][10],int n,int m)
{
 int p;
	_asm{
		mov ebx,[ebp+8] //a[0][0]
		 mov esi,0 //i
		 mov edi,0 //j
		 mov eax,0
		 mov p,1
startfor1:cmp esi,n
		  je exit_functie
		  mov edi,0
startfor2:cmp edi,m
		  je exitfor2
		  mov eax,0 
		  add eax,m //m
	      mul esi //m*i
		  shl eax,2 //4*m*i
		  add eax,ebx //a[0][0]+4*m*i
          mov ecx,[eax+4*edi] //a[0][0]+4*j+4*m*i
		  mov edx,0
		  mov eax,p
		  imul ecx
		  mov p,eax
		  inc edi
			 jmp startfor2
exitfor2:inc esi
		 jmp startfor1
exit_functie:
		
}
	return p;
}


int main()
{

	int n,m;
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cout<<"a[i][j]=";
			cin>>a[i][j];
		}
		cout<<produs(a,n,m);
		return 1;
}
