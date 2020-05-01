#include<iostream>
/*int prim(int n)
{
	int d;
	for(d=2;d<=n;d++)
		if(n%d==0)
			return 0;
	return 1;
}*/

int prim(int n)
{
	bool a;
	_asm{
		mov eax,n
			mov esi,2 //d
i_for:
		cmp esi,eax
			ja afara
			mov edx,0
			div esi
			cmp edx,0
			jne e1
			mov a,0
e1:
		inc esi
			jmp i_for
afara:
	}
	if(a==0)
		return 0;
	return 1;
}
		




int main()
{
	int n,s;bool a;
	cin>>n;
	_asm{
		mov ebx,0 //s
			mov ecx,1 //i
for_i:
		cmp ecx,n
			ja afara_for_i
		mov eax,n
			mov esi,2 //d
i_for:
		cmp esi,eax
			ja afara
			mov edx,0
			div esi
			cmp edx,0
			jne e1
			mov a,0
e1:
		inc esi
			jmp i_for
afara_for_i:
		cmp a,0
			jne executa
executa:add ebx,ecx
		inc ecx
	afara_for_i:
		jmp for_i
		mov s,ebx
	}
	cout<<s;
return 1;


}
