#include "RandomGenerator.h"
#include <iostream>
#include <time.h>
#include <random>
#include <chrono>

using namespace std;


int RandomGenerator::SEED = static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count());

RandomGenerator::RandomGenerator(double lower, double higher)
{
	mt19937 randGen(SEED);
	uniform_real_distribution<double> randomGenerator(lower, higher);
	randomNumber = randomGenerator(randGen);
	SEED++;
}


double RandomGenerator::GetNumber()
{
	return randomNumber;
}


