#include "stdafx.h"
#include "Triunghi.h"
typedef unsigned int ui;
#pragma warning(disable:4996)

Triunghi::Triunghi(int x1, int y1, int x2, int y2, int x3, int y3)
{
	X1 = x1;
	X2 = x2;
	X3 = x3;
	Y1 = y1;
	Y2 = y2;
	Y3 = y3;
}

double Triunghi::ComputeArea()
{
	double A, B, C;
	A = sqrt(double((X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2)));
	B = sqrt(double((X2 - X3)*(X2 - X3) + (Y2 - Y3)*(Y2 - Y3)));
	C = sqrt(double((X3 - X1)*(X3 - X1) + (Y3 - Y1)*(Y3 - Y1)));
	double p = (A + B + C) / 2;
	//cout <<A<<' '<<B<<' '<<C<<' '<<p << "  ";
	double area = sqrt(abs(p*(p - A)*(p - B)*(p - C)));
	return area;
}

const char *Triunghi::GetName()
{
	char *tt = new char[10];
	strcpy(tt, "Triunghi:");
	return tt;
}