// Tema1.1GA.cpp : Defines the entry point for the console application.


#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>
#include <functional>

#define pi 3.14159265

using namespace std;

int Matrix[30][30];
long long seed = rand() % 31;
long long trand = rand() % 47; //nr prim
double Value[35];


struct Between {
	double a;
	double b;
};

double TransformInValue(int v[], int NrBites) {
	double result = 0;

	for (int i = 0; i < NrBites; i++) {
		if (v[i] == 1) {
			result += pow((double)2, NrBites - i - 1);
		}
	}

	return result;
}

int Number_Of_Bites(Between AtoB, int Precizie) {
	double nrIntervale;
	double difference = AtoB.b - AtoB.a;
	nrIntervale = difference * pow((double)10, Precizie);
	double NrBites;
	NrBites = log((double)nrIntervale);
	int nrfinalBites = (int)NrBites + 1;
	return nrfinalBites;
}


void RandomHelper()
{

	//cout << seed << ' ';
	long long d = sqrt(seed);
	trand /= 2;
	seed = seed + d + trand;
	seed = abs(seed);
	long long mod = seed % 13;
	switch (mod) //+/- prime numbers
	{
	case 0:
		trand -= 5;
		break;
	case 1:
		trand += 19;
		break;
	case 2:
		trand += 7;
		break;
	case 3:
		trand += 43;
		break;
	case 4:
		trand -= 19;
		break;
	case 5:
		trand += 23;
		break;
	case 6:
		trand += 61;
		break;
	case 7:
		trand -= 11;
		break;
	case 8:
		trand += 13;
		break;
	case 9:
		trand -= 17;
		break;
	case 10:
		trand += 53;
		break;
	case 11:
		trand += 37;
		break;
	case 12:
		trand -= 29;
		break;
	default:
		trand -= 1;
		break;
	}
	//cout << seed << '\n';
}

int CreateMatrix(Between Interval, int Precizie, int NrParams) {
	int nrBITES = Number_Of_Bites(Interval, Precizie);
	for (int i = 0; i < NrParams; i++) {
		for (int j = 0; j < nrBITES; j++)
		{
			//srand(time(NULL));
			RandomHelper();
			srand(seed);
			Matrix[i][j] = rand() % 2;
		}
	}
	return nrBITES;
}

void getParams(int Matrix[30][30], int NrBites, int numarparametri, Between Interval) {
	for (int i = 0; i < numarparametri; i++) {
		Value[i] = Interval.a + TransformInValue(Matrix[i], NrBites) * (Interval.b - Interval.a) / (pow((double)2, NrBites) - 1);
	}
}

double DeJong(int Matrix[30][30], int NrBites, int NrParams, Between Interval) {

	double s = 0;
	getParams(Matrix, NrBites, NrParams, Interval);
	for (int i = 0; i < NrParams; i++)
		s = s + Value[i] * Value[i];
	return s;
}

double Schwefel(int Matrix[30][30], int NrBites, int NrParams) {
	double s = 0;
	Between Interval;
	Interval.a = -500;
	Interval.b = 500;
	getParams(Matrix, NrBites, NrParams, Interval);
	for (int i = 0; i < NrParams; i++)
		s = s - Value[i] * sin(sqrt(abs(Value[i])));
	return s;
}

double Rastrigin(int Matrix[30][30], int NrBites, int NrParams, Between Interval) {
	double s = 0;
	getParams(Matrix, NrBites, NrParams, Interval);
	for (int i = 0; i < NrParams; i++)
		s = s + (Value[i] * Value[i] - 10 * cos(2 * pi*Value[i]));
	s = 10 * NrParams + s;
	return s;
}

double SixHumpCamelBack(int Matrix[30][30], int NrBites, int Params)
{
	Between Interval;
	Interval.a = -3;
	Interval.b = 2;
	getParams(Matrix, NrBites, Params, Interval);
	return (4 - 2.1*Value[0] * Value[0] + pow(Value[0], 4) / 3)*Value[0] * Value[0] + Value[0] * Value[1] + (-4 + 4 * Value[1] * Value[1])*Value[1] * Value[1];
}

