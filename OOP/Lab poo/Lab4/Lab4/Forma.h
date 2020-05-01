#pragma once
class Forma
{
//private:
	//char* Afisare;
//protected:
	//int var; //poate fi apelata doar din clasa forma si din clasele mostenitoare
public:
	virtual double ComputeArea() = 0; //functie virtuala pura => clasa abstracta

	virtual const char * GetName() = 0;
	//Forma(char* test);
};

