#include <iostream>
#include "Camera.h"
#include "Pestera.h"
#include "Casa.h"


int main()
{
	SpatiuInchis *c1 = new Camera("paie", true, "Culoar frontal");
	SpatiuInchis *c2 = new Camera("urs", false, "Camera ursului");
	SpatiuInchis *c3 = new Camera("rugina", false, "Depozit arme");
	SpatiuInchis *c4 = new Pestera("neutru", false, "Pestera muierilor");
	c4->AddSpatiu(c1);
	c4->AddSpatiu(c2);
	c4->AddSpatiu(c3);

	SpatiuInchis *my_home = new Casa("var", true, "Casa lui Manole");
	my_home->AddSpatiu(new Camera("mucegai", false, "Baie"));
	my_home->AddSpatiu(new Camera("parfum", true, "Sufragerie"));

	c4->PrintInfo();
	my_home->PrintInfo();

	cout << endl;
	cout << "Hello" << endl;
	system("pause");
	return 0;
}