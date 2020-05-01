
#pragma once
#pragma warning(disable:4996)
#include "Prieten.h"
#ifndef Agenda_h
#define Agenda_h

#include <vector>


class Contact;

class Agenda {

public:

	virtual bool cautare(char* nume);

	virtual void stergere(char* nume);

	virtual void adaugare(char* nume);

	virtual Prieten* lista(char* nume);

public:

	std::vector< Contact* > myContact;
};

#endif // Agenda_h



