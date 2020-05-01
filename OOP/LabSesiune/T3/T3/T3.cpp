// T3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Forma.h"
#include "Dreptunghi.h"
#include "Oval.h"
#include "Cerc.h"
#include "DreptunghiRotit.h"
#include "Forme.h"

int main()
{
	Forme f;
	Cerc c;
	c.set(10, 10, 100);
	Oval o;
	o.set(20, 20, 50, 100);
	DreptunghiRotit p;
	p.set(5, 5, 2, 10, 30);
	f.Add(&c);
	f.Add(&o);
	f.Add(&p);
	f.Paint();
}

