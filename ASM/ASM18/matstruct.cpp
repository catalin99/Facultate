#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define newline f1();
void f1()
{
	cout << '\n';
}

//i*nrcol+j
struct mystruct
{
	int x, y, z;
};

void fillstruct(mystruct *)
{
	_asm
	{
		mov ecx, [ebp + 8]
		mov dword ptr [ecx],  3
		mov dword ptr [ecx + 4],  4
		mov dword ptr [ecx + 8],  5
	}
}

void matrice(mystruct *, int, int *)
{
	_asm
	{
		mov ebx, [ebp + 16] //matricea
		mov edx, [ebp + 8] //structura
		mov esi, 0 //i
		_fori:
			cmp esi, [ebp+12]
			jge _endfori
			mov edi, 0//j
			_forj:
				cmp edi, [ebp+12]
				jge _endforj
				//poz elem curent
				mov eax, [ebp+12]
				imul eax, esi
				add eax, edi
				//end poz
				mov ecx, [ebx+4*eax] //elementul curent
				push eax//pune eax in stiva
				cmp ecx, [edx]//daca elem din matrice este egal cu x (din struct)
				je _do
				cmp ecx, [edx+4]//=y
				je _do
				cmp ecx, [edx+8]//=j
				je _do
				jmp _nothing
				_do:
				mov eax, ecx
				imul eax, eax //ridicare la patrat element daca este egal cu unul dintre elementele din structura
				mov ecx, eax
				pop eax//scoate eax din stiva
				mov [ebx+4*eax], ecx
				jmp _nothing2
					_nothing:
					pop eax
					_nothing2:
				inc edi
				jmp _forj
			_endforj:
			inc esi
			jmp _fori
		_endfori:
	}
}
int main()
{
	int a[4][4];
	mystruct *d=new mystruct;
	int n = 4;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	fillstruct(d);
	//test
	cout << d->x << ' ' << d->y << ' ' << d->z << endl;
	//test
	matrice(d, n, (int*)a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}