#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <random>
#include <deque>
#include <thread>

using namespace std;
typedef unsigned int ui;
double pi=3.1415926535;
ui Population = 50;

struct Info {
	double(*function)(vector<double>&);
	double first;
	double last;
	unsigned int dim;
	unsigned int BitesPerDim;//nr de biti pe dimensiune
};
/*start_random*/
double RandomDouble(double first, double last)
{
	double nrRandD = 0;
	random_device seed;
	mt19937 rand(seed());
	uniform_real_distribution<double> randGen(first, last);
	nrRandD = randGen(rand);
	return nrRandD;
}

int RandomInt(int first, int last)
{
	int nrRandI = 0;
	random_device seed;
	mt19937 rand(seed());
	uniform_int_distribution<int> randGen(first, last);
	nrRandI = randGen(rand);
	return nrRandI;
}
/*end_random*/

/*start_functions*/
double DeJong(vector<double> &dq)
{
	double sum = 0;
	for (ui i = 0; i < dq.size(); i++)
		sum = sum + pow(dq[i], 2);
	return sum;
}

double Schwefel(vector<double> &dq)
{
	double sum = 0;
	for (ui i = 0; i < dq.size(); i++)
		sum = sum + (sin(sqrt(abs(dq[i]))* (-1) *dq[i]));
	return sum;
}

double Rastrigin(vector<double> &dq)
{
	double sum = 0;
	for (ui i = 0; i < dq.size(); i++)
		sum = sum + (dq[i] * dq[i]) - 10 * cos(2 * pi *dq[i]);
	sum = sum + 10 * dq.size();
	return sum;
}

double SumOfDifferentPower(vector<double> &dq)
{
	double sum = 0;
	for (ui i = 0; i < dq.size()-1; i++)
		sum = sum + abs(pow(dq[i], dq[i + 1]));
	return sum;
}

double Rosenbrock(vector<double> &dq)
{
	double sum = 0;
	double x;
	for (ui i = 0; i < dq.size() - 1; i++)
	{
		x = 100 * pow((dq[i + 1] - pow(dq[i], 2)), 2) + pow((1 - dq[i]), 2);
		sum += x;
	}
	return sum;
}

double Griewangk(vector<double> &dq)
{
	double sum = 0;
	double prod = 1;
	double x;
	for (ui i = 1; i < dq.size(); i++)
	{
		sum += (pow(dq[i], 2) / 4000);
		prod *= (cos(dq[i] / (double)sqrt(i)));
	}
	x = sum - prod + 1;
	return x;
}
/*end_functions*/

/*start_help*/
int BinaryToDec(string str)
{
	int NrDec = 0;
	for (ui i=0; i<str.size(); i++)
		if (str[i] == '1')
			NrDec += (int)pow(2, i);
	return NrDec;
}

int NrBiti(Info &inf)
{
	double dif = (inf.last - inf.first);
	double power = dif * 1000; //10^3
	int nrfin = (int)ceil(log2(power));
	return nrfin;
}

double Decode(string str, Info &inf)
{
	double nrRet;
	double power = pow(2, str.size() - 1);
	double difference = inf.last - inf.first;
	int NrDec = BinaryToDec(str);
	nrRet = inf.first + (double)NrDec*difference / power;
	return nrRet;
}
/*end_help*/

/*start_generator*/
string GenerateCromozom(Info &inf)
{
	string Cromozom;
	for (ui i = 0; i < inf.dim*inf.BitesPerDim; i++)
		if (RandomInt(0, 1) == 1)
			Cromozom.push_back('1');
		else
			Cromozom.push_back('0');
	return Cromozom;
}

vector<string> GeneratePopulation(Info &inf)
{
	vector<string> MyPopulation;
	for (ui i = 0; i < Population; i++)
		MyPopulation.push_back(GenerateCromozom(inf));
	return MyPopulation;
}
/*end_generator*/

/*start_eval*/
double EvaluateCromozom(Info &inf, string str)
{
	vector<double> CromozomDecoded;
	for (ui i = 0; i < inf.dim; i++)
		CromozomDecoded.push_back(Decode(str.substr(inf.BitesPerDim*i, inf.BitesPerDim), inf));
	return inf.function(CromozomDecoded);
}

