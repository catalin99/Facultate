// C-rev21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#pragma pack(1)
struct Data{
	int data1;
	char data2;
	int data3;
	char data4;
};

int main(void)
{
	HANDLE f1;
	DWORD write, read;
	DWORD fsize;
	char *dat_arr;
	int i;
	int k;
	printf("%d\n", sizeof(Data));

	dat_arr = new char[5*sizeof(Data)];
	k = 65;
	
	f1 = CreateFile("structuri.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(f1, dat_arr, GetFileSize(f1,0), &write, NULL);
	CloseHandle(f1);
	//cititi fisierul intr-un buffer char* buffer, alocand bufferul dupa size-ul fisierului
	//castati bufferul la tipul de data al structurii sa-l puteti referi sub forma de array
	//verificati ce se gaseste la urmatoarele 2 pozitii:
	//1. *(int*)(buffer+20)
	//2. *(unsigned short*)(buffer+45)

	printf( "%d\n",*(int*)(dat_arr + 20));
	printf("%d\n",*(unsigned short*)(dat_arr+45));
	//unde-i problema?
	
	delete dat_arr;
}
