#include<iostream>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
int W = 1;
using namespace std;


float FunctiaDeJong(int n, float v[])
{
	float f = 0;
	for (int i = 0; i<n; i++)
		f = f + pow(v[i], 2);

	return f;
}

float FunctiaSchwefel(int n, float v[])
{
	float f = 0;
	for (int i = 0; i<n; i++)
		f = f + (-1)*v[i] * sin(sqrt(abs(v[i])));
	return f;

}

float FunctiaRastrigin(int n, float v[])
{
	float f = 0;
	for (int i = 0; i<n; i++)
		f = f + (v[i] * v[i]) - 10 * cos(2 * 3.14*v[i]);

	return float(f + 10 * n);
}

float interval(float a, float b)
{
	int n = (b - a) * 10;
	return n;
}

int superior(float a, float b)
{
	float n = interval(a, b);
	a = log10(n) / log10(2);
	if (a = int(a))
		return a;
	else return int(a) + 1;
}

void Generare(int v[], float a, float b, int dim)
{
	int m = superior(a, b);

	for (int i = 0; i<m*dim; i++)
		v[i] = ((2 - 0)*((float)rand() / RAND_MAX)) + 0;
}

void TransfBaza10(int v[], int n, float a, float b, float t[], int dim)
{
	int o = superior(a, b);
	for (int j = 0; j < dim; j++)
	{
		int x = 0;
		int p = 0;
		for (int i = superior(a, b) - 1; i >= 0; i--)
		{
			x = x + (v[i] * pow(2, p));
			p = p + 1;

		}

		t[j] = a + x*(b - a) / (pow(2, o) - 1);

		//stergem  primu numar din vector in biti
		for (int c = 0; c < superior(a, b); c++)
		{
			for (int k = 0; k < n; k++)
				v[k] = v[k + 1];

			n--;
		}

	}
}



float minimizare(int mat[][500], float x[], float fitnes, float fitnestotal, float minim, float probabilitate[], float vectorfitnes[], int dim,
	int functie, float a, float b, int nrcrom)
{

	float n = superior(a, b) * dim;
	float q[500];
	double y;
	int i, j, c[500];
	int parinte1, parinte2, cromparinte1[500], cromparinte2[500];
	float probcromozom, ratamutatie = 0.1, probelementmutatie, rataincrucisare = 0.7, probcromozomincrucisare;
	int nr = 0, pctrandom, pct1, pct2;
	int transformare[500];
	int matriceselectie[500][500];

	//calculam probabilitatea cromozomilor
	for (i = 0; i<nrcrom; i++)
	{
		probabilitate[i] = (vectorfitnes[i] / fitnestotal);

	}



	//roata norocului

	for (j = 0; j<nrcrom; j++)
	{
		y = ((1 - 0)*((float)rand() / RAND_MAX)) + 0;

		q[0] = 0;
		for (i = 0; i<nrcrom; i++)
		{
			q[i + 1] = q[i] + probabilitate[i];
		}
		for (i = 0; i<nrcrom; i++)
			if (q[i] < y && y <= q[i + 1])
			{
				//salvam linia la care se afla cromozomul ce indeplineste conditia 
				c[j] = i;
			}
	}




	//copiem cromozomii care indeplinesc conditia 
	for (i = 0; i<nrcrom; i++)
	{
		for (j = 0; j<n; j++)
			matriceselectie[i][j] = mat[c[i]][j];
	}



	//MUTATIE

	for (int i = 0; i<nrcrom; i++)
	{
		probcromozom = ((1 - 0)*((float)rand() / RAND_MAX)) + 0;

		if (probcromozom<ratamutatie)
		{
			srand(time(0));
			for (j = 0; j<n ;j++)
			{
				probelementmutatie = ((1 - 0)*((float)rand() / RAND_MAX)) + 0;


				if (probelementmutatie<ratamutatie)
					if (matriceselectie[i][j] == 0)
						matriceselectie[i][j] = 1;
					else
						matriceselectie[i][j] = 0;
			}
		}
	}


	//INCRUCISARE

	for (int i = 0; i<nrcrom; i++)
	{
		probcromozomincrucisare = ((1 - 0)*((float)rand() / RAND_MAX)) + 0;
		if (probcromozomincrucisare<rataincrucisare)
		{
			nr++;
			if (nr == 1)
				for (j = 0; j<n; j++)
				{
					cromparinte1[j] = matriceselectie[i][j];
					pct1 = i;
				}
			if (nr == 2)
			{
				for (j = 0; j<n; j++)
				{
					cromparinte2[j] = matriceselectie[i][j];
					pct2 = i;
					nr = 0;
				}

				//generam punctul de taiere

				pctrandom = rand() % (24 - 0 + 1) + 0;
				for (j = pctrandom; j<n; j++)
				{
					matriceselectie[pct1][j] = cromparinte2[j];
					matriceselectie[pct2][j] = cromparinte1[j];
				}
			}
		}
	}









	for (i = 0; i<nrcrom; i++)
	{
		for (j = 0; j<n; j++)
			transformare[j] = matriceselectie[i][j];

		TransfBaza10(transformare,n, a, b, x, dim);



		if (functie == 1)
		{
			fitnes = 1 / FunctiaRastrigin(dim, x);
		}

		if (functie == 2)
		{
			fitnes = 1 / FunctiaSchwefel(dim, x);
		}

		if (functie == 3)
		{
			fitnes = 1 / FunctiaDeJong(dim, x);

		}


		fitnestotal = fitnestotal + fitnes;
		vectorfitnes[i] = fitnes;

		if (fitnes<minim)
			minim = fitnes;

	}




	return minim;



}



