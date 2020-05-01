// C-rev23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

char *mystring = "--->Today is not the end of the world.<---";

char *dostuff(char *data, int number)
{
	static int ceva_la_nimereala = 0x01020304;
	char *backup = new char[strlen(data) - (number << 1) + 1];
	memcpy(backup, data + number, strlen(data) - number);
	memcpy(backup + strlen(data) - (number << 1), data + strlen(data), 1);
	ceva_la_nimereala++;
	return backup;
}

int main(void)
{
	char *myptr[2] = { (char*)&main, (char*)&main};
	int some_number;
	int start_point;
	int previous;
	int result;
	int i;

	for (i = 0; i<2; i++)
	{
		do{
			myptr[0]++;
		} while (*(int*)myptr[0] != 1043148077);
	}

	for (i = 0; i<2; i++)
	{
		do{
			myptr[1]++;
		} while (*(int*)myptr[1] != 16909060);
	}

	some_number = (int)myptr[1];
	start_point = (int)myptr[0] & 0xFFFF0000;

	previous = 0;
	do{
		if (((*(int*)start_point) & 0xFFFFFF) == 0xEC8B55)
			previous = start_point;
		start_point++;
	} while (*(int*)start_point != some_number);

	((void(*)(int, int))previous)((int)myptr[0], sizeof(int));
	__asm{
		push eax
	}

	printf("Rezultatul este: [%s]\n");

	return 0;
}