bool EvaluatePopulation(Info &inf, vector<string> &MyPop, vector<double> &Evaluator)
{
	Evaluator.clear();
	for (ui i = 0; i < Population; i++)
	{
		Evaluator.push_back(EvaluateCromozom(inf, MyPop[i]));
	}
	return true;
}

double MinEvaluate(vector<double> &evaluator)
{
	double Minim = evaluator[0];
	for (ui i = 1; i <Population; i++)
	{
		if (evaluator[i] < Minim)
			Minim= evaluator[i];
	}
	return Minim;
}
/*end_eval*/

/*start_fitness*/
bool Fitness(Info &inf, vector<double> &Evaluator, vector<double> &Fitness)
{
	Fitness.clear();
	for (ui i = 0; i < Population; i++)
		if (inf.function == DeJong || inf.function == Rastrigin || inf.function == SumOfDifferentPower || inf.function==Rosenbrock || inf.function==Griewangk)
			Fitness.push_back(1 / Evaluator[i]);
		else if (inf.function == Schwefel)
			Fitness.push_back(1/(5*418.99+Evaluator[i]));
		else
		{
			cout << "Eroare. Functie inexistenta\n";
			return false;
		}
	return true;
}

double SumALLFitness(vector<double> Fitness)
{
	double SumAllFitness = 0;
	for (ui i = 0; i < Fitness.size(); i++)
		SumAllFitness += Fitness[i];
	return SumAllFitness;
}

bool CalculProbs(vector<double> &Probs, vector<double> Fitness) //vector 0->1 cu probs //const+ref
{
	double LimitaSup = 0; //pornim intervalul de la 0
	double SumFitness = SumALLFitness(Fitness);
	for (ui i = 0; i < Population - 1; i++) //adaugam toate probs
	{
		LimitaSup += (Fitness[i] / SumFitness);
		Probs.push_back(LimitaSup);
	}
	Probs.push_back(double(1)); //adaugam capatul din dreapta al vectorului dequeului, 1.
	return true;
}
/*end_fitness*/
/*start_genetic_algorithm*/
bool Select(Info &inf, vector<string> &MyPop, vector<double> &Evaluator)
{
	vector<string> MyPop_Temp;
	vector<double> Fitness_var;
	Fitness(inf, Evaluator, Fitness_var);
	vector<double> Probs;
	CalculProbs(Probs, Fitness_var);
	for (ui i = 0; i < Population; i++)
	{
		double random = RandomDouble(0, 1);
		for(ui j=0; j<Population; j++)
			if (random < Probs[j])
			{
				MyPop_Temp.push_back(MyPop[j]);
				break;
			}
	}
	MyPop = MyPop_Temp;
	EvaluatePopulation(inf, MyPop_Temp, Evaluator);
	return true;
}

bool Mutation(Info &inf, vector<string> &MyPop)
{
	for(ui i=0; i<Population; i++)
		for (ui j = 0; j < MyPop[i].size(); j++)
		{
			double Random = RandomDouble(0, 1);
			if (Random < 0.015)
			{
				if (MyPop[i][j] == '1')
					MyPop[i][j] = '0';
				else
					MyPop[i][j] = '1';
			}
		}
	return true;
}
bool SwapCrossOver(string &first, string &second)
{
	ui PozBreak = (ui)RandomInt(0, first.size() - 1);
	string temp = first.substr(0, PozBreak);
	first.replace(0, PozBreak, second, 0, PozBreak);
	second.replace(0, PozBreak, temp);
	return true;
}
bool CrossOver(vector<string> &MyPop)
{
	deque<double> Prob;
	deque<int> SelectedPopulation;
	for (ui i = 0; i < Population; i++)
	{
		double Random = RandomDouble(0, 1);
		if (Random < 0.25)
		{
			Prob.push_back(Random);
			SelectedPopulation.push_back(i);
		}
	}
	for (ui i = 1; i < SelectedPopulation.size(); i += 2)
		SwapCrossOver(MyPop[SelectedPopulation[i-1]], MyPop[SelectedPopulation[i]]);
	return true;
}
/*end_genetic_algorithm*/
/*start_results*/
double Maxx(vector<double> dq)
{
	double maxx = dq[0];
	for (ui i = 1; i < dq.size(); i++)
		if (dq[i] > maxx)
			maxx = dq[i];
	return maxx;
}
double Minn(vector<double> dq)
{
	double minn = dq[0];
	for (ui i = 1; i < dq.size(); i++)
		if (dq[i] < minn)
			minn = dq[i];
	return minn;
}
double AVG(vector<double> dq)
{
	double avg = 0.0;
	for (ui i = 1; i < dq.size(); i++)
		avg += dq[i];
	avg /= dq.size();
	return avg;
}

