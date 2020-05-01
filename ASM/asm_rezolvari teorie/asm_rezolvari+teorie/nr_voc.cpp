#include<iostream.h>
#include<string.h>
/*int nr_voc(char s[100],int n)
{
	int nr=0,i;
	for(i=0;i<n;i++)
		if(strchr("aeiou",s[i])!=0)
			nr++;
	return nr;
}*/
int nr_voc(char s[100],int n)
{
	int nr;
	_asm{
		mov ebx,[ebp+8]
		mov eax,0 //nr
			mov ecx,0 //i
for_i:
		cmp ecx,n
			jae afara_for_i
		cmp byte ptr [ebx],'a'
			je afara
			
		cmp byte ptr [ebx],'e'
		je afara
		
		cmp byte ptr [ebx],'i'
		je afara
		
		cmp byte ptr [ebx],'o'
		je afara
		
		cmp byte ptr [ebx],'u'
		je afara 
inc eax
afara:
	  inc ebx
	  inc ecx
	  jmp for_i
afara_for_i:
		mov nr,eax
	}
	return nr;
}

int main()
{
	char s[100],n;
	cin.getline(s,100);
	n=strlen(s);
	cout<<nr_voc(s,n);
	return 0;
}

