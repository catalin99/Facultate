//Sa se scrie codul in limbaj de asamblare care calculeaza suma: 1+2+3+...+n, unde n = 92682 
//Atentie, aceasta suma nu se poate reprezenta folosind doar 32 de biti.

#include "stdafx.h"
#include <iostream>
using namespace std;
#define LEAST_SEMNIF 55607
#define SEMNIF 1

int main(){
	int n=92682, least_semnif, semnif;
	_asm {
		mov eax, n					//eax=n
		mov ebx, eax				//ebx=eax(n)
		inc ebx						//ebx++(ebx==n+1)
		mul ebx						//edx eax=eax*ebx (edx eax = n*n+1)
		shr eax, 1					//eax unsigned shift to right with 1 bit (eax /2)
		mov ebx, edx				//ebx=edx
		shr edx, 1					//edx unsigned shift to right with 1 bit (edx /2)
		shl ebx, 31					//ebx unsigned shift to left with 1 bit (ebx = ultimul bit de la edx, pus pe prima pozitie)
		or eax, ebx					//eax=bitwise_or eax,ebx (eax pune pe primul bit ultimul bit de la edx)
		mov semnif, edx				//semnif = edx
		mov least_semnif, eax		//least_semnif = eax
	}
	cout << semnif << "::: " << least_semnif << endl;
	if (least_semnif == LEAST_SEMNIF && SEMNIF == semnif) {
		cout << "Ok! Your result is: " << semnif*pow(2,32)+ least_semnif << endl;
	}
	else {
		cout << "Failed! Your result is: " << semnif*pow(2, 32) + least_semnif << endl;
	}
	system("PAUSE");
    return 0;
}