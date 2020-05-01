// GA-tema3.cpp : Defines the entry point for the console application.NumarGeneratii
//


#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <random>
#include <utility>
#include <map>
#include <cmath>
#include <stdlib.h>

#define Mutate_Prob 0.035
#define Cross_Prob 0.27

const size_t NumarCromozomi = 100;
const size_t NumarGeneratii = 1000;
struct node
{
	double x;
	double y;
};
std::deque<node> CoordNodes;

int RandomInt(int first, int last)
{
	int nrRandI = 0;
	std::random_device seed;
	std::mt19937 rand(seed());
	std::uniform_int_distribution<int> dist(first, last - 1);
	nrRandI = dist(rand);
	return nrRandI;
}

double RandomDouble(double first, double last)
{
	double nrRandI = 0.;
	std::random_device seed;
	std::mt19937 rand(seed());
	std::uniform_real_distribution<double> dist(first, last - 1.);
	nrRandI = dist(rand);
	return nrRandI;
}

std::deque<std::deque<int>> population;
double COSTS[100][100];

void generate_chromosome(std::deque<int>& chromosome, size_t Cities)
{
	for (size_t it = 0; it < Cities; it++)
	{
		chromosome.emplace_back(RandomInt(0,Cities - it));
	}
}

void CalculDistance(const double& CoordX, const double& CoordY, const size_t& Cities, const size_t& NOD)
{
	for (size_t it = 0; it < Cities; ++it)
	{
		double Distance;
	
			double One; double Two;
			One = CoordNodes[it].x - CoordX;
			One *= One;
			Two = CoordNodes[it].y - CoordY;
			Two *= Two;
			Distance = One + Two;
			Distance = sqrt(Distance);
			COSTS[NOD][it] = Distance;
	}
}



void Generate_Pop(std::ifstream &f1, size_t &Cities)                //creare populatie
{

	f1 >> Cities;
	int nod;
	double x, y;
	std::deque<int> chromosome;
	for (size_t it = 0; it < Cities; it++)
	{
		f1 >> nod;
		f1 >> x >> y;
		nod--;
		node N;
		N.x = x;
		N.y = y;
		CoordNodes.emplace_back(N);
		/*for (size_t parc = 0; parc < Cities - 1; parc++)
		{
			int line, column;
			double cost;
			f1 >> cost >> line;


			COSTS[it][line] = cost;
			COSTS[it][it] = -1;
		}*/
	}
	for (size_t it = 0; it < Cities; it++)
	{
		CalculDistance(CoordNodes[it].x, CoordNodes[it].y, Cities, it);
	}
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		generate_chromosome(chromosome, Cities);
		population.emplace_back(chromosome);
		chromosome.clear();
	}
}

void Generate_Pop_SAHC(std::ifstream &f1, size_t &Cities)                //creare populatie
{

	f1 >> Cities;
	int nod;
	double x, y;
	std::deque<int> chromosome;
	for (size_t it = 0; it < Cities; it++)
	{
		f1 >> nod;
		f1 >> x >> y;
		nod--;
		node N;
		N.x = x;
		N.y = y;
		CoordNodes.emplace_back(N);
		/*for (size_t parc = 0; parc < Cities - 1; parc++)
		{
			int line, column;
			double cost;
			f1 >> cost >> line;


			COSTS[it][line] = cost;
			COSTS[it][it] = -1;
		}*/
	}
	for (size_t it = 0; it < Cities; it++)
	{
		CalculDistance(CoordNodes[it].x, CoordNodes[it].y, Cities, it);
	}
}

void Do_Eval(std::deque<double>&eval)
{

	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		double sum = 0;
		for (size_t parc = 0; parc < population[it].size() - 1; parc++)
			sum = sum + COSTS[population[it][parc]][population[it].at(parc + 1)];
		sum = sum + COSTS[population[it].at(population[it].size() - 1)][population[it].at(0)];

		eval.emplace_back(sum);
	}

}

double  MakeFitnessDeque(std::deque<double> &fit, std::deque<double>eval)
{
	double FitnessTotal = 0;
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		fit.emplace_back(1 / eval[it]);
		FitnessTotal += fit[it];

	}
	return FitnessTotal;
}

