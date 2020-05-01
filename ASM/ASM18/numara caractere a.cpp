#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

///Registri
/*
Registri:
1) R. Uz general:
31-0	  15-0
15-8  7-0
EAX  |  AH   AL
EBX	 |  BH   BL
ECX	 |  CH   CL
EDX  |  DH   DL
ESI  |	   SI
EDI  |	   DI
EBP  |	   BP
ESP  |	   SP

2)R. de segment:
15-0
CS
DS
SS
ES
FS
GS

3)R Status-program si control (31-0)
EFLAGS
*Marcatori Status Flag:
CF (bit 0) = Carry Flag -> transport/imprumut
PF (bitul 2) = Parity Flag -> cel mai putin semnificativ octet din cadrul rezultatului are un numar par de biti de 1.
ZF (bitul 6) = Zero flag -> rezultatul este zero.
SF (bitul 7) = Sign flag -> semnul al unui numar intreg cu semn (0=pozitiv,1=negativ).
OF (bitul 11) = Overflow flag -> eroare de depasire in cadrul aritmeticii cu numere intregi cu semn.

4)Instruction pointer (31-0)
EIP
*/

///Comenzi
/*
Comenzi:
1.  Moving data:				MOV		dest, source	// dest <- source.
2.  Exchange:					XCHG	dest, source	// temp <- dest; dest <- source; source <- temp.
3.  Integer add:				ADD		dest, source	// dest <- (dest+source).
4.  Substract:					SUB		dest, source	// dest <- (dest-source).
5.  Increment:					INC		dest			//dest	<- ( dest + 1).
6.  Decrement:					DEC		dest			//dest <- ( dest - 1).
7.  Negate:						NEG		dest			//dest <- (-dest).
8.  Bitwise logical not:		NOT		dest			//dest <- C1(dest).
9.  Bitwise logical and:		AND		dest, source	//dest <- (dest & source).
10.	Bitwise logical or:			OR		dest, source	//dest <- (dest | source).
11.	Bitwise logical xor:		XOR		dest, source	//dest <- (dest ^ source).
12. Logical compare:			TEST	operand1, operand2 //Computes the Bitwise logical AND between the two operands and sets the SF, ZF and PF. The result is then discarded.
Shift Instructions: The last bit shifted beyond the destination boundary are shifted into the cary flag, then discarded.
The count operand can be the CL register or an immediate value.
There is no difference between SAL and SHL
13. Shift arithm. right:		SAR		signed_dest, count		// signed_dest <- (signed_dest >> (count%32)).
14. Shift logic right:			SHR		unsigned_dest, count	// unsigned_dest <- (unsigned_dest >> (count%32)).
15. Shift arithm. left:			SAL		dest, count		// dest <- (dest << (count%32)).
16. Shift logic. left:			SHL		dest, count		// dest <- (dest << (count%32)).
17. Rotate right:				ROR		dest, count		// Rotate dest bits count%32 times to the right.
17. Rotate left:				ROL		dest, count		// Rotate dest bits count%32 times to the left.
18. Rotate right including CF:	RCR		dest, count		// The RCR instruction shifts the CF flag into the most-significant bit and shifts the least-significant bit into the CF flag
19. Rotate left including CF:   RCL		dest, count		// The RCL instruction shifts the CF flag into the least-significant bit and shifts the most-significant bit into the CF flag

20. Unsigned multiply:			MUL		source2			// destination <- source1 * source2;
21. Unsigned divide				DIV		divizor			// divident = quotient * divizor + remainder

22. Signed multiply:
- IMUL r/m (The same as MUL instruction)
- IMUL r, r/m (First operand = first operand*second operand)
- IMUL r, r/m, imm
*/


void main()
{
	char *s = "Maimutica mica";
	int number=0;
	_asm
	{
		MOV EAX, s
		MOV ECX, 0
		MOV EDX, 0
		_while:
			MOV BL, [EAX+ECX]
			CMP BL, '\0'
			JE _end_while
			CMP BL, 'a'
				JNE _next
			INC EDX
			_next:
			INC ECX
			JMP _while 
		_end_while:
		MOV number, EDX

	}
	cout << number << '\n';
	system("pause");
	return;
}