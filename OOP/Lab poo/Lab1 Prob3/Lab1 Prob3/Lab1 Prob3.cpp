// Lab1 Prob3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef unsigned int ui;
#define MAXSIZE 255
#pragma warning(disable:4996)

char MoreThanTen(unsigned int number)
{
	if (number == 10)
		return 'A';
	if (number == 11)
		return 'B';
	if (number == 12)
		return 'C';
	if (number == 13)
		return 'D';
	if (number == 14)
		return 'E';
	if (number == 15)
		return 'F';
	return '\0';
}

bool Convert(unsigned int number, unsigned int toBase, char * result, unsigned int resultMaxSize)
{
	if (resultMaxSize > MAXSIZE)
		return false;
	if (toBase > 16 || toBase < 2)
		return false;
	ui x, i=0;
	char temp[5];
	while (number)
	{
		x = number % toBase;
		//strcpy(temp, '\0');
		if (x >= 10)
			result[i++] = MoreThanTen(x);
		else
		{
			itoa(x, temp, 10);
			result[i++] = temp[0];
		}
		result[i] = '\0';

		number /= toBase;
	}
	for (i = 0; i < (strlen(result)) / 2; i++)
		swap(result[i], result[strlen(result) - i - 1]);
	return true;
}

int main()
{
	char sss[MAXSIZE];
	strcpy(sss, "eroare");
	Convert(411, 16, sss, MAXSIZE);
	cout << sss<<'\n';
    return 0;
}

