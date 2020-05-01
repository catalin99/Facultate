//Sa se scrie codul in limbaj de asamblare care oglindeste bitii  unui numar

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(){
	char number;
	number = 140;

	_asm {
		mov al, number			//al=number
		xor cl, cl				//cl                         =11111111b

		mov bl, al				//bl=number
		and bl, 00000001b		//bl=bitwise_and bl,00000001b=0000000xb
		shl bl, 7				//unsigned shift to left,  bl=x0000000b
		or cl, bl				//cl=bitwise_or cl,bl        =x1111111b

		mov bl, al				//bl=number
		and bl, 00000010b		//bl=bitwise_and bl,00000010b=000000x0b
		shl bl, 5				//unsigned shift to left,  bl=0x000000b
		or cl, bl				//cl=bitwise_or cl,bl        =xx111111b

		mov bl, al				//bl=number
		and bl, 00000100b		//bl=bitwise_and bl,00000100b=00000x00b
		shl bl, 3				//unsigned shift to left,  bl=00x00000b
		or cl, bl				//cl=bitwise_or cl,bl        =xxx11111b

		mov bl, al				//bl=number
		and bl, 00001000b		//bl=bitwise_and bl,00001000b=0000x000b
		shl bl, 1				//unsigned shift to left,  bl=000x0000b
		or cl, bl				//cl=bitwise_or cl,bl        =xxxx1111b

		mov bl, al				//bl=number
		and bl, 00010000b		//bl=bitwise_and bl,00010000b=000x0000b
		shr bl, 1				//unsigned shift to right, bl=0000x000b
		or cl, bl				//cl=bitwise_or cl,bl        =xxxxx111b

		mov bl, al				//bl=number
		and bl, 00100000b		//bl=bitwise_and bl,00100000b=00x00000b
		shr bl, 3				//unsigned shift to right, bl=00000x00b
		or cl, bl				//cl=bitwise_or cl,bl        =xxxxxx11b

		mov bl, al				//bl=number
		and bl, 01000000b		//bl=bitwise_and bl,01000000b=0x000000b
		shr bl, 5				//unsigned shift to right, bl=000000x0b
		or cl, bl				//cl=bitwise_or cl,bl        =xxxxxxx1b

		mov bl, al				//bl=number
		and bl, 10000000b		//bl=bitwise_and bl,10000000b=x0000000b
		shr bl, 7				//unsigned shift to right, bl=0000000xb
		or cl, bl				//cl=bitwise_or cl,bl        =xxxxxxxxb

		mov number, cl			//number=cl
	}

	if (number != 49){
		cout << "Failed! Your result is " << int(number) << endl;
	}else{
		cout << "Ok!" << endl;
	}
	system("PAUSE");
    return 0;
}