double HillClimbing_FirstImprovement(int Iterations, int id)
{
	Between Interval;
	double NrBites, min_fitness, fitness, min = 1000;
	int numarparametri, schimbat = 1, min_hilltop = 0, bit_position = 0, hilltop = 0, Precizie;
	double fminim[31]; int it = -1;
	double worstminim = -100000;
	if (id == 1 || id == 2 || id == 3)
	{
		cout << "Introduceti numarul de valori: ";
		cin >> numarparametri;
	}
	else
	{
		cout << "Aceasta functie are ca numar de parametri prestabiliti, valoarea 2\n";
		numarparametri = 2;
	}

	cout << "Introduceti precizia: " << endl;
	cin >> Precizie;

	if (id == 1) {
		Interval.a = -5.12;
		Interval.b = 5.12;
	}
	else if (id == 2) {
		Interval.a = -500;
		Interval.b = 500;
	}
	else if (id == 3) {
		Interval.a = -5.12;
		Interval.b = 5.12;
	}
	else
	{
		Interval.a = -3;
		Interval.b = 2;
	}

	int parcurgeri;
	for (parcurgeri = 1; parcurgeri <= 30; parcurgeri++)
	{
		if (id == 1 || id == 2 || id == 3)
			NrBites = CreateMatrix(Interval, Precizie, numarparametri);
		else
			NrBites = CreateMatrix(Interval, Precizie, 2);
		if (id == 1)
			min_fitness = DeJong(Matrix, NrBites, numarparametri, Interval);
		else if (id == 2)
			min_fitness = Schwefel(Matrix, NrBites, numarparametri);
		else if (id == 3)
			min_fitness = Rastrigin(Matrix, NrBites, numarparametri, Interval);
		else
			min_fitness = SixHumpCamelBack(Matrix, NrBites, numarparametri);
		for (int iteratii = 0; iteratii < Iterations; iteratii++) {

			for (int i = 0; i < numarparametri; i++) {
				for (int j = 0; j < NrBites; j++)
				{
					RandomHelper();
					srand(seed);
					hilltop = rand() % (numarparametri + 1);
					RandomHelper();
					srand(seed);
					bit_position = rand() % ((int)NrBites + 1);

					if (Matrix[hilltop][bit_position] == 0)
						Matrix[hilltop][bit_position] = 1;
					else
						Matrix[hilltop][bit_position] = 0;

					if (id == 1)
						fitness = DeJong(Matrix, NrBites, numarparametri, Interval);
					else if (id == 2)
						fitness = Schwefel(Matrix, NrBites, numarparametri);
					else if (id == 3)
						fitness = Rastrigin(Matrix, NrBites, numarparametri, Interval);
					else
						fitness = SixHumpCamelBack(Matrix, NrBites, numarparametri);

					if (fitness < min_fitness) {
						schimbat = 0;
						min_fitness = fitness;
					}
					else {
						if (schimbat == 1) {
							schimbat = 0;
							if (Matrix[hilltop][bit_position] == 0)
								Matrix[hilltop][bit_position] = 1;
							else
								Matrix[hilltop][bit_position] = 0;
						}
					}
				}
			}
		}
		fminim[++it] = min_fitness;
	}
	for (int i = 0; i < 30; i++)
	{
		//cout << fminim[i] << endl;
		if (min > fminim[i])
			min = fminim[i];
		if (worstminim < fminim[i])
			worstminim = fminim[i];
	}
	cout << min << " " << worstminim;
	return min;
}

