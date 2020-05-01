// T4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Camera.h"
#include "Pestera.h"
#include "Casa.h"

int main()
{
	SpatiuInchis *c1 = new Camera("paie", true, "culoare frontal");
	SpatiuInchis *c2 = new Camera("urs", false, "camera ursului");
	SpatiuInchis *c3 = new Camera("rugina", false, "depozit arme");
	SpatiuInchis *c4 = new Pestera("neutru", false, "Pestera muierilor");
	c4->AddSpatiu(c1);
	c4->AddSpatiu(c2);
	c4->AddSpatiu(c3);
	SpatiuInchis *my_home = new Casa("var", true, "Casa lui Manole");
	my_home->AddSpatiu(new Camera("mucegai", false, "Baie"));
	my_home->AddSpatiu(new Camera("parfum", true, "Sufragerie"));
	c4->PrintInfo();
	my_home->PrintInfo();
	return 0;
}

