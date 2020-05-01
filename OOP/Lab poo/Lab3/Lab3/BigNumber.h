#pragma once
class BigNumber
{
private:
	char Number[999];
	int  CharactersCount;
	bool RealNumber();

public:
	int ChCount=0;
	BigNumber(); // Constructor implicit (creaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]
	BigNumber(int value);
	BigNumber(const char * number);
	BigNumber(const BigNumber &number);
	
	bool Set(int value);
	bool Set(const char * number);
	
	BigNumber operator+ (const BigNumber &number);
	BigNumber operator* (const BigNumber &number); //working progress
	BigNumber operator- (const BigNumber &number); //working progress
	BigNumber operator/ (const BigNumber &number); //working progress

	char operator[] (int index); // returneaza caracterul de pe pozitia index sau \0 in rest
	BigNumber operator() (int start, int end); // returneaza numarul de la caracterul dat de pozitia "start" pana la caracterul dat de pozitia "end" sau "0" daca start/end nu sunt valide.

	friend bool operator == (const BigNumber & n1, const BigNumber & n2);
	friend bool operator >= (const BigNumber & n1, const BigNumber & n2); //netestat, dar ar trebui sa mearga...
	friend bool operator <= (const BigNumber & n1, const BigNumber & n2); //netestat, dar ar trebui sa mearga...
	friend bool operator < (const BigNumber & n1, const BigNumber & n2); //netestat, dar ar trebui sa mearga...
	friend bool operator > (const BigNumber & n1, const BigNumber & n2); //netestat, dar ar trebui sa mearga...
	friend bool operator != (const BigNumber & n1, const BigNumber & n2); //netestat, dar ar trebui sa mearga...

	void testData();
	bool Afisare();
};

