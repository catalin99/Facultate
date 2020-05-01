#include<iostream.h>
int n;
/*float  media(int &n)
{
	int c,nr,s;
	s=0;nr=0;
	float ma;
	while(n!=0)
	{
		c=n%10;
		s=s+c;
		nr++;
		n=n/10;
	}
	ma=s/(float)nr;
	return ma;
}
*/
float media(int n)
{
	int s,nr;float ma;
	s=nr=0;
	_asm{
		mov ebx,0 //suma
			mov ecx,0 //nr
			mov eax,n //n
bucla:
		cmp eax,0
			je afara
			mov edx,0
			mov esi,10
			div esi
			//c=edx
			add ebx,edx
			inc ecx
			jmp bucla
afara:
		mov s,ebx
			mov nr,ecx
	}
	ma=s/(float)nr;
}


			
int main()
{
	cout<<"n=";cin>>n;
	cout<<media(n);
	return 1;
}
