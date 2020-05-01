/* Tema0.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" */
#include <iostream>
#include <random>
#include <climits>
#include <cmath>

#define PI 3.14159265359

double DeJong1(unsigned int nrDim)
{
	double x, sum = 0;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> dist(-5.12, 5.12);
	for (unsigned int i = 1; i <= nrDim; i++)
	{
		x = dist(mt);
		sum += x*x;
	}
	return sum;
}

double Schwefel7(unsigned int nrDim)
{
	double x, sum = 0;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> dist(-500, 500);
	for (unsigned int i = 1; i <= nrDim; i++)
	{
		x = dist(mt);
		sum += - x*sin(sqrt(abs(x)));
	}
	return sum;
}

double Rastrigin6(unsigned int nrDim)
{
	double x, sum = 0;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> dist(-5.12, 5.12);
	for (unsigned int i = 1; i <= nrDim; i++)
	{
		x = dist(mt);
		sum += pow(x,2) - 10 * cos(2 * PI *x );
	}
	return (10 * nrDim + sum);
}

double SixCamel()
{
	double x1, x2, val;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> dist(-3, 3);
	std::uniform_real_distribution<> dist2(-2, 2);
	x1 = dist(mt);
	x2 = dist2(mt);
	val = (4 - 2.1*pow(x1, 2) + pow(x1, 4)/3)*pow(x1, 2) + x1*x2 + (-4 + 4 * pow(x2, 2))*pow(x2, 2);
	return val;
}

double min_rulare(unsigned int nrDim, short functie, unsigned int generari)
{
	double min = std::numeric_limits<double>::max();
	if(functie==1)
		for (unsigned int i = 1; i <= generari; i++)
		{
			if (min > DeJong1(nrDim))
				min = DeJong1(nrDim);
		}
	else if(functie==2)
		for (unsigned int i = 1; i <= generari; i++)
		{
			if (min > Schwefel7(nrDim))
				min = Schwefel7(nrDim);
		}
	else if(functie==3)
		for (unsigned int i = 1; i <= generari; i++)
		{
			if (min > Rastrigin6(nrDim))
				min = Rastrigin6(nrDim);
		}
	else
		for (unsigned int i = 1; i <= generari; i++)
		{
			if (min > SixCamel())
				min = SixCamel();
		}
	return min;
}

int main()
{
	unsigned int nrDim,rulari,generari;
	short functie;
	std::cout << "Pentru ce functie doriti sa calculati minimul?\nOptiuni:\n1 pentru De Jong 1\n2 pentru Schwefel 7\n3 pentru Rastrigin 6\n4 pentru Six-hump camel back\n";
	std::cin >> functie;
	if (functie == 4)
		nrDim = 2;
	else
	{
		std::cout << "Introduceti numarul de dimensiuni ale functiei : ";
		std::cin >> nrDim;
	}
	std::cout << "De cate ori doriti sa rulati algoritmul?\n";
	std::cin >> rulari;
	std::cout << "De cate ori doriti sa generati parametrii functiei intr-o rulare?\n";
	std::cin >> generari;
	double min = min_rulare(nrDim, functie, generari);
	for (unsigned int i = 2; i <= rulari; i++)
	{
		if (min > min_rulare(nrDim, functie, generari))
			min = min_rulare(nrDim, functie, generari);
	}
	std::cout << "Minim = " << min<<'\n';
	return 0;
}
