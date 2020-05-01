﻿#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
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

///JUMP
/*
CMP			compare
JCC			salt conditionat
--testarea egalitatii
JE/JZ		Jump if equal/zero
JNE/JNZ		Jump of not equal/zero
--fara semn
JA/JNBE		Jump if above/not below or equal
JAE/JNB		Jump if above or equal/not below
JB/JNAE		Jump if below/not above or equal
JBE/JNA		Jump if below or qual/not above
--cu semn
JG/JNLE		Jump if greater/not lower or equal
JGE/JNL		Jump if greater or equal/not lower
JL/JNGE		Jump if lower/not greater or equal
JLE/JNG		Jump if lower or qual/not greater
--flag test
JC			Jump if carry
JNC			Jump if not carry
JO			Jump if overflow
JNO			Jump if not overflow
JS			Jump if sign(negative)
JNS			Jump if not sign(non-neg)
JPO/JNP		Jump if parity odd
JPE/JP		Jump if parity even
-- ++++
JECXZ		Jump when register ECX is zero
JCXZ		Jump when register CX is zero
-- Loop operations (using ECX or CX as counter)
LOOP		Decrement count and jump if count <> 0
LOOPE		Decrement count and jump if count <> 0 and ZF=1
LOOPZ		Decrement count and jump if count <> 0 and ZF=1
LOOPNE		Decrement count and jump if count <> 0 and ZF=0
LOOPNZ		Decrement count and jump if count <> 0 and ZF=0
RDTSC		Read TimeStamp Counter (EDX:EAX)
CLD			Clear Direction Flag (operatiile cu stringuri incrementeaza registrii index ESI/EDI)
STD			Set Direction Flag (operatiile cu stringuri decrementeaza registrii index ESI/EDI)
-- Salt neconditionat
JMP		<label>		Jump
*/

///++JUMP **
/*
LODS/B/W/D					Load String
MOV AL/AX/EAX, [ESI]
ADD/SUB ESI,1/2/4
REP LODS/B/W/D				SE REPETA INSTRUCTIUNEA LODS/B/W/D DE ECX ORI

STOS/B/W/D					Store string
MOV [EDI], AL/AX/EAX
ADD/SUB ESI,1/2/4
REP STOS/B/W/D				SE REPETA INSTRUCTIUNEA LODS/B/W/D DE ECX ORI

MOVS/B/W/D					Move data from String to String
MOV TEMP, BYTE/WORD/DWORD PTR [ESI]
ADD/SUB ESI, 1/2/4
MOV BYTE/WORD/DWORD PTR [EDI], TEMP
ADD/SUB EDI, 1/2/4
REP MOVS/B/W/D				SE REPETA INSTRUCTIUNEA MOVS/B/W/D DE ECX ORI

SCAS/B/W/D					Scan String
CMP AL/AX/EAX, [EDI]
PUSHFD
ADD/SUB EDI, 1/2/4
POPFD
REPE/REPNE SCAS/B/W/D		SE REPETA INSTRUCTIUNEA SCAS/B/W/D DE MAXIM ECX ORI, CAT TIMP ZF=1 (REPE)/ZF=0(REPNE)

CMPS/B/W/D					Compare String Operands
MOV TEMP, BYTE/WORD/DWORD PTR [ESI]
CMP TEMP, BYTE/WORD/DWORD PTR [EDI]
PUSHFD
ADD/SUB ESI, 1/2/4
ADD/SUB EDI, 1/2/4
POPFD
REPE/REPNE CMPS/B/W/D		SE REPETA INSTRUCTIUNEA CMPS/B/W/D DE MAXIM ECX ORI, CAT TIMP ZF=1 (REPE)/ZF=0(REPNE)
*/

#define newline f1();
void f1()
{
	cout << '\n';
}
//suma elementelor pare dintr un vector
int sumapare(int *, int) //pointer catre vector si nr elemente
{
	int suma = 0;
	_asm
	{

		MOV EBX, [EBP+8]  //retinem vectorul in EBX (Este pointer-dinamic deci merge cu MOV)
		MOV ESI, [EBP+12] //retinem numarul de elemente in ESI
		//MOV EDI, 2 // pt verif paritate
		MOV ECX, 0 //parcurgere
		///EAX: numarul pe care trebuie sa il verificam daca e par
		///EDX: restul
		///In EBP+8 se retine primul argument al functiei, iar in EBP+12 al doilea
		_drumul_vietii_ne_desparte: //for
		CMP ECX, ESI 
			JGE _end_of_road //i mai mare/egal decat nr ellemente
			MOV EAX, [EBX+4*ECX] //retine in EAX elementul
			MOV EDX, 0 //restul
			MOV EDI, 2 //
			DIV EDI //imparte EAX la EDI (numarul de pe pozitia ECX la 2)
			CMP EDX, 0 
			JNE _no_suma //daca restul nu este 0, numarul e impar deci nu modifica suma
				MOV EDI, suma //folosesc tot EDI ca registru temporar pentru retinerea si actualizarea sumei
				MOV EAX, [EBX+4*ECX] //pune din nou in EAX elementul de pe pozitia ECX (pt ca la impartirea cu 2 s-a modificat EAX cu rezultatul)
				ADD EDI, EAX //actualizeaza suma
				MOV suma, EDI
			_no_suma:
			INC ECX //creste i-ul
			JMP _drumul_vietii_ne_desparte //reia for-ul
		_end_of_road:
		MOV EAX, suma // echivalent cu return suma; (o functie returneaza valoarea din EAX daca nu are alt return)

	}
}
void main()
{
	int v[100];
	int s = 0;
	int nrelem;
	cin >> nrelem;
	for (int i = 0; i < nrelem; i++)
		cin >> v[i];
	s = sumapare(v, nrelem);
		cout << s;
#ifdef newline
	newline;
#endif
	system("pause");
	return;
}