double HillClimbing_BestImprovement(int Iterations, int id)
{
	bool decrease_found;
	Between Interval;
	double NrBites, min_fitness, fitness, min = 1000;
	int numarparametri, schimbat = 1, min_hilltop = 0, bit_position = 0, hilltop = 0, Precizie;
	double fminim[31]; int it = -1;
	double worstminim = -10000;
	if (id == 1 || id == 2 || id == 3)
	{
		cout << "Introduceti numarul de valori: ";
		cin >> numarparametri;
	}
	else
	{
		cout << "Aceasta functie are ca numar de parametri prestabiliti, valoarea 2\n";
		numarparametri = 2;
	}

	cout << "Introduceti precizia: " << endl;
	cin >> Precizie;

	if (id == 1) {
		Interval.a = -5.12;
		Interval.b = 5.12;
	}
	else if (id == 2) {
		Interval.a = -500;
		Interval.b = 500;
	}
	else if (id == 3) {
		Interval.a = -5.12;
		Interval.b = 5.12;
	}
	else
	{
		Interval.a = -3;
		Interval.b = 2;
	}
	int parcurgeri;
	for (parcurgeri = 1; parcurgeri <= 30; parcurgeri++)
	{
			NrBites = CreateMatrix(Interval, Precizie, numarparametri);
		if (id == 1)
			min_fitness = DeJong(Matrix, NrBites, numarparametri, Interval);
		else if (id == 2)
			min_fitness = Schwefel(Matrix, NrBites, numarparametri);
		else if (id == 3)
			min_fitness = Rastrigin(Matrix, NrBites, numarparametri, Interval);
		else
			min_fitness = SixHumpCamelBack(Matrix, NrBites, numarparametri);
		for (int iteratii = 0; iteratii < Iterations; iteratii++) {

			decrease_found = true;

			while (decrease_found) {

				decrease_found = false;

				for (int i = 0; i < numarparametri; i++)
				{
					for (int j = 0; j < NrBites; j++)
					{
						srand(time(NULL));
						RandomHelper();
						srand(seed);
						hilltop = rand() % (numarparametri + 1);
						RandomHelper();
						srand(seed);
						bit_position = rand() % ((int)NrBites + 1);

						if (Matrix[hilltop][bit_position] == 0)
							Matrix[hilltop][bit_position] = 1;
						else
							Matrix[hilltop][bit_position] = 0;

						if (id == 1)
							fitness = DeJong(Matrix, NrBites, numarparametri, Interval);
						else if (id == 2)
							fitness = Schwefel(Matrix, NrBites, numarparametri);
						else if (id == 3)
							fitness = Rastrigin(Matrix, NrBites, numarparametri, Interval);
						else
							fitness = SixHumpCamelBack(Matrix, NrBites, numarparametri);

						if (fitness < min_fitness) {
							schimbat = 0;
							min_fitness = fitness;
							decrease_found = true;
						}
						else {
							if (schimbat == 1) {
								schimbat = 0;
								if (Matrix[hilltop][bit_position] == 0)
									Matrix[hilltop][bit_position] = 1;
								else
									Matrix[hilltop][bit_position] = 0;
							}
						}

					}
				}
			}
		}

		fminim[++it] = min_fitness;
	}
	double sum = 0;
	for (int i = 0; i < 30; i++)
	{
		sum += fminim[i];
		if (min > fminim[i])
			min = fminim[i];
		if (worstminim < fminim[i])
			worstminim = fminim[i];
	}
	cout << min << " " << worstminim << " " << sum / 30;
	return min;
}

