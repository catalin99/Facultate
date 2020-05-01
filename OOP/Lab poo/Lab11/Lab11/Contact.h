
#pragma once
#pragma warning(disable:4996)
#ifndef Contact_h
#define Contact_h


class Agenda;

class Contact {

public:
	char* nume;

public:

	/**
	* @element-type Agenda
	*/
	Agenda *myAgenda;
};

#endif // Contact_h

