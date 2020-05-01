#include<iostream.h>
int v[100],n;
/*void sortare(int v[100],int n)
{
	int i,j,aux;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(v[i]>v[j])
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
}*/

void sortare(int *v,int n)
{
	_asm{
		mov ebx,[ebp+8]
		mov ecx,1 //i
for_i:
		cmp ecx,[ebp+12]
			ja afara_i
			mov edx,ecx 
			inc edx //j
for_j:
		cmp edx,[ebp+12]
			ja afara_j
			mov esi,[ebx+ecx*4] //v[i]
			mov edi,[ebx+edx*4] //v[j]
			cmp esi,edi
			jbe afara_if
			 mov [ebx+ecx*4],edi
		 mov [ebx+edx*4],esi
		 

afara_if:
		inc edx
			jmp for_j
afara_j:
		inc ecx
			jmp for_i
afara_i:
	}
}


int main()
{
	int i;
	cout<<"n=";cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"v[i]=";
		cin>>v[i];
	}
	sortare(v,n);
	for(i=1;i<=n;i++)
		cout<<v[i];
	return 1;
}
