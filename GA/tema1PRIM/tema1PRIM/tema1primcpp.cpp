#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define _USE_MATH_DEFINES 1;
#include <math.h>  
#include <cmath>
using namespace std;
#define ENDLINE cout<<endl;


int punct;
int bestpunct;
int best[5];
int bestmax;
int v[5];
int bazin[31][20];
int global;




void DecToBin(int n)
{

	for (int i = 0; i < 5; i++)
			v[i] = 0;
	int cifra = 0;
	int nr = 4;
	while (n > 0)
	{
		cifra = n % 2;
		n /= 2;
		v[nr] = cifra;
		nr--;
	}

}

int  BinToDec(int x,int &putere)
{
	
	for (int j = 0; j < 5; j++)
	{

		x = x + v[j] * pow(2, putere);
		putere--;
	}

	return x;

}

void BestHillClimbing()
{
	int bestmax = 0;
	int local = 0;
	int functie = 0;
	int max = 0;
	int x = 0;
	int putere = 4;
	int primu = 1;

	do
	{
		
		
		for (int i = 0; i < 5; i++)
		{

			if (v[i] == 0) v[i] = 1;
			else v[i] = 0;

			putere = 4;
			x = 0;

			x = BinToDec(x, putere);

			functie = pow(x, 3) - 60 * pow(x, 2) + 900 * x + 100;

			//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MAXIMUL
			if (functie > max)
			{

				max = functie;

				for (int k = 0; k < 5; k++)
					best[k] = v[k];

				punct = x;
				
			}

			//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
			if (v[i] == 0) v[i] = 1;
			else v[i] = 0;
		}
		if (bestmax < max)
		{
			bestmax = max;
			for (int k = 0; k < 5; k++)
				v[k] = best[k];
			bestpunct = punct;
			local = 0;
		}
		else local = 1;
		 
		

	} while (!local);

	cout << "Maximul este: " << bestmax << " si punctul de maxim este " << bestpunct; ENDLINE; ENDLINE;

	bazin[global][bestpunct] = 1;
	

}

void FirstHillClimbing()
{
	int bestmax = 0;
	int local = 0;
	int functie = 0;
	int max = 0;
	int x = 0;
	int putere = 4;
	int primu = 1;




	do
	{


		for (int i = 0; i < 5; i++)
		{

			if (v[i] == 0) v[i] = 1;
			else v[i] = 0;

			putere = 4;
			x = 0;

			x = BinToDec(x, putere);

			functie = pow(x, 3) - 60 * pow(x, 2) + 900 * x + 100;

			//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MAXIMUL
			if (functie > max)
			{

				max = functie;

				for (int k = 0; k < 5; k++)
					best[k] = v[k];
				punct = x;
				break;
				


			}

			//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
			if (v[i] == 0) v[i] = 1;
			else v[i] = 0;
		}
		if (bestmax < max)
		{
			bestmax = max;
			for (int k = 0; k < 5; k++)
				v[k] = best[k];
			bestpunct = punct;
			local = 0;
		}
		else local = 1;



	} while (!local);

	cout << "Maximul este: " << bestmax << " si punctul de maxim este " << bestpunct; ENDLINE; ENDLINE;

	bazin[global][bestpunct] = 1;


}
		



int main()
{
	int p, k;
	for (int i = 0; i < 32; i++)
	{
		DecToBin(i);
		global = i;
		cout << "Punctul de la care plecam este : " << i; ENDLINE;
		BestHillClimbing();


	}
	for (k = 0; k < 20; k++)
	{
		cout << " Bazinul  de atractie pentru " << k << " este :";
		for (p = 0; p < 32; p++)
			if (bazin[p][k] == 1)
			{
				cout << p << " ";

			}
		ENDLINE;
	}
	

}