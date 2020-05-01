#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define _USE_MATH_DEFINES 1;
#include <math.h>  
#include <cmath>
#define ENDLINE cout<<endl;
#define MAX 10000
using namespace std;

int bestmat[30][30];
int mat[30][30];
float MIN;
int v[5];




void GenerareMatrice(int parametri,int nr_biti,int mat[30][30])
{
	for (int i = 0; i < parametri; i++)
	{
		for (int j = 0; j < nr_biti; j++)
			mat[i][j] = rand() % 2;
	}
	ENDLINE;
	

}

float CalculeazaFunctiaDeJong(float a,float b,float n,int parametri,int nr_biti, int mat[30][30])
{
	float suma = 0;
	for (int q = 0; q < parametri; q++)
	{
		float x = 0;
		float putere = nr_biti - 1;
		//TRASNFORMAM NUMARUL IN DECIMAL
		for (int p = 0; p < nr_biti; p++)
		{

			x = x + mat[q][p] * pow(2, putere);
			putere--;
		}
		//TRANSFORMAM NUMARUL REAL
		float Xreal =(float)( a + x * (b - a) / (pow(2, n) - 1));
		
		//cout << "Numarul real este: "; cout << Xreal; ENDLINE;


		//IL ADAUGAM LA SUMA
		suma = suma + Xreal*Xreal;

	}
	return suma;
}


void DeJongBest(int parametri,int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);


	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);

	
	for (int count = 0; count < 30;count++)
	{
		if(count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaDeJong(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
	
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{
				
				for (int j = 0; j < nr_biti; j++)
				{
					
					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaDeJong(a, b, n, parametri, nr_biti, mat);

					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{
						
						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;
					
					
					
				}
			}

			
			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}
				
				
			}
			else local = true; //NU A FOST GASIT UN VECIN MAI BUN

			
			

		} while (!local);

		cout <<MIN; ENDLINE;
	
		
	}


	
}

void DeJongFirst(int parametri, int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	


	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);


	for (int count = 0; count < 10; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaDeJong(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaDeJong(a, b, n, parametri, nr_biti, mat);

					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
						break; break;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;
					
				
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}
				


			}
			else local = true;


		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}

}

void DeJongAnnealing(int parametri, int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	float d = 2;
	float N = (b - a)* pow(10, d);
	float n = log2(N);
	float T = 1;
	float t = 0.00001;
	


	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);

	for (int count = 0; count < 10; count++)
	{

		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaDeJong(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII

		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaDeJong(a, b, n, parametri, nr_biti, mat);

					
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
					}
					else
					{
						if ((rand() % 2) < exp(-abs(suma - min) / T))
						{
							for (int k = 0; k < parametri; k++)
							{
								for (int l = 0; l < nr_biti; l++)
								{
									bestmat[k][l] = mat[k][l];
								}
							}
							min = suma;
							cout << min; ENDLINE;
						}
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

				

					
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			

			
			T= T * 0.9;


		} while (t < T);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}


}



int CalculeazaFunctiaSchwefel(float a, float b, float n, int parametri, int nr_biti, int mat[30][30])
{
	float suma = 0;
	for (int q = 0; q < parametri; q++)
	{
		float x = 0;
		int putere = nr_biti - 1;
		//TRASNFORMAM NUMARUL IN DECIMAL
		for (int p = 0; p < nr_biti; p++)
		{

			x = x + mat[q][p] * pow(2, putere);
			putere--;
		}
		//TRANSFORMAM NUMARUL REAL
		float Xreal = (float)(a + x * (b - a) / (pow(2, n) - 1));

		//cout << "Numarul real este: "; cout << Xreal; ENDLINE;


		//IL ADAUGAM LA SUMA
		suma = suma + (-Xreal * sin(sqrt(abs(Xreal))* M_PI / 180));

	}
	return suma;
}