void DecodeChromosome(std::deque<int> &chromosome)
{
	std::deque<int> cities;
	for (size_t it = 0; it < chromosome.size(); it++)
		cities.emplace_back(it);

	for (size_t it = 0; it < chromosome.size(); it++)
	{
		int position = chromosome[it];
		//std::cout<<position<<std::endl;
		chromosome[it] = cities.at(position);
		cities.erase(cities.begin() + position);
	}
}

void decode_pop()
{
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		DecodeChromosome(population[it]);
	}
}


void code_chromosome(std::deque<int> &chromosome)
{
	std::deque<int> cities;
	for (size_t it = 0; it < chromosome.size(); it++)
		cities.emplace_back(it);

	for (size_t it = 0; it < chromosome.size(); it++)
	{
		int POZ=0;
		for (size_t it = 0; it < cities.size(); it++)
			if (chromosome[it] == cities[it])
				POZ = it;
		chromosome[it] = POZ;
		cities.erase(cities.begin() + POZ);
	}
}

void code_pop()
{
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		code_chromosome(population[it]);
	}
}


void Afiseaza_Rezultate()
{
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		for (size_t parc = 0; parc < population[it].size(); parc++)
			std::cout << population[it][parc] << ' ';
		std::cout << std::endl;
	}
}


void Calculate_Probabilities(std::deque<double> &probabilities, std::deque<double>fit, double FitTotal)
{
	for (size_t it = 0; it < NumarCromozomi; it++)
		probabilities.emplace_back((double)fit[it] / FitTotal);
}

void Calculate_Intervals(std::deque<double> &intervals, std::deque<double>probabilities)
{
	intervals.emplace_back(0);
	for (size_t it = 1; it < NumarCromozomi; it++)
	{
		intervals.emplace_back(intervals[it-1] + probabilities[it-1]);
	}
	intervals[NumarCromozomi - 1] = 1;
}

void Select_Chromosomes(std::deque<double>intervals, std::deque<double>&fit)
{
	std::deque<std::deque<int>> temp_pop;
	std::deque<double> fit_temp;
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		double random_number = RandomDouble(0,2);
		for (size_t parc = 1; parc < NumarCromozomi; parc++)
		{
			if (random_number <= intervals[parc])
			{
				temp_pop.emplace_back(population[parc - 1]);
				fit_temp.emplace_back(fit[parc - 1]);
				break;
			}
		}
	}
	population = temp_pop;
	fit = fit_temp;
}



void CrossOver_Chromosome(std::deque<int>&v1, std::deque<int>&v2)
{
	int nr = RandomInt(0, v1.size());
	std::deque<int>copy;
	copy = v1;
	for (size_t it = nr; it < v1.size(); it++)
		v1[it] = v2[it];
	for (size_t it = nr; it < v1.size(); it++)
		v2[it] = copy[it];

}
void CrossOver_Pop()
{
	int counter = 0;
	int x;
	for (size_t it = 0; it < NumarCromozomi; it++)
	{
		double random_number = RandomDouble(0, 2);
		if (random_number < Cross_Prob)
		{
			counter++;
			if (counter == 1) 
			{ 
				x = it; 
			}
			else 
			{
				CrossOver_Chromosome(population[x], population[it]); counter = 0;
			}
		}
	}
}
void Mutation()
{
	for (size_t it = 0; it < NumarCromozomi; it++)
		for (size_t parc = 0; parc < population[it].size(); parc++)
		{
			//std::cout << 1 << std::endl;
			double rand_nr = RandomDouble(0, 2);
			if (rand_nr < Mutate_Prob)
			{
				if (population[it][parc] < population[it].size() - parc - 1)
					population[it][parc]++;
				else if (population[it][parc] > 0)
					population[it][parc]--;
			}
		}
}
double GeneticAlgorithm()
{
	int Start_Generation = 0;
	std::deque<int>best;
	std::deque<double> eval;
	std::ifstream f1("TSPdata.txt");
	size_t Cities;
	double min = DBL_MAX;
	Generate_Pop(f1, Cities);
	f1.close();
	
	decode_pop();
	Do_Eval(eval);
	
	
	for (size_t it = 0; it < NumarCromozomi; it++)
	{ 
		if (min < eval[it]) min = eval[it];

	}
	
	while (Start_Generation < NumarGeneratii)
	{
		//std::cout << "\n\n" << Start_Generation << "\n\n";
		double fitTotal = 0;
		std::deque<double>fitness;
		fitTotal = MakeFitnessDeque(fitness, eval);
		std::deque<double>probabilities;
		Calculate_Probabilities(probabilities, fitness, fitTotal);
		std::deque<double>intervals;
		Calculate_Intervals(intervals, probabilities);
		Select_Chromosomes(intervals, fitness);
		code_pop();
		Mutation();
		CrossOver_Pop();
		decode_pop();
		eval.clear();
		Do_Eval(eval);
		for (size_t it = 0; it < NumarCromozomi; it++)
		{
			if (eval[it] < min) 
			{ 
				min = eval[it]; 
				std::cout << min << ' ';
				best = population[it]; 
			}
		}
		Start_Generation++;
	}


	population.clear();
	return min;
}

