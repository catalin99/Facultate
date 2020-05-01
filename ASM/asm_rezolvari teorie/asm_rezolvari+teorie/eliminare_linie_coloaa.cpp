#include<iostream.h>
int n,x,y;
/*void minor(int src[100][100],int dst[100][100],int n,int x,int y)
{
	int i,j,q;
	//elimina linia x
	for(i=0;i<n;i++)
		if(i==x)
			for(q=x-1;q<n-1;q++)
				for(j=0;j<n;j++)
					src[q][j]=src[q+1][j];
	

	//elimina coloana y
	for(j=0;j<n;j++)
		if(j==y)
			for(q=y-1;q<n-1;q++)
				for(i=0;i<n;i++)
					src[i][q]=src[i][q+1];

	n--;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dst[i][j]=src[i][j];
}*/

void minor(int *src,int *dst,int dim,int x,int y)
{
	int i,j;
	asm{
mov ebx, [ebp+8]
mov ecx, [ebp+12]
mov esi, 0 //i
mov edi, 0 //j
mov edx, 0
mov eax, 0
fori: cmp esi, dim
jge endfori
forj: cmp edi, dim
jge endforj
cmp esi, x
je stop1
cmp edi, y
je stop1
mov z, esi
mov esi, [ebx + eax]
mov [ecx + edx], esi
mov esi, z
add edx, 4
add eax, 4
inc edi
jmp forj
stop1: add eax, 4
inc edi
jmp forj
endforj: inc esi
mov edi, 0
jmp fori
endfori:
}
}
int main()
{
int a[4][4], b[3][3], i, j, dim=4;
for (i = 0; i < 4; i++)
for (j = 0; j < 4; j++)
a[i][j] = i;
int *p = a[0], *r = b[0];
minor(p, r, dim, 2, 3);
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
cout << b[i][j] << " ";
cout << endl;
}
/*
void minor(int* src, int* dst, int dim, int x, int y){
	_asm{
		mov esi, [ebp+8]//sursa 
		mov edi, [ebp+12]//destinatie
		mov edx, [ebp+16]//dimensiunea
		xor eax, eax //linia
		xor ebx, ebx //coloana
	_while1:
		cmp eax, edx
		jge _finish
		cmp eax, [ebp+20]
		jz _salt
		inc eax
		xor ebx, ebx
	_while2:
		cmp ebx, edx
		jge _while1
		cmp ebx, [ebp+24]
		jz _salt2
		mov ecx, [esi]
		mov [edi], ecx
		add edi, 4
		add esi, 4
		inc ebx
		jmp _while2
	_salt:
		inc eax
		lea esi, [esi+edx*4]
		jmp _while1
	_salt2:
		inc ebx
		add esi, 4
		jmp _while2
	_finish:
	}
}
*/
int main()
{
	int i,j,src[10][10],dst[10][10];
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>src[i][j];
	cout<<"x=";cin>>x;
	cout<<"y=";cin>>y;
	minor( *src, *dst, n, x, y);
	n--;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<dst[i][j]<<" ";
			cout<<endl;
		}
		return 0;
}


						
