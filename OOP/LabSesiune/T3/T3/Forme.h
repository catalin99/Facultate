#pragma once
#include "Forma.h"
class Forme: public Forma
{
	list<Forma*> L;
public:
	Forme();
	~Forme();
	void Add(Forma* F);
	void Paint();
};

