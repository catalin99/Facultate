#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <Windows.h>
using namespace std;

#define MAXIT 5

ifstream file("form.txt");
int V[100];
int Vcopie[100];
char formula[500];
float sansaMutatie = 0.2;
float sansaIncrucisare = 0.3;
int numarLinii = 10;
int matrice[100][100];
int matriceCopie[100][100];

int nrVar()
{

	stringstream temp;
	temp << file.rdbuf();
	string buffer(temp.str());

	strcpy(formula, buffer.c_str());
	

	int i = 0, nr = 0, maxnr = 0;

	for (i = 0; i < strlen(formula); i++)
	{
		if (formula[i] == 'X')
		{
			nr = 0;
			i++;
			while (formula[i] >= '0' && formula[i] <= '9')
			{
				nr = nr * 10 + (formula[i] - '0');
				i++;
			}
		}

		if (nr > maxnr)
			maxnr = nr;
	}

	return maxnr;
}

int clauza_SAT(char*  clauza, int vector[100])
{
	int i = 0, indice = 0;
	bool negatie = 0;
	bool SAT = 0;

	while (i < strlen(clauza))
	{
		if (clauza[i] == 'X')
		{
			negatie = 0;
			if (clauza[i - 1] == '!')
				negatie = 1;

			indice = 0;
			i++;
			while (clauza[i] >= '0' && clauza[i] <= '9')
			{
				indice = indice * 10 + (clauza[i] - '0');
				i++;
			}



			if ((vector[indice - 1] == 1 && negatie == 0) || (vector[indice - 1] == 0 && negatie == 1))
			{
				return 1;		// ==> clauza este 1, pot trece la urmatoarea
			}
		}
		i++;
	}

	return 0;
}

int nr_clauze_SAT(int nrpara, int vector[100])
{
	char formula2[500];
	strcpy(formula2, formula);

	int nrclauze = 0;

	char * clauza;
	clauza = strtok(formula2, "^");
	bool negatie = 0;

	while (clauza != NULL)			//delim retine CLAUZELE
	{

		int i = 0;
		int indice = 0;
		while (i < strlen(clauza))
		{
			negatie = 0;
			if (clauza[i] == 'X')
			{
				if (clauza[i - 1] == '!')
					negatie = 1;

				indice = 0;
				i++;
				while (clauza[i] >= '0' && clauza[i] <= '9')
				{
					indice = indice * 10 + (clauza[i] - '0');
					i++;
				}

				if ((vector[indice - 1] == 1 && negatie == 0) || (vector[indice - 1] == 0 && negatie == 1))
				{
					nrclauze++;
					break;			// ==> clauza este 1, pot trece la urmatoarea
				}
			}
			i++;
		}
		clauza = strtok(NULL, "^");
	}

	return nrclauze;
}

int formula_SAT(int nrpara, int vector[100])
{
	char formula2[500];
	strcpy(formula2, formula);

	int OK = 0;
	int OK2 = 1;

	char * clauza;
	clauza = strtok(formula2, "^");
	bool negatie = 0;

	while (clauza != NULL)			//delim retine CLAUZELE
	{
		cout << clauza << " ----> " << clauza_SAT(clauza, vector) << '\n';

		int i = 0;
		int indice = 0;
		while (i < strlen(clauza))
		{
			OK = 0;
			negatie = 0;
			if (clauza[i] == 'X')
			{
				if (clauza[i - 1] == '!')
					negatie = 1;

				indice = 0;
				i++;
				while (clauza[i] >= '0' && clauza[i] <= '9')
				{
					indice = indice * 10 + (clauza[i] - '0');

					i++;
				}

				if ((vector[indice - 1] == 1 && negatie == 0) || (vector[indice - 1] == 0 && negatie == 1))
				{
					OK = 1;
					break;			// ==> clauza este 1, pot trece la urmatoarea
				}
			}
			i++;
		}
		OK2 = OK2*OK;
		clauza = strtok(NULL, "^");
	}

	return OK2;
}


void emptyMatriceCopie(int nrpara)
{
	for (int i = 0; i < numarLinii; i++)
		for (int j = 0; j < nrpara; j++)
			matriceCopie[i][j] = 0;
}

void showM(int nrpara)
{
	for (int i = 0; i < numarLinii; i++)
	{
		for (int j = 0; j < nrpara; j++)
			cout << matrice[i][j] << " ";
		cout << endl;
	}
	cout << endl;

}