double Simulated_Annealing(int Iterations, int id) {
	Between Interval;
	double NrBites, min = 1000;
	double min_fitness, fitness, Temperatura = 10;
	int numarparametri, schimbat = 0, iteratii = 0, Precizie;
	int min_hilltop = 0, bit_position = 0, hilltop = 0;
	double fminim[1000]; int it = -1;
	double worstminim = -10000;
	if (id == 1) {
		Interval.a = -5.12;
		Interval.b = 5.12;
	}
	else if (id == 2) {
		Interval.a = -500;
		Interval.b = 500;
	}
	else if (id == 3) {
		Interval.a = -5.12;
		Interval.b = 5.12;
	}
	else
	{
		Interval.a = -3;
		Interval.b = 2;
	}

	if (id == 1 || id == 2 || id == 3)
	{
		cout << "Introduceti numarul de valori: ";
		cin >> numarparametri;
	}
	else
	{
		cout << "Aceasta functie are ca numar de parametri prestabiliti, valoarea 2\n";
		numarparametri = 2;
	}

	cout << "Introduceti precizia: " << endl;
	cin >> Precizie;

	int k;

	while (Temperatura > 0.1) {
		for (k = 1; k <= 30; k++)
		{
			if (id == 1 || id == 2 || id == 3)
				NrBites = CreateMatrix(Interval, Precizie, numarparametri);
			else
				NrBites = CreateMatrix(Interval, Precizie, 2);
			if (id == 1)
				min_fitness = DeJong(Matrix, NrBites, numarparametri, Interval);
			else if (id == 2)
				min_fitness = Schwefel(Matrix, NrBites, numarparametri);
			else if (id == 3)
				min_fitness = Rastrigin(Matrix, NrBites, numarparametri, Interval);
			else
				min_fitness = SixHumpCamelBack(Matrix, NrBites, numarparametri);
			for (iteratii = 0; iteratii < Iterations; iteratii++)
			{
				RandomHelper();
				srand(seed);
				hilltop = rand() % (numarparametri);
				RandomHelper();
				srand(seed);
				bit_position = rand() % ((int)NrBites);
				if (Matrix[hilltop][bit_position] == 0)
					Matrix[hilltop][bit_position] = 1;
				else
					Matrix[hilltop][bit_position] = 0;
				schimbat = 1;

				if (id == 1)
					fitness = DeJong(Matrix, NrBites, numarparametri, Interval);
				else if (id == 2)
					fitness = Schwefel(Matrix, NrBites, numarparametri);
				else if (id == 3)
					fitness = Rastrigin(Matrix, NrBites, numarparametri, Interval);
				else
					fitness = SixHumpCamelBack(Matrix, NrBites, numarparametri);

				if (fitness < min_fitness) {
					schimbat = 0;
					min_fitness = fitness;
				}
				else
				{
					RandomHelper();
					srand(seed);
					double probability = (double)rand() / (RAND_MAX + 1);
					double acceptance_probability = exp(-floor((fitness - min_fitness)) / Temperatura);

					if (probability < acceptance_probability) {
						schimbat = 0;
						min_fitness = fitness;
					}
					else {
						if (schimbat == 1) {
							schimbat = 0;
							if (Matrix[hilltop][bit_position] == 0)
								Matrix[hilltop][bit_position] = 1;
							else
								Matrix[hilltop][bit_position] = 0;
						}
					}
				}
				//Interval.a += 0.1; Interval.b -= 0.1;
			}
			fminim[++it] = min_fitness;
			Temperatura = Temperatura * 0.95;
		}

	}
	double suma = 0;
	for (int i = 1; i <= it; i++)
	{
		//cout << fminim[i] << endl;
		suma += fminim[i];
		if (min > fminim[i])
			min = fminim[i];
		if (worstminim < fminim[i])
			worstminim = fminim[i];
	}

	cout << min << " " << worstminim << " " << suma / it;
	return min;
}


int main()
{

	int FUNCTION, Algorithm, Iterations;
	short continua = 1;
	double result;
	srand(time(NULL));
	while (continua == 1) {
		cout << "Alegeti algoritmul cu care doriti sa rulati programul: \n\t1.Simulated Annealing \n\t2.Best Hill Climbing \n\t3.First Hill Climbing\n";
		cin >> Algorithm;

		cout << "Introduceti numarul de iteratii!\n ";
		cin >> Iterations;

		cout << "Alegeti functia pe care doriti sa o rezolvati: \n\t1.De Jong \n\t2.Schwefel \n\t3.Rastrigin \n\t4.Six Hump Camel \n";
		cin >> FUNCTION;

		switch (Algorithm) {
		case 1: {
			result = Simulated_Annealing(Iterations, FUNCTION);
			break;
		}
		case 2: {
			result = HillClimbing_BestImprovement(Iterations, FUNCTION);
			break;
		}
		case 3: {
			result = HillClimbing_FirstImprovement(Iterations, FUNCTION);
		}

		default: {
			break;
		}
		}

		cout << "\nNumarul de iteratii: " << Iterations << '\n';
		cout << "Rezultat: " << result << '\n';
		cout << "Doriti sa executati din nou? \n\t1=YES\n\t2=NO\n ";
		cin >> continua;
		if ((continua != 2) && (continua != 1)) {
			continua = 2;
		}

	}
	return 0;
}
