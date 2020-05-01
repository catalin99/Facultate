#include <iostream>
using namespace std;
//suma elementelor unui vector
int main()
{
	unsigned char v[100];
	int n,s,i;
	cin>>n;
	for (i=0;i<n;i++)
	{scanf_s("%d",&v[i]);}
	_asm
	{
		lea ebx,v
			mov ecx,0
			mov eax,0
		start_for:
		cmp ecx,n
			jge exit_for
			movsx edx,byte ptr[ebx+ecx]
			add eax,edx
			inc ecx
			jmp start_for
		exit_for:
		mov s,eax
	}
	cout<<s;
}