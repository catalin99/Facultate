// T1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Masina.h"
#include "MasinaOras.h"
#include "SUV.h"
#include "Opel.h"
#include "Dacia.h"
#include "RangeRover.h"
#include <string>
using namespace std;

int main()
{
	Opel o;
	o.setCapacitate(100);
	o.setCuloare("rosu");
	o.SetAnFabricatie(2000);
	MasinaOras *m = &o;
	cout << m->getName() << "," << m->getCuloare() << "," << m->getCapacitate() << "," << o.getAnFabricatie() << endl;
	//cout << m->getCapacitate() << "," << o.getAnFabricatie() << endl;
	//string s1("dada");
	//cout << s1.c_str();
	return 1;
    
}

