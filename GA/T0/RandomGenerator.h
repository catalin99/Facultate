#pragma once

class RandomGenerator
{
private:

	double randomNumber;


public:

	RandomGenerator() = delete;
	RandomGenerator(double lower, double higher);
	double GetNumber();
	static int SEED;
};

