// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

//ifstream f("input.txt");
//ofstream g("output.txt");
FILE *F;
void bubblesort(int v[], int n)
{
	int ok = 1;
	while (ok)
	{
		for (int j = 0; j < n - 1; j++)
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j+1]);
				ok = 0;
			}
	}
}
int main()
{
	F=fopen("input.txt", "r");
	char s[20];
	int v[1000];
	int x, i=0;
	while (!feof(F))
	{
		fscanf(F, "%s", s);
		x = atoi(s);
		v[i] = x;
		i++;
		strcpy(s, "\0");
	}
	for (int j = 0; j < i; j++)
		cout << v[j] << ' ';
	cout<<"\n";
	bubblesort(v, i);
	for (int j = 0; j < i; j++)
		cout << v[j] << ' ';
	return 0;



}

