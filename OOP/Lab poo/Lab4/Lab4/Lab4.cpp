// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Forma.h"
#include "Dreptunghi.h"
#include "Cerc.h"
#include "Triunghi.h"


int main()
{

	Forma *f[5];
	///Forma b; //nu compileaza pentru ca clasa forma este abstracta => nu se pot instantia obiecte
				//ar fi mers daca Forma nu avea functii virtuale !!!Pure!!! (cu =0)
	/* ///Merge -> e pointer catre o instanta, nu o instanta propriu-zisa
	Forma *c;
	c = new Cerc(4);
	cout << c->GetName() << '\n';
	cout << c->ComputeArea() << '\n';
	*/
	///Forma &ref; //nu merge->referinta!=pointer, ea trebuie initializata la declarare
	///Testare atribuire ref->pointer  --start-- //fail
	//Forma *pointer = new Dreptunghi(3, 10);
	//Forma *test = &pointer; //error: connot conver from ** to *
	///--end--

	f[0] = new Dreptunghi(7,5);
	f[1] = new Cerc(13);
	f[2] = new Triunghi(2, 15, 7, 12, 13, 13);
	f[3] = new Dreptunghi(21, 19);
	f[4] = new Triunghi(-1, 4, -15, 7, 11, 23);
	/*
	cout << f[0]->GetName()<<'\n';
	cout << f[0]->ComputeArea()<<'\n';
	cout << f[1]->GetName() << '\n';
	cout << f[1]->ComputeArea() << '\n';
	cout << f[2]->GetName() << '\n';
	cout << f[2]->ComputeArea() << '\n';
	*/
	for (int i = 0; i <= 4; i++)
	{
		cout << f[i]->GetName() << '\n';
		cout << f[i]->ComputeArea() << '\n';
	}
	//Dreptunghi *d = new Dreptunghi(10, 3); //it works too
	return 0;
}

