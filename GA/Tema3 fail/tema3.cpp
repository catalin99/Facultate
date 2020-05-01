#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <random>
#include <utility>
#include <map>
#include <cmath>

const size_t NumarCromozomi = 10;
const size_t NumarGeneratii = 30;

int RandomInt(int first, int last)
{
	int nrRandI = 0;
	std::random_device seed;
	std::mt19937 rand(seed());
	std::uniform_int_distribution<int> dist(first, last-1);
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

void ReadCities(std::deque <std::pair<double,double>>& Cities, size_t& NrOrase)
{
	unsigned int nrCur;
	double x, y;
	std::ifstream f("dateTSP.txt", std::ios::in);
	f >> NrOrase;
	for (size_t NrCur = 0; NrCur < NrOrase; NrCur++)
	{
		f >> nrCur;
		f >> x;
		f >> y;
		std::pair<double, double> CoordActuale(x, y);
		Cities.emplace_back(CoordActuale);
	}
	f.close();
}

void CalculDistance(std::map<size_t, double>& CurrentDistance, const size_t& NrOrase, const double& CoordX, const double& CoordY, const size_t& OrasCurent, const std::deque <std::pair<double, double>>& Cities)
{
	for (size_t it = 0; it < Cities.size(); ++it)
	{
		double Distance;
		if (it != OrasCurent)
		{
			double One; double Two;
			One = Cities[it].first - CoordX;
			One *= One;
			Two = Cities[it].second - CoordY;
			Two *= Two;
			Distance = One + Two;
			Distance = sqrt(Distance);
			CurrentDistance[it] = Distance;
		}
	}
}

void CalculAllDistances(std::deque<std::map<size_t, double>>&  AllDistances, const size_t& NrOrase, const std::deque <std::pair<double, double>>& Cities)
{
	for (size_t it = 0; it < Cities.size(); it++)
	{
		std::map<size_t, double> CurrentDistance;
		CurrentDistance.clear();
		CalculDistance(CurrentDistance, NrOrase, Cities[it].first, Cities[it].second, it, Cities);
		AllDistances.emplace_back(CurrentDistance);
	}
}

void GenerateCromozom(const size_t& NrOrase, std::deque<int>& Cromozom)
{
	for (size_t i = 0; i < NrOrase; i++)
		Cromozom.emplace_back(RandomInt(0, NrOrase - i));
}

void GeneratePopulation(const size_t& NrOrase, std::deque<std::deque<int>>& MyPopulation)
{
	for (size_t i = 0; i < NumarCromozomi; i++)
	{
		std::deque<int> Individ;
		Individ.clear();
		GenerateCromozom(NrOrase, Individ);
		MyPopulation.emplace_back(Individ);
	}
}

void DecodeCromozom(const size_t& NrOrase, std::deque<int> &DecodedCromozom, std::deque<int>& Cromozom)
{
	std::deque<int> OraseOrdonate;
	OraseOrdonate.clear();
	for (size_t k = 0; k < NrOrase; k++)
		OraseOrdonate.emplace_back(k);
	
	for (size_t i = 0; i < NrOrase; i++)
	{
		std::cout << '*' << Cromozom[i] << '&' << OraseOrdonate[Cromozom[i]] << '*';
		DecodedCromozom.emplace_back(OraseOrdonate[Cromozom[i]]);
		OraseOrdonate.erase(OraseOrdonate.begin()+Cromozom[i]);
	}
	//DecodedCromozom.emplace_back(0);
	std::cout << std::endl;
}

void DecodePop(const size_t& NrOrase, std::deque<std::deque<int>>& DecodedPop, std::deque<std::deque<int>>& MyPop)
{
	for (size_t j = 0; j < NumarCromozomi; j++)
	{
		std::deque<int> currentdecode;
		currentdecode.clear();
		DecodeCromozom(NrOrase, currentdecode, MyPop[j]);
		DecodedPop.emplace_back(currentdecode);
	}
}

size_t FindElement(const int& Elem, const std::deque<int>& Where)
{
	for (size_t it = 0; it < Where.size(); it++)
	{
		if (Where[it] == Elem)
		{
			return it;
		}
	}
	return Where.size();
}

void EncodeCromozom(const size_t& NrOrase, std::deque<int> &EncodedCromozom, std::deque<int> Cromozom)
{
	for (size_t i = 0; i < Cromozom.size(); i++)
		EncodedCromozom.push_back(i);
	EncodedCromozom.swap(Cromozom);
	for (size_t city = 0; city < EncodedCromozom.size(); city++)
	{
		size_t Pozition = FindElement(EncodedCromozom[city], Cromozom);
		EncodedCromozom[city] = int(Pozition);
		Cromozom.erase(Cromozom.begin() + Pozition);
	}
}

void EncodePop(const size_t& NrOrase, std::deque<std::deque<int>>& EncodedPop, std::deque<std::deque<int>>& MyPop)
{
	for (size_t j = 0; j < NumarCromozomi; j++)
	{
		std::deque<int> currentencode;
		currentencode.clear();
		EncodeCromozom(NrOrase, currentencode, MyPop[j]);
		EncodedPop.emplace_back(currentencode);
	}
}

void CrossOver(const size_t& NrOrase, std::deque<int>& Cromozom_1, std::deque<int>&Cromozom_2)
{
	int prob = RandomInt(0, 100);
	if (prob <= 27)
	{
		size_t CutPozition = RandomInt(1, NrOrase - 1);
		std::deque<int> Cromozom_Temp = Cromozom_1;
		Cromozom_1.erase(Cromozom_1.begin() + CutPozition, Cromozom_1.end());
		for (size_t i = CutPozition; i < Cromozom_2.size(); i++)
		{
			Cromozom_1.emplace_back(Cromozom_2[i]);
		}
		Cromozom_2.erase(Cromozom_2.begin() + CutPozition, Cromozom_2.end());
		for (size_t i = CutPozition; i < Cromozom_Temp.size(); i++)
		{
			Cromozom_2.emplace_back(Cromozom_Temp[i]);
		}
	}
}

void Mutation(const size_t& NrOrase, std::deque<int>& Cromozom, const double& prob)
{
	for (size_t it = 0; it < NrOrase; it++)
	{
		double DoMutation = RandomDouble(0.00, 100.00);
		if (DoMutation <= prob)
		{
			if (Cromozom[it] <= NrOrase - 2) //can inc
				Cromozom[it]++;
			else if(Cromozom[it] >=1)//can dec
				Cromozom[it]--;
		}
	}
}

void PrepareProbabilyForMutation(double& prob)
{
	if (prob < 0.025)
		return;
	double HowMuch = 0.01*prob;
	prob = prob - HowMuch;
}

double Fitness(const std::deque<int> &Cromozom, const std::deque<std::map<size_t, double>>&  AllDistances, double& DrumMinim)
{
	double CostTotal = 0.;
	for (size_t it = 1; it < Cromozom.size(); ++it)
	{
		std::map<size_t, double> TempMap = AllDistances[Cromozom[it - 1]];
		CostTotal += TempMap[Cromozom[it]];
	}
	std::map<size_t, double> MapFinal = AllDistances[Cromozom[Cromozom.size()-1]];
	CostTotal += MapFinal[Cromozom[0]];
	if (DrumMinim > CostTotal)
	{
		DrumMinim = CostTotal;
		std::cout << DrumMinim << " | ";
	}
	return 1. / CostTotal;
}

double Next_Generation(std::deque<std::deque<int>>& Pop, const size_t& NrOrase, const std::deque<std::map<size_t, double>>&  AllDistances, double &prob)
{
	std::deque<std::deque<int>> DecodedPop;
	DecodedPop.clear();
	DecodePop(NrOrase, DecodedPop, Pop);
	std::deque<double> FITNESS;
	double DrumMinim = DBL_MAX;
	for (size_t it = 0; it < DecodedPop.size(); it++)
	{
		double Fitnesstemp = Fitness(DecodedPop[it], AllDistances, DrumMinim);
		
		FITNESS.emplace_back(Fitnesstemp);
	}
	std::cout << std::endl;
	double SumFitness = 0.;
	for (size_t Fit = 0; Fit < FITNESS.size(); Fit++)
	{
		SumFitness += FITNESS[Fit];
	}

	std::deque<double> IntervaleProbabilitate;
	for (size_t it = 0; it < Pop.size(); it++)
	{
		if (it == 0)
			IntervaleProbabilitate.emplace_back(FITNESS[it] / SumFitness);
		else if (it == Pop.size()-1)
			IntervaleProbabilitate.emplace_back(1.);
		else
			IntervaleProbabilitate.emplace_back(IntervaleProbabilitate[it-1]+(FITNESS[it] / SumFitness));
	}

	std::deque<std::deque<int>> SelectedPop;
	for (size_t it = 0; it < Pop.size(); ++it)
	{
		double NrRand = RandomDouble(0., 2.);
		for (size_t prob = 0; prob < IntervaleProbabilitate.size(); ++prob)
		{
			if (NrRand <= IntervaleProbabilitate[prob])
			{
				SelectedPop.emplace_back(Pop[prob]);
				break;
			}
		}
	}

	//std::deque<std::deque<int>> EncodedPop;
	//EncodePop(NrOrase, EncodedPop, DecodedPop);

	Pop = SelectedPop;
	for (size_t it = 1; it < Pop.size(); ++it)
	{
		CrossOver(NrOrase, Pop[it - 1], Pop[it]);
	}

	PrepareProbabilyForMutation(prob);
	for (size_t it = 0; it < Pop.size(); ++it)
	{
		Mutation(NrOrase, Pop[it], prob);
	}

	return DrumMinim;
}

void Genetic_Algorithm(std::deque<std::deque<int>>& Pop, const size_t& NrOrase, const std::deque<std::map<size_t, double>>&  AllDistances)
{
	double probStart = 5.;
	double MinGlobal = DBL_MAX;
	double MaxGlobal = DBL_MIN;
	double SumForAvg = 0.;
	for (size_t Generatie = 0; Generatie < NumarGeneratii; ++Generatie)
	{
		double ActualMin=Next_Generation(Pop, NrOrase, AllDistances, probStart);
		if (ActualMin < MinGlobal)
			MinGlobal = ActualMin;
		if (ActualMin > MaxGlobal)
			MaxGlobal = ActualMin;
		SumForAvg += ActualMin;
	}
	double Avg = SumForAvg / NumarGeneratii;
	std::cout << "\n\n\n";
	std::cout << "Valoare minima: " << MinGlobal << "\n\n";
	std::cout << "Valoare maxima: " << MaxGlobal << "\n\n";
	std::cout << "Valoare medie: " << Avg << "\n\n";
}

int main()
{
	
	//read cities+distances
	size_t NrCities;
	std::deque <std::pair<double, double>> Cities;
	ReadCities(Cities, NrCities);
	std::deque<std::map<size_t, double>>  AllDistances;
	CalculAllDistances(AllDistances, NrCities, Cities);
	//end
	
	//pop start
	std::deque<std::deque<int>> Pop;
	GeneratePopulation(NrCities, Pop);
	//end

	Genetic_Algorithm(Pop, NrCities, AllDistances);
	std::cout << "Algoritmul a fost rulat pentru urmatoarele instante:\n";
	std::cout << "Numar generatii: " << NumarGeneratii << '\n';
	std::cout << "Numar indivizi in populatie: " << NumarCromozomi << '\n';
	std::cout << "Numarul de orase: " << NrCities;

	

	/*std::cout << std::endl << std::endl;
	for (size_t it = 0; it < Cities.size(); it++)
	{
		std::cout << it << ": " << Cities[it].first << ' ' << Cities[it].second << std::endl;
	}
	std::deque<std::map<size_t, double>>  AllDistances;
	CalculAllDistances(AllDistances, NrCities, Cities);
	for (size_t i = 0; i < AllDistances.size(); i++)
	{
		std::cout << "Node: " << i << '\n';
		for (auto j : AllDistances[i])
			std::cout << "\tDistance to " << j.first << " : " << j.second << '\n';
		std::cout << '\n';
	}*/
	/*std::cout << "\n\nCross Over 0 & 1\n\n\n";
	CrossOver(Orase, DecPop[0], DecPop[1]);
	for (size_t ipop = 0; ipop < NumarCromozomi; ipop++)
	{
		for (size_t icrom = 0; icrom < Orase; icrom++)
			std::cout << DecPop[ipop][icrom] << " ";
		std::cout << std::endl;
	}
	
	std::cout << "\n\nMutation\n\n\n";
	for (size_t i = 0; i < NumarGeneratii; i++)
	{
		PrepareProbabilyForMutation(StartProbability);
		std::cout << "\n\nProbabilitate de mutatie: " << StartProbability << std::endl;
		std::cout <<"Generatie "<<i << std::endl;
		for (size_t ipop = 0; ipop < NumarCromozomi; ipop++)
		{
			Mutation(Orase, DecPop[ipop], StartProbability);
			for (size_t icrom = 0; icrom < Orase; icrom++)
				std::cout << DecPop[ipop][icrom] << " ";
			std::cout << std::endl;
		}
	}*/
	/*
	*/
	system("pause");

}