void PrintResultsToFILE(vector<double> results, vector<unsigned long long> generations, ofstream &FisierOut)
{
	for (ui Index = 0; Index < results.size(); Index++)
		FisierOut << Index << ". " << results[Index] << endl;
	FisierOut << "\n\n";
	FisierOut << "Final Results: " << endl;
	FisierOut << "Minim: " << Minn(results) << endl;
	FisierOut << "Maxim: " << Maxx(results) << endl;
	FisierOut << "Medie: " << AVG(results) << endl;
	FisierOut << "\n\n";
} 
void evaluateFUNCTION(int Dimensions, double lower, double higher, ofstream &FisierOut, ui functnr)
{
	vector<double> Results;
	vector<unsigned long long> Generations;
	vector<string> MyPop;
	vector<double> Probs; //intervalele
	vector<double> Evaluator;
	vector<double> Fitness;
	Info inf;
	inf.first = lower;
	inf.last = higher;
	inf.dim = Dimensions;
	inf.BitesPerDim = NrBiti(inf);
	switch (functnr)
	{
	case 1:
	{
		inf.function = DeJong;
		break;
	}
	case 2:
	{
		inf.function = Schwefel;
		break;
	}
	case 3:
	{
		inf.function = Rastrigin;
		break;
	}
	case 4:
	{
		inf.function = SumOfDifferentPower;
		break;
	}
	case 5:
	{
		inf.function = Rosenbrock;
		break;
	}
	case 6:
	{
		inf.function = Griewangk;
		break;
	}
	default:
	{
		cout << "A aparut o eroare.Functie inexistenta." << endl;
		break;
	}
	}
	unsigned long nrGenerations = 0;

	for (ui rulare = 0; rulare < 30; rulare++)
	{
		cout << endl << "Rularea nr:" << rulare << endl;
		MyPop = GeneratePopulation(inf);
		EvaluatePopulation(inf, MyPop, Evaluator);
		double minim = DBL_MAX;
		double Minnn;
		for (ui i = 0; i < 1000; i++)
		{
			Select(inf, MyPop, Evaluator);
			Mutation(inf, MyPop);
			CrossOver(MyPop);
			nrGenerations++;
			Minnn = MinEvaluate(Evaluator);
			//cout << Minnn << "***";
			if (Minnn < minim)
			{
				minim = Minnn;
				cout << minim << " ";
				Results.push_back(minim);
				Generations.push_back(nrGenerations);
			}
		}
	}
	PrintResultsToFILE(Results, Generations, FisierOut);
}
/*end_results*/
int main()
{
	ofstream FF;
	double lower, higher;
	ui nrfunct, dimensions;
/*Start_DeJong*/
	/*5*/ 
		cout << "De Jong pe 5 dim\n";
		FF.open("dejong5dim.out", ios::app);
		lower = -5.12;
		higher = 5.12;
		nrfunct = 1;
		dimensions = 5;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); 
	/*10*/ /*
		cout << "De Jong pe 10 dim\n";
		FF.open("dejong10dim.out", ios::app);
		lower = -5.12;
		higher = 5.12;
		nrfunct = 1;
		dimensions = 10;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*30*/ /*
		cout << "De Jong pe 30 dim\n";
		FF.open("dejong30dim.out", ios::app);
		lower = -5.12;
		higher = 5.12;
		nrfunct = 1;
		dimensions =30;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
/*End_DeJong*/
/*Start_Schwefel*/
	/*5*/ /*
		cout << "Schwefel pe 5 dim\n";
		FF.open("Schwefel5dim.out", ios::app);
		lower = -500;
		higher = 500;
		nrfunct = 2;
		dimensions = 5;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls");  */
	/*10*/ /*
		cout << "Schwefel pe 10 dim\n";
		FF.open("Schwefel10dim.out", ios::app);
		lower = -500;
		higher = 500;
		nrfunct = 2;
		dimensions = 10;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*30*/ /*
		cout << "Schwefel pe 30 dim\n";
		FF.open("Schwefel30dim.out", ios::app);
		lower = -500;
		higher = 500;
		nrfunct = 2;
		dimensions = 30;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
/*End_Schwefel*/
/*Start_Rastrigin*/
	/*5*/ /*
		cout << "Rastrigin pe 5 dim\n";
		FF.open("rastrigin5dim.out", ios::app);
		lower = -5.12;
		higher = 5.12;
		nrfunct = 3;
		dimensions = 5;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*10*/ /*
		cout << "Rastrigin pe 10 dim\n"; 
		FF.open("rastrigin10dim.out", ios::app);
		lower = -5.12;
		higher = 5.12;
		nrfunct = 3;
		dimensions = 10;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*30*/ /*
		cout << "Rastrigin pe 30 dim\n";
		FF.open("rastrigin30dim.out", ios::app);
		lower = -5.12;
		higher = 5.12;
		nrfunct = 3;
		dimensions = 30;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
/*End_Rastrigin*/
/*Start_SumOfDifferentPowers*/
	/*5*/ /*
		cout << "Sum of Different Powers pe 5 dim\n";
		FF.open("sdp5dim.out", ios::app);
		lower = -1;
		higher = 1;
		nrfunct = 4;
		dimensions = 5;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*10*/ /*
		cout << "Sum of Different Powers pe 10 dim\n";
		FF.open("sdp10dim.out", ios::app);
		lower = -1;
		higher = 1;
		nrfunct = 4;
		dimensions = 10;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*30*/ /*
		cout << "Sum of Different Powers pe 30 dim\n";
		FF.open("sdp30dim.out", ios::app);
		lower = -1;
		higher = 1;
		nrfunct = 4;
		dimensions = 30;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
/*End_SumOfDifferentPowers*/
/*Start_Rosenbrock*/
	/*5*/ /*
		cout << "Rosenbrock pe 5 dim\n";
		FF.open("rosenbrock5dim.out", ios::app);
		lower = -2.048;
		higher = 2.048;
		nrfunct = 5;
		dimensions = 5;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */ 
	/*10*/ /*
		cout << "Rosenbrock pe 10 dim\n";
		FF.open("rosenbrock10dim.out", ios::app);
		lower = -2.048;
		higher = 2.048;
		nrfunct = 5;
		dimensions = 10;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close(); 
		system("cls"); */
	/*30*/ /*
		cout << "Rosenbrock pe 30 dim\n";
		FF.open("rosenbrock30dim.out", ios::app);
		lower = -2.048;
		higher = 2.048;
		nrfunct = 5;
		dimensions = 30;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
/*End_Rosenbrock*/
/*Start_Griewangk*/
	/*5*/ /*
		cout << "Griewangk pe 5 dim\n";
		FF.open("Griewangkk5dim.out", ios::app);
		lower = -600;
		higher = 600;
		nrfunct = 6;
		dimensions = 5;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */
	/*10*/ /*
		cout << "Griewangk pe 10 dim\n";
		FF.open("Griewangk10dim.out", ios::app);
		lower = -600;
		higher = 600;
		nrfunct = 6;
		dimensions = 10;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close(); 
		system("cls"); */
	/*30*/ /*
		cout << "Griewangk pe 30 dim\n";
		FF.open("Griewangk30dim.out", ios::app);
		lower = -600;
		higher = 600;
		nrfunct = 6;
		dimensions = 30;
		evaluateFUNCTION(dimensions, lower, higher, FF, nrfunct);
		FF.close();
		system("cls"); */ 
/*End_Griewangk*/ 
	system("pause");
}
