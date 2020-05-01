void bubble_sort_asm(int nr, int* v)
{
	 _asm{
	
	do_while:
		 mov ecx,1
		 mov eax,1
	bucla:
		 cmp ecx,[ebp+8]
		 jae bucla_out
		 mov ebx,[ebp+12]
		 mov esi,[ebx+ecx*4-4]
		 mov edi,[ebx+ecx*4]
		 cmp esi,edi
		 jbe ok
		 mov [ebx+ecx*4-4],edi
		 mov [ebx+ecx*4],esi
		 xor eax,eax
	ok: 
		 inc ecx
		 jmp bucla
		 
	bucla_out:
		 test eax,eax
		 jnz iesire
		 jmp do_while
	iesire:
	 }
}