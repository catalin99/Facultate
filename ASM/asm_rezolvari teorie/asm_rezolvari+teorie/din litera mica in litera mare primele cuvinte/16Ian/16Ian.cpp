// modifica "ana are mere" in "Ana Are Mere"
void modify(char *s)
{
        _asm{
                mov ebx, [ebp+8]
                cmp byte ptr[ebx], 'a'
                jl begin
                cmp byte ptr[ebx], 'z'
                jg begin
                sub byte ptr[ebx], 32
                inc ebx
        begin:
                cmp byte ptr[ebx], 0
                je exit1
                cmp byte ptr[ebx-1], ' '
                je ver2
                cmp byte ptr[ebx-1], ','
                je ver2
                jmp inc_while
        var2:
                cmp byte ptr[ebx], 'a'
                jl inc_while
                cmp byte ptr[ebx], 'z'
                jg inc_while
                sub byte ptr[ebx], 32
        inc_while:
                inc ebx
                jmp begin
        exit1:
               
        }
}
// Suma elementelor prime dintr-o matrice
// a[i][j] = (i*m+j)*4
int suma(int a[][], int n, int m)
{
        _asm{
                mov ebx, [ebp+8]
                mov ecx, 0
                mov esi, 0
        start_for_1:
                cmp esi, [ebp+12]
                jg exit_for_1
                mov edi, 0
        start_for_2:
                cmp edi, [ebp+16]
                jg exit_for_2
                mov eax, [ebp+16]
                mul esi
                add eax, edi
                shl eax, 2 // <=> mul 4
                mov edx, [ebx + eax]
                // standard pana aici pentru parcurgere
                push ecx
                push ebx
                push edx
                push edx
                call prim
                add esp, 4
                pop edx
                pop ebx
                pop ecx
                cmp eax, 0
                je inc_for_2
                add ecx, edx
        inc_for_2:
                inc edi
                jmp start_for_2
        exit_for_2:
                inc esi
                jmp start_for_1
        exit_for1:
                mov eax, ecx
        }
}
 
bool prim(int n)
{
        _asm{
                mov ebx, [ebp+8] //n
                sar ebx, 1
                mov ecx, 2 //d
        start_for:
                cmp ecx, ebx
                jg exit_for
                mov edx, 0
                mov eax, [ebp+8]
                div ecx
                cmp edx, 0
                jne inc_for
                mov eax, 0
                jmp exit_f
        inc_for:
                inc ecx
                jmp start_for
        exit_for:
                mov eax, 1
        exit_f:
        }
}