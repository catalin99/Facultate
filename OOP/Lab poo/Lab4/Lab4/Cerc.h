#include "Forma.h"
#pragma once

class Cerc : public Forma 
{

	int Raza;

public:

	Cerc(int raza);

	double ComputeArea();

	const char * GetName();


};
