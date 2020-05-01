// supermarket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HyperMarket.h"
#include "Lidl.h"
#include "Kaufland.h"
#include "Carrefour.h"

int main()
{
	HyperMarket *Hyp = new Kaufland("Bucharest", 25000, 200, 3500);//Nu adauga si acest obiect kaufland in lista..dar asta e :>
	Lidl d("Bucharest", 25000, 200, 3500);
	Carrefour c("Iasi", 2333, 14, 4000);
	Lidl z("Bacau", 4111, 15, 2500);
	Kaufland k("Roman", 29991, 140, 4100);
	Kaufland r("Cluj", 3123, 222, 4333);
	Hyp->AddItem(&c);
	Hyp->AddItem(&z);
	Hyp->AddItem(&d);
	Hyp->AddItem(&k);
	Hyp->AddItem(&r);
	Hyp->Print();
	return 0;

}