int main()
{
	srand(time(0));

	int p[500];
	float x[500];
	float a, b;
	float minim = 100000;
	int mat[500][500];
	float fitnes, fitnestotal = 0;
	float vectorfitnes[100];
	float probabilitate[100];
	int functie = 1;
	int dim = 10;
	int nrcrom = 10;
	float vect[100];
	float Best = 10000, Worst = -10000;
	float test = 0;
	float Suma = 0;
	int n;

	if (functie == 1)
	{
		a = -5.12;
		b = 5.12;
	}

	else if (functie == 3)
	{
		a = -5.12;
		b = 5.12;
	}
	else if (functie == 2)
	{
		a = -500;
		b = 500;
	}


	//Generam toti cromozomii
	for (int j = 0; j<nrcrom; j++)
	{
		Generare(p, a, b, dim);


		for (int i = 0; i<dim*superior(a, b); i++)
			mat[j][i] = p[i];

		//transformam cromzomul in nr real unde x este vectorul cu dim elemente
		TransfBaza10(p, dim*superior(a, b), a, b, x, dim);



		if (functie == 1)
		{
			fitnes = 1 / FunctiaRastrigin(dim, x);
		}

		if (functie == 2)
		{
			fitnes = 1 / FunctiaSchwefel(dim, x);

		}

		if (functie == 3)
		{
			fitnes = 1 / FunctiaDeJong(dim, x);

		}
		fitnestotal = fitnestotal + fitnes;

		//salvam  fitnesul fiecarui cromozom in parte
		vectorfitnes[j] = fitnes;

		if (fitnes<minim)
			minim = fitnes;




	}




	srand(time(0));
	for (int j = 0; j < 3; j++)
	{
		minim = 1000;

		test = minimizare(mat, x, fitnes, fitnestotal, minim, probabilitate, vectorfitnes, dim, functie, a, b, nrcrom);
		cout << "Valorile minime : " << endl;
		cout << test << endl;

		if (test<Best)
			Best = test;

		if (test>Worst)
			Worst = test;

		Suma = Suma + test;

	}
	cout << "Pentru " << dim << " dimensiuni:";
	cout << endl;
	cout << "Cea mai buna solutie:" << fixed << Best << endl;
	cout << "Cea mai proasta solutie:" << fixed << Worst << endl;
	cout << "Media solutiilor:" << fixed << Suma / 15;





	return 0;
}
