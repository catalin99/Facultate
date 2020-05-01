// Tema0.cpp : Defines the entry point for the console application.
//
//[GA]_TEMA1_CATALIN_BELU_IIA6
//#include "stdafx.h"
#include <iostream>
#include <random>
//#include <climits>
#include <cmath>
using namespace std;
#define PI 3.14159265359

//random_device is a uniformly-distributed integer random number generator that produces non-deterministic random numbers.
//A Mersenne Twister 19937 pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
//Produces random floating-point values i, uniformly distributed on the interval [a, b), that is, distributed according to the probability density function:
//P(i | a, b) =1/(b-a)

double DeJong1(unsigned int params)
{
	//The simplest test function is De Jong's function 1. It is also known as sphere model. It is continuos, convex and unimodal.
	//suma dupa i de la 1 la n din (x de i)^2
	//min global 0
	double x, sum = 0;
	random_device rd; //seed
	mt19937 mt(rd()); //rand // mersenne trebuie aplicat de doua ori pentru a fi mult mai precis
	uniform_real_distribution<> dist(-5.12, 5.12); //-5.12<xi<5.12
	for (unsigned int i = 1; i <= params; i++)
	{
		x = dist(mt);
		sum += x * x;
	}
	return sum;
}

double Schwefel7(unsigned int params)
{
	//Schwefel's function [Sch81] is deceptive in that the global minimum is geometrically distant, 
	//over the parameter space, from the next best local minima. 
	//Therefore, the search algorithms are potentially prone to convergence in the wrong direction.
	//suma dupa i de la 1 la n din [-(x de i) * sin (sqrt din abs(x de i))]
	//min global: f(x)=-n·418.9829; x(i)=420.9687, i=1:n.
	double x, sum = 0;
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<> dist(-500, 500); //-500<=x(i)<=500
	for (unsigned int i = 1; i <= params; i++)
	{
		x = dist(mt);
		sum += -x * sin(sqrt(abs(x)));
	}
	return sum;
}

double Rastrigin(unsigned int params)
{
	//Rastrigin's function is based on function 1 with the addition of cosine modulation to produce many local minima. 
	//Thus, the test function is highly multimodal. 
	//However, the location of the minima are regularly distributed.
	//min global 0
	double x, sum = 0;
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<> dist(-5.12, 5.12);
	for (unsigned int i = 1; i <= params; i++)
	{
		x = dist(mt);
		sum += pow(x, 2) - 10 * cos(2 * PI *x);
	}
	return (10 * params + sum);
}

double SixCamel()
{
	//The 2-D Six-hump camel back function [DS78] is a global optimization test function. 
	//Within the bounded region are six local minima, two of them are global minima
	//Min global: f(x1,x2)=-1.0316; (x1,x2)=(-0.0898,0.7126),(0.0898,-0.7126).
	double x1, x2, val;
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<> dist(-3, 3);
	uniform_real_distribution<> dist2(-2, 2);
	x1 = dist(mt);
	x2 = dist2(mt);
	val = (4 - 2.1*pow(x1, 2) + pow(x1, 4) / 3)*pow(x1, 2) + x1 * x2 + (-4 + 4 * pow(x2, 2))*pow(x2, 2);
	return val;
}

double min_rulare(unsigned int params, short algorithm, unsigned int NrGen)
{
	double Minim = DBL_MAX;
	if (algorithm == 1)
		for (unsigned int i = 1; i <= NrGen; i++)
		{
			if (Minim > DeJong1(params))
				Minim = DeJong1(params);
		}
	else if (algorithm == 2)
		for (unsigned int i = 1; i <= NrGen; i++)
		{
			if (Minim > Schwefel7(params))
				Minim = Schwefel7(params);
		}
	else if (algorithm == 3)
		for (unsigned int i = 1; i <= NrGen; i++)
		{
			if (Minim > Rastrigin(params))
				Minim = Rastrigin(params);
		}
	else
		for (unsigned int i = 1; i <= NrGen; i++)
		{
			if (Minim > SixCamel())
				Minim = SixCamel();
		}
	return Minim;
}

int main()
{
	unsigned int params, rulari, NrGen;
	short algorithm;
	cout << "Alegeti functia: \n1=De Jong 1\n2=Schwefel 7\n3=Rastrigin\n4=Six-hump camel back\n";
	cin >> algorithm;
	if (algorithm == 4)
		params = 2;
	else
	{
		cout << "Dimensiunea functiei: \n";
		cin >> params;
	}
	cout << "Numarul de rulari\n";
	cin >> rulari;
	cout << "Numarul de generari ai parametrilor intr-o singura rulare\n";
	cin >> NrGen;
	double minim = min_rulare(params, algorithm, NrGen);
	for (unsigned int i = 2; i <= rulari; i++)
	{
		if (minim > min_rulare(params, algorithm, NrGen))
			minim = min_rulare(params, algorithm, NrGen);
	}
	cout << "Minim = " << minim << '\n';
	system("pause");
	return 0;
}