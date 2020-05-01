#include <iostream>
#include <math.h>
#include <random>
#include <time.h>
#include "RandomGenerator.h"


#define ui unsigned int
#define PI 3.14159265359

#define FUNCTION DeJong(xArray, x_count)

#define MIN_FINDER MinFinder(5)
#define MIN_FINDER2 MinFinder2()

#define LOW_LIMIT -5.12
#define HIGH_LIMIT 5.12
#define NUMBER_OF_RAND_GENS 1000
#define NUMBER_OF_RUNS 100


using namespace std;


// x_array contine valorile variabilelor x
// x_count reporezinta numarul de variabile x (numarul n din formula)

// -5.12 <= x <= 5.12
// min = 0
double DeJong(double* x_array, ui x_count)
{
	
	if (x_array == nullptr)
	{ 
		cout << "Null x_array." << endl << endl;
		return 0;
	}

	double result = 0;
	for (ui i = 0; i < x_count; i++)
	{
		result += x_array[i] * x_array[i];
	}

	return result;

}

// -500 <= x <= 500
// min = -x_count * 418.9829
double Schwefel(double* x_array, ui x_count)
{

	if (x_array == nullptr)
	{
		cout << "Null x_array." << endl << endl;
		return 0;
	}

	double result = 0;
	for (ui i = 0; i < x_count; i++)
	{
		result -= x_array[i] * sin(sqrt(abs(x_array[i])));
	}

	return result;

}

// -5.12 <= x <= 5.12
// min = 0
double Rastrigin(double* x_array, ui x_count)
{

	if (x_array == nullptr)
	{
		cout << "Null x_array." << endl << endl;
		return 0;
	}

	double result = 10 * x_count;
	for (ui i = 0; i < x_count; i++)
	{
		result += x_array[i] * x_array[i] - 10 * cos(2 * PI * x_array[i]);
	}

	return result;

}

// -3 <= x1 <= 3
// -2 <= x2 <= 2
// min = -1.0316
double SixHumpCamelBack(double* x_array)
{

	if (x_array == nullptr)
	{
		cout << "Null x_array." << endl << endl;
		return 0;
	}

	double result = (4 - 2.1 * pow(x_array[0], 2) + pow(x_array[0], 1.33))*pow(x_array[0], 2) + x_array[0] * x_array[1] + (-4 + 4 * pow(x_array[1], 2)) * pow(x_array[1], 2);
	
	return result;

}



double MinFinder(ui x_count)
{
	double* xArray = new double[x_count];
	for (ui i = 0; i < x_count; i++)
	{
		RandomGenerator randNum(LOW_LIMIT, HIGH_LIMIT);
		xArray[i] = randNum.GetNumber();
	}

	double min = FUNCTION;

	double aux;

	for (ui i = 1; i < NUMBER_OF_RAND_GENS; i++)
	{
		for (ui j = 0; j < x_count; j++)
		{
			RandomGenerator randNum(LOW_LIMIT, HIGH_LIMIT);
			xArray[j] = randNum.GetNumber();
		}
		aux = DeJong(xArray, x_count);
		if (aux < min)
			min = aux;

	}

	delete[](xArray);

	return min;
	
}

double MinFinder2()
{
	double* xArray = new double[2];

	RandomGenerator randNum(-3, 3);
	xArray[0] = randNum.GetNumber();
	RandomGenerator randNum1(-2, 2);
	xArray[1] = randNum1.GetNumber();
	
	double min = SixHumpCamelBack(xArray);

	double aux;

	for (ui i = 1; i < NUMBER_OF_RAND_GENS; i++)
	{
		RandomGenerator randNum2(-3, 3);
		xArray[0] = randNum2.GetNumber();
		RandomGenerator randNum3(-2, 2);
		xArray[1] = randNum3.GetNumber();

		aux = SixHumpCamelBack(xArray);
		if (aux < min)
			min = aux;

	}

	delete[](xArray);

	return min;
}



int main()
{

	double min = MIN_FINDER;
	double aux;

	for (ui i = 1; i < NUMBER_OF_RUNS; i++)
	{
		aux = MIN_FINDER;
		if (aux < min)
			min = aux;
	}

	cout << "Numare generate:" << NUMBER_OF_RAND_GENS << endl;
	cout << "Numar rulari:" << NUMBER_OF_RUNS << endl;

	cout << endl << "Rezultat: " << min << endl;


	system("pause");
}