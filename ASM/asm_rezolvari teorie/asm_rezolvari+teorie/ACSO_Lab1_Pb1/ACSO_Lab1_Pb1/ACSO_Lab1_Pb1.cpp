// ACSO_Lab1_Pb1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define LEAST_SEMNIF 55607
#define SEMNIF 1
using namespace std;
int least_semnif, semnif;
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	n = 92682;
	int least_semnif, semnif;
	_asm{
		/*In acest bloc scrieti codul ASM*/
		mov eax, n;
		mov ebx, eax;
		inc ebx
		mov edx, 0;
		mul ebx;
		mov ecx, edx;
		xor edx, edx;
		mov ebx, 2;
		div ebx;
		mov least_semnif, eax;
		xor edx, edx;
		mov eax, ecx;
		div ebx;
		mov semnif, eax;
	}
	if (least_semnif == LEAST_SEMNIF && SEMNIF == semnif){
		printf("Ok!\n");
	}
	else{
		printf("Failed! Your result is: %d*pow(2,32)+%d\n", semnif, least_semnif);
	}
}

