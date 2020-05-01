// Lab1 Prob2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

#define MATRIX_HEIGHT 6
#define MATRIX_WIDTH 5
int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
void Circle(int* ptr, int cx, int cy, int ray) {
	//D(P1,P2) = SQRT ((P1.x - P2.x)*(P1.x - P2.x)+(P1.y - P2.y)*(P1.y - P2.y))
	int op1, op2, p1, p2;
	float dist;
	for(int i=0; i<MATRIX_HEIGHT; i++)
		for (int j = 0; j < MATRIX_WIDTH; j++)
		{
			op1 = abs(i - cx);
			p1 = op1 * op1;
			op2 = abs(j - cy);
			p2 = op2 * op2;
			dist = p1 + p2;
			dist = ceil(sqrt(dist));
			if (dist == ray)
				ptr[i*MATRIX_WIDTH+j] = 1;
			//cout << *(ptr+i*MATRIX_WIDTH+j) << '\n';
			//cout << ptr+i*MATRIX_WIDTH+j << '\n'; //adresa
			//cout << element << endl;
		}
}
void main() 
{
	Circle(&Matrix[0][0], 2, 2, 2);
	cout << '\t';
	for (int i=0; i<MATRIX_HEIGHT; i++)
	{
		for (int j = 0; j < MATRIX_WIDTH; j++)
			cout << Matrix[i][j] << "  ";
		cout << "\n \n \t";
	}
}