void SchwefelAnnealing(int parametri, int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	float T = 1;
	float t = 0.00001;



	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);

	for (int count = 0; count < 10; count++)
	{

		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaSchwefel(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII

		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaSchwefel(a, b, n, parametri, nr_biti, mat);


					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
					}
					else
					{
						if ((rand() % 2) < exp(-abs(suma - min) / T))
						{
							for (int k = 0; k < parametri; k++)
							{
								for (int l = 0; l < nr_biti; l++)
								{
									bestmat[k][l] = mat[k][l];
								}
							}
							min = suma;
							cout << min; ENDLINE;
						}
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

					


				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}

			T = T * 0.9;


		} while (t < T);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}


}



void SchwefelBest(int parametri, int nr_biti)
{
	float a = -500;
	float b = 500;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);



	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);


	for (int count = 0; count < 30; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaSchwefel(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaSchwefel(a, b, n, parametri, nr_biti, mat);

			
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;
					

					
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			else local = true;

	

		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}

}

void SchwefelFirst(int parametri, int nr_biti)
{
	float a = -500;
	float b = 500;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);



	srand(time(NULL));

	GenerareMatrice(parametri,nr_biti, mat);


	for (int count = 0; count < 10; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaSchwefel(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaSchwefel(a, b, n, parametri, nr_biti, mat);

				
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
						break; break;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;
					
					

					
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			else local = true;


		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}

}



float CalculeazaFunctiaRastrigin(float a, float b, float n, int parametri, int nr_biti, int mat[30][30])
{
	float suma = 0;
	for (int q = 0; q < parametri; q++)
	{
		float x = 0;
		int putere = nr_biti - 1;
		//TRASNFORMAM NUMARUL IN DECIMAL
		for (int p = 0; p < nr_biti; p++)
		{

			x = x + mat[q][p] * pow(2, putere);
			putere--;
		}
		//TRANSFORMAM NUMARUL REAL
		float Xreal = (float)(a + x * (b - a) / (pow(2, n) - 1));

		//cout << "Numarul real este: "; cout << Xreal; ENDLINE;


		//IL ADAUGAM LA SUMA
		suma = suma + (Xreal * Xreal - 10 * cos((2 * M_PI * Xreal)* M_PI / 180));

	}
	return suma;

}

void RastriginAnnealing(int parametri, int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	float T = 1;
	float t = 0.00001;



	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);

	for (int count = 0; count < 10; count++)
	{

		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaRastrigin(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII

		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaRastrigin(a, b, n, parametri, nr_biti, mat);

				
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
					}
					else
					{
						if ((rand() % 2) < exp(-abs(suma - min) / T))
						{
							for (int k = 0; k < parametri; k++)
							{
								for (int l = 0; l < nr_biti; l++)
								{
									bestmat[k][l] = mat[k][l];
								}
							}
							min = suma;
							cout << min; ENDLINE;
						}
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

					


				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}

			T = T * 0.9;


		} while (t < T);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}


}



void RastriginBest(int parametri, int nr_biti)
{

	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	


	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);


	for (int count = 0; count < 10; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaRastrigin(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaRastrigin(a, b, n, parametri, nr_biti, mat);

					
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}

						cout << min; ENDLINE;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

					
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			else local = true;




		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}
}

void RastriginFirst(int parametri, int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);



	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);


	for (int count = 0; count < 10; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaRastrigin(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaRastrigin(a, b, n, parametri, nr_biti, mat);

					
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
						
						break; break;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

					

					
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			else local = true;


		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}

}


float CalculeazaFunctiaSixHump(float a, float b, float n, int parametri, int nr_biti, int mat[30][30])
{
	float Xreal1;
	float Xreal2;
	float suma = 0;
	for (int q = 0; q < parametri; q++)
	{
		float x = 0;
		int putere = nr_biti - 1;
		//TRASNFORMAM NUMARUL IN DECIMAL
		for (int p = 0; p < nr_biti; p++)
		{

			x = x + mat[q][p] * pow(2, putere);
			putere--;
		}
		//TRANSFORMAM NUMARUL REAL
		if (q == 0) Xreal1 = (float)(a + x * (b - a) / (pow(2, n) - 1));
		else if (q == 1) Xreal2 = (float)(a + x * (b - a) / (pow(2, n) - 1));
		//cout << "Numarul real este: "; cout << Xreal; ENDLINE;
	}

		//IL ADAUGAM LA SUMA
		suma = suma + (4 - 2.1*(Xreal1*Xreal2) + pow(Xreal1, 4 / 3)* (Xreal1 * Xreal1) + Xreal1*Xreal2 + (-4 + 4 * (Xreal2*Xreal2)) * (Xreal2 * Xreal2));

	
	return suma;

}