void randomizeM(int nrpara)
{
	srand(time(NULL));
	for (int i = 0; i < numarLinii; i++)
		for (int j = 0; j < nrpara; j++)
			matrice[i][j] = rand() % 2;
}

int max_clauze_SAT(int nrpara)
{
	int max = 0;
	int x;
	for (int i = 0; i < numarLinii; i++)
	{
		x = nr_clauze_SAT(nrpara, matrice[i]);
		if (x > max)
			max = x;
	}
	return max;
}

void CopyMatLine(int src[100][100], int dest[100][100], int scrLine, int destLine, int nrpara)
{
	for (int i = 0; i < nrpara; i++)
		dest[destLine][i] = src[scrLine][i];

}

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void SUS(int nrpara)
{
	int eval[100];		//fitness-uri
	double T = 0;			//fitness total
	double p[100];			//prob. sel. individuale
	double q[100];			//prob. sel. cumulate
	int index;			//index-ul unui cromosom ales pt next generation

	for (int i = 0; i < numarLinii; i++)
	{
		eval[i] = nr_clauze_SAT(nrpara, matrice[i]);
		T += eval[i];
	}

	for (int i = 0; i < numarLinii; i++)
		p[i] = eval[i] / T;

	q[0] = 0;
	for (int i = 0; i < numarLinii; i++)
		q[i + 1] = q[i] + p[i];

	/*
	for (int i = 0; i < nrlinii; i++)
	cout << "Q" << i << "= " << q[i] << " ";
	cout << endl;
	*/




	srand(time(NULL));

	int k = -1;
	//double r =(double) rand() % (1.0 / nrlinii - 0 + 1) + 0;	//  x = min + (rand() % static_cast<int>(max - min + 1))
	//double r = 0.07;
	double r = fRand(0, 1.0 / numarLinii);
	for (int i = 0; i < numarLinii; i++)

	{
		//caut cel mai mare nrSAT, mai mic decat r
		for (int j = numarLinii - 1; j >= 0; j--)
		{
			if (q[j] < r)
			{
				index = j;
				k++;
				CopyMatLine(matrice, matriceCopie, j, k, nrpara);
				break;
			}
		}

		//cout << "R " << r << endl;

		r = r + 1.0 / numarLinii;

	}

}

void Mutatie(int nrpara)
{
	for (int i = 0; i < numarLinii; i++)
	{
		double yesOrNo = double(rand()) / (double)RAND_MAX;
		if (yesOrNo < sansaMutatie)
		{
			int randomPoz = rand() % nrpara;
			if (matriceCopie[i][randomPoz] == 1)  matriceCopie[i][randomPoz] = 0;
			else matriceCopie[i][randomPoz] = 1;
		}
	}
}

void Incrucisare(int nrpara)
{
	int vec[100];
	int k = -1;
	for (int i = 0; i < numarLinii; i++)
	{
		double yesOrNo = double(rand()) / (double)RAND_MAX;
		if (yesOrNo < sansaIncrucisare)
		{
			k++; vec[k] = i;
		}
	}
	if (k % 2 == 0) k--;

	for (int i = 0; i < k; i = i + 2)
	{
		int punctTaiere = 1 + (rand() % (int)(nrpara - 2 + 1));	//intre 1 si nrpara-1
		int aux = 0;
		for (int j = 0; j < punctTaiere; j++)
		{
			aux = matriceCopie[vec[i]][j];
			matriceCopie[vec[i]][j] = matriceCopie[vec[i + 1]][j];
			matriceCopie[vec[i + 1]][j] = aux;

		}

	}

}

void InlocuireMatrice(int nrpara)
{
	for (int i = 0; i <numarLinii; i++)
		for (int j = 0; j < nrpara; j++)
			matrice[i][j] = matriceCopie[i][j];
}

void Program()
{
	int nrpara = nrVar();
	int iteratii = 0;

	randomizeM(nrpara);
	showM(nrpara);

	int n = max_clauze_SAT(nrpara);
	int n_best = n;

	while (iteratii < MAXIT)
	{

		emptyMatriceCopie(nrpara);

		SUS(nrpara);		//selectia 
		Mutatie(nrpara);
		Incrucisare(nrpara);

		InlocuireMatrice(nrpara);

		cout << endl;
		showM(nrpara);

		cout << "Current n = " << n << "\n";
		n = max_clauze_SAT(nrpara);
		if (n > n_best)
			n_best = n;


		iteratii++;
	}

	cout << "\n \n Besttttttttttttt n = " << n_best;


}


int main()
{

	Program();


}