#include<iostream>
using namespace std;
 int a[20][20],b[19][19],n,m,i,j,x,y;
void main()
{
int *p=a[0],*q=b[0];
cout<<"n=";cin>>n;
cout<<"m=";cin>>m;
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		cin>>a[i][j];

cout<<"x=";cin>>x;
cout<<"y=";cin>>y; 

_asm{
	mov edi,p;
	mov esi,q;
	mov ebx,-1; //i=0                   //for(i=0;i<x;i++)
	                                     // for(j=0;j<y;j++)
	                                     //     b[i][j]=a[i][j];
E1: inc ebx;  //i<x
	cmp ebx,x;
	mov ecx,0;  // j=0
	jge F2;
E2: cmp ecx,y;  //j<y;
	jge E1;
	
	mov eax,ebx; //i*nr coloane B
	push ebx;     
	mov ebx,19;
	mul ebx;
	pop ebx;

	add eax,ecx;  // adunam j
	push eax;      //salvam rez
	
	mov eax,ebx;   //i*nr coloane A
	push ebx;
	mov ebx,20;
	mul ebx;
	pop ebx;

	add eax,ecx;  //adunam j
	pop edx;     //edx rep i*nr_coloane+j pt B
	
	push ecx;            //operatii pe matrici
	mov ecx,[edi+eax*4];  
	mov [esi+edx*4],ecx;
	pop ecx;

	inc ecx;   //j++
	jmp E2;    //salt la forul cu i
F2:                                        //for(i=x;i<n-1;i++)
	                                     // for(j=0;j<y;j++)
	                                     //     b[i][j]=a[i+1][j];
	mov edx,x;
	dec edx;
	mov ebx,edx; //i=x
	
E1_2: inc ebx;  //i<n-1
	mov edx,n;
	dec edx;
	cmp ebx,edx;
	mov ecx,0;  // j=0
	jge F3;
E2_2: cmp ecx,y;  //j<y;
	jge E1_2;
	
	mov eax,ebx; //i*nr coloane B
	push ebx;     
	mov ebx,19;
	mul ebx;
	pop ebx;

	add eax,ecx;  // adunam j
	push eax;      //salvam rez
	
	mov eax,ebx;
	inc eax        //i+1 *nr coloane A
	push ebx;
	mov ebx,20;
	mul ebx;
	pop ebx;

	add eax,ecx;  //adunam j
	pop edx;     //edx rep i*nr_coloane+j pt B
	
	push ecx;            //operatii pe matrici
	mov ecx,[edi+eax*4];  
	mov [esi+edx*4],ecx;
	pop ecx;

	inc ecx;   //j++
	jmp E2_2;    //salt la forul cu i
F3:                                   //for(i=0;i<x;i++)
	                                     // for(j=y;j<m-1;j++)
	                                     //     b[i][j]=a[i][j+1];
	mov ebx,-1; //i=0
	
E1_3: inc ebx;  //i<x
	cmp ebx,x;
	mov ecx,y;  // j=y
	jge F4;
E2_3: mov edx,m;
	dec edx;
	cmp ecx,edx;  //j<m-1;
	jge E1_3;
	
	mov eax,ebx; //i*nr coloane B
	push ebx;     
	mov ebx,19;
	mul ebx;
	pop ebx;

	add eax,ecx;    // adunam j
	push eax;      //salvam rez
	
	mov eax,ebx;   //i*nr coloane A
	push ebx;
	mov ebx,20;
	mul ebx;
	pop ebx;

	add eax,ecx;
	inc eax     //adunam j+1
	pop edx;     //edx rep i*nr_coloane+j pt B
	
	push ecx;            //operatii pe matrici
	mov ecx,[edi+eax*4];  
	mov [esi+edx*4],ecx;
	pop ecx;

	inc ecx;   //j++
	jmp E2_3;    //salt la forul cu i
F4: 
	mov edx,x;
	dec edx
	mov ebx,edx; //i=x                   //for(i=x;i<n-1;i++)
	                                     // for(j=y;j<m-1;j++)
	                                     //     b[i][j]=a[i+1][j+1];
E1_4: mov edx,n;
	dec edx;
	inc ebx;  //i<n-1
	cmp ebx,edx;
	mov ecx,y;  // j=y
	jge EXIT;
E2_4: mov edx,m;
	dec edx;
	cmp ecx,edx;  //j<m;
	jge E1_4;
	
	mov eax,ebx;   //i*nr coloane B
	push ebx;     
	mov ebx,19;
	mul ebx;
	pop ebx;

	add eax,ecx;  // adunam j
	push eax;      //salvam rez
	
	mov eax,ebx;
	inc eax     //i+1*nr coloane A
	push ebx;
	mov ebx,20;
	mul ebx;
	pop ebx;

	add eax,ecx; 
	inc eax     //adunam j+1
	pop edx;     //edx rep i*nr_coloane+j pt B
	
	push ecx;            //operatii pe matrici
	mov ecx,[edi+eax*4];  
	mov [esi+edx*4],ecx;
	pop ecx;

	inc ecx;   //j++
	jmp E2_4;    //salt la forul cu i
EXIT:                  
    }

for(i=0;i<n;i++)
	{for(j=0;j<m;j++)
		cout<<a[i][j]<<" ";
cout<<endl;}
cout<<endl;
for(i=0;i<x;i++)
	{for(j=0;j<y;j++)
		cout<<a[i][j]<<" ";
cout<<endl;}
cout<<endl;
for(i=0;i<n-1;i++)
	{for(j=0;j<m-1;j++)
		cout<<b[i][j]<<" ";
cout<<endl;}
}