void SixHumpAnnealing(int parametri, int nr_biti)
{
	float a = -5.12;
	float b = 5.12;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	float T = 1;
	float t = 0.00001;



	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);

	for (int count = 0; count < 2; count++)
	{

		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaSixHump(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII

		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaSixHump(a, b, n, parametri, nr_biti, mat);


					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
					}
					else
					{
						if ((rand() % 2) < exp(-abs(suma - min) / T))
						{
							for (int k = 0; k < parametri; k++)
							{
								for (int l = 0; l < nr_biti; l++)
								{
									bestmat[k][l] = mat[k][l];
								}
							}
							min = suma;
							cout << min; ENDLINE;
						}
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

				


				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}

			T = T * 0.9;


		} while (t < T);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}


}



void SixHumpBest(int parametri, int nr_biti)
{
	float a = -500;
	float b = 500;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	

	parametri = 2;
	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);


	for (int count = 0; count < 10; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaSixHump(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaSixHump(a, b, n, parametri, nr_biti, mat);

				
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}
						cout << min; ENDLINE;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;

					

					
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			else local = true;


		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}

}

void SixHumpFirst(int parametri, int nr_biti)
{
	float a = -500;
	float b = 500;
	int d = 2;
	float N = (b - a)* pow(10, d);
	int n = log2(N);
	


	srand(time(NULL));

	GenerareMatrice(parametri, nr_biti, mat);


	for (int count = 0; count < 10; count++)
	{
		if (count > 0) GenerareMatrice(parametri, nr_biti, mat);


		//CALCULAM PENTRU MATRICEA INITIALA
		float suma = CalculeazaFunctiaSixHump(a, b, n, parametri, nr_biti, mat);

		float min = suma;
		MIN = min;

		//CALCULAM VECINII
		bool local = false;
		
		do {
			//CAUT IN VECINATATE SOLUTII MAI BUNE
			for (int i = 0; i < parametri; i++)
			{

				for (int j = 0; j < nr_biti; j++)
				{

					if (mat[i][j] == 1) mat[i][j] = 0;
					else mat[i][j] = 1;

					suma = CalculeazaFunctiaSixHump(a, b, n, parametri, nr_biti, mat);

					
					//DACA E O SOLUTIE MAI BUNA, ACTUALIZAM MINIMUL SI MATRICEA
					if (suma < min)
					{

						min = suma;
						for (int k = 0; k < parametri; k++)
						{
							for (int l = 0; l < nr_biti; l++)
							{
								bestmat[k][l] = mat[k][l];
							}
						}

						cout << min; ENDLINE;
						break; break;
					}
					//SCHIMBAM INAPOI BITUL SI TRECEM LA URMATORUL VECIN
					if (mat[i][j] == 0) mat[i][j] = 1;
					else mat[i][j] = 0;
					
					

				
				}
			}


			if (min < MIN)
			{

				MIN = min;

				for (int k = 0; k < parametri; k++)
				{
					for (int l = 0; l < nr_biti; l++)
					{
						mat[k][l] = bestmat[k][l];
					}
				}


			}
			else local = true;



		} while (!local);

		cout << "Minimul global este: " << MIN; ENDLINE; ENDLINE;
	}

}




 
int main()
{
	srand(time(NULL));
	int nr_biti;
	int parametri;

	cout << "Introduceti numarul de parametri: ";
	cin >> parametri;
	cout << "Introduceti numarul de biti: ";
	cin >> nr_biti;
	
	DeJongAnnealing(parametri, nr_biti);
	
	return 0;
}                                                            


//TEMA 1' 
// for(i=0;i>32;i++)
//{
//sir = int_to_bit(i); i este int
//HC(SIR);
//}


//TEMA 2 - taietura random