double calculate_distance(std::deque<int>dq, const size_t& nr_cities)
{
	double sum = 0.;
	for (size_t it = 0; it < nr_cities - 1; it++)
		sum += COSTS[dq[it]][dq[it + 1]];
	sum += COSTS[dq[nr_cities - 1]][dq[0]];
	return sum;
}

void DecodeIndivid(std::deque<int>&dq, int nr_cities)
{

	std::deque<int> cities;
	for (size_t it = 0; it < nr_cities; it++)
		cities.emplace_back(it);

	for (size_t it = 0; it < nr_cities; it++)
	{
		size_t position = dq[it];
		//cout<<position<<endl;
		dq[it] = cities[position];
		cities.erase(cities.begin() + position);
	}
}

void HillClimbingBestImprovement()
{
	size_t nr_cities;
	std::deque<int>individ;
	std::ifstream f("TSPdata.txt");
	Generate_Pop_SAHC(f, nr_cities);
	//print_matrix(nr_cities);
	double BESTMIN;
	std::deque<int>bestdeque;
	BESTMIN = 111111;
	double min = 100000, max = 0, avg = 0;
	for (size_t iteratii = 0; iteratii < 100; iteratii++)
	{

		individ.clear();
		generate_chromosome(individ, nr_cities);
		std::deque<int> copy;
		std::deque<int>best;
		copy = individ;//copy=codat
		DecodeIndivid(individ, nr_cities);
		double dist = calculate_distance(individ, nr_cities);

		double min_iteratie = dist;
		double mmin = min_iteratie;

		code_chromosome(individ);
		bool local = false;
		int nr = 0;
		do
		{
			nr++;
			for (size_t it = 0; it < nr_cities; it++)
			{


				int ok = 0;
				if (individ[it] < individ.size() - it - 1) 
				{ 
					ok = 1; 
					individ[it]++; 
				}
				else if (individ[it] > 0)
				{ 
					ok = 2; 
					individ[it]--; 
				}

				DecodeIndivid(individ, nr_cities);
				double dist1 = calculate_distance(individ, nr_cities);

				code_chromosome(individ);
				if (dist1 < min_iteratie)
				{
					min_iteratie = dist1;

					best = individ;
				}
				if (ok == 1)
					individ[it]--;
				else if (ok == 2)
					individ[it]++;
			}
			if (min_iteratie < mmin)
			{
				mmin = min_iteratie;
				individ = best;

			}
			else
			{
				local = true;
			}
			//copy=individ;

		} while (!local);
		if (mmin < BESTMIN) BESTMIN = mmin;



		if (mmin < min)min = mmin;
		if (mmin > max)max = mmin;
		avg += mmin;

	}

	std::cout << std::endl << "minim: " << min << "    maxim" << max << "media:  " << (double)avg / 100;
}

int main()
{
	double min = DBL_MAX, max = DBL_MIN, AVG = 0;
	for (size_t it = 1; it < 100; it++) 
	{
		double x = GeneticAlgorithm();
		if (x > max)
			max = x;
		else if (x < min)
			min = x;
		AVG += x;
	}

	std::cout<<std::endl<<"Burma: \n"<<"minim: "<<min<<"\nmaxim: "<<max<<"\nmedia: "<<(double)AVG/100; 
	system("pause");
	return 0;

}
