#include<iostream.h>
int v[100],n;
/*int numara(int *v,int n)
{
	int nr;
	nr=0;
	for(int i=1;i<=n;i++)
		if(v[i]<=5)
			nr++;
	return nr;
}*/

int numara(int *v,int n)
{

	int nr;
	_asm{
		mov ecx,1 //i
			mov eax,0 // nr
bucla:
		cmp ecx,n
			ja afara
			cmp v[ecx],5
			ja afara1
			inc eax
afara1:
			inc ecx
			jmp bucla
afara:
	mov nr,eax
	}
	return nr;
}
void main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	cout<<numara(v,n);
}