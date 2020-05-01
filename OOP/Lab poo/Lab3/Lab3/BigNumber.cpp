#include "stdafx.h"
#include "BigNumber.h"
using namespace std;
typedef unsigned int ui;
#pragma warning(disable:4996)

BigNumber::BigNumber()
{
	Number[0] = '0';
	Number[1] = '\0';
	CharactersCount = 1;
}

BigNumber::BigNumber(int value) //retine numarul invers
{
	ui i = 0;
	while (value)
	{
		Number[i] = (value % 10) + '0';
		i++;
		value /= 10;
	}
	Number[i] = '\0';
	CharactersCount = i;
}

BigNumber::BigNumber(const char * number)
{
	int j = 0;
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		Number[j++] = number[i];
	}
	Number[j] = '\0';
	CharactersCount = j;
}

BigNumber::BigNumber(const BigNumber &number)
{
	strcpy(Number, number.Number);
	Number[strlen(Number)] = '\0';
	CharactersCount = strlen(Number);
}

bool BigNumber::Set(int value)
{
	if (value == 0)
	{
		Number[0] = '0';
		Number[1] = '\0';
		CharactersCount = 1;
		return false;
	}
	strcpy(Number, "\0");
	ui i = 0;
	while (value)
	{
		Number[i] = (value % 10) + '0';
		i++;
		value /= 10;
	}
	Number[i] = '\0';
	CharactersCount = i;
	return true;
}

bool BigNumber::Set(const char *number)
{
	if (number[0] == NULL)
		return false;
	strcpy(Number, "\0");
	int j = 0;
	for (int i = strlen(number) - 1; i >= 0; i--)
	{
		Number[j++] = number[i];
	}
	Number[j] = '\0';
	CharactersCount = j;
	return true;
}

BigNumber BigNumber::operator+ (const BigNumber &number) //done
{
	ui LungMax = 0;
	ui Transport = 0;
	ui i;
	LungMax = __max(strlen(Number), strlen(number.Number));
	BigNumber newbig;
	for (i = 0; i <= LungMax; i++)
	{
		int actual = 0;
		int N;
		if (i >= strlen(Number))
			N = (number.Number[i] - '0') + Transport;
		else if (i >= strlen(number.Number))
			N = (Number[i] - '0') + Transport;
		else if (i >= strlen(Number) && i >= strlen(number.Number))
		{
			N = Transport;
		}
		else
			N = (Number[i] - '0') + (number.Number[i] - '0') + Transport;
		if(i!=LungMax)
		if (N > 9)
		{
			actual = N % 10;
			Transport = N / 10;
		}
		else
		{
			actual = N;
			Transport = 0;
		}
		if (i == LungMax && Transport == 0)
			newbig.Number[i] = '\0';
		else if (i == LungMax && Transport == 1)
		{
			newbig.Number[i] = '1';
			newbig.Number[i + 1] = '\0';
		}
		else 
		{
			newbig.Number[i] = actual + '0';
			newbig.Number[i + 1] = '\0';
		}
	}
	newbig.CharactersCount = i - 1;
	return newbig;

}

BigNumber BigNumber::operator*(const BigNumber &number) //done
{
	BigNumber newmul;
	if ((number.Number[0] == '0' && number.CharactersCount == 1) || (Number[0] == '0' && CharactersCount == 1))
		return newmul;
	ui nr1[999], nr2[999], i, j, rez[999];
	//Punem ambele numere in cate un vector
	for (i = 0; i < strlen(Number); i++)
		nr1[i] = Number[i] - '0';
	for (j = 0; j < strlen(number.Number); j++)
		nr2[j] = number.Number[j] - '0';
	ui counterfin = (i-1) + (j-1);
	//initializam vectorul rezultatelor cu 0
	for (i = 0; i <= counterfin+1; i++)
		rez[i] = 0;
	//facem inmultirile
	for (j = 0; j < strlen(number.Number); j++)
		for (i = 0; i < strlen(Number); i++)
			rez[i + j] += nr1[i] * nr2[j];
	//mutam transportul unde trebuie
	bool newpoz = false; //in cazul in care vom avea transport si pe ultima pozitie
	for(i=0; i <= counterfin; i++)
		if (rez[i] > 9)
		{
			rez[i + 1] += rez[i] / 10;
			rez[i] = rez[i] % 10;
			if (i + 1 == counterfin + 1)
				newpoz = true;
		}
	//mutam numarul din vector in noul bignumber
	if (newpoz == true)
		counterfin++;
	for (i = 0; i <= counterfin; i++)
		newmul.Number[i] = rez[i] + '0';
	newmul.Number[i] = '\0';
	CharactersCount = strlen(newmul.Number);
	return newmul;
}

BigNumber BigNumber::operator- (const BigNumber &number) //done !!!Functioneaza doar cand scadem numar mai mic din numar mai mare!!!
{
	short tempbig, templow, transport=0;
	BigNumber newminus;
	bool status = true;
	for (ui i = 0; i < strlen(Number); i++)
	{
		//se retine numarul din care scadem
		tempbig = Number[i] - '0';
		//se retine numarul pe care il scadem
		if (i >= strlen(number.Number))
			templow = 0;
		else
			templow = number.Number[i] - '0';
		//daca avem transport de la operatiile anterioare
		if (transport == 1)
		{
			if (!tempbig) //cazul in care cifra din care scadem e 0
			{
				status = false; //trebuie sa se imprumute mai departe daca am mai avut transport
				tempbig = 9; //cifra devine 9
			}
			else
				tempbig--;
		}
		
		//cazul in care avem transport:
		if (tempbig < templow)
		{
			tempbig += 10;
			transport = 1;
		}
		else
		{
			if (status == false)
			{
				transport = 1;
				status = true;
			}
			else
				transport = 0;
		}
		//operatia propriu-zisa
		newminus.Number[i] = (tempbig - templow) + '0';
		newminus.Number[i + 1] = '\0';
		CharactersCount = strlen(newminus.Number);
	}
	return newminus;
}

BigNumber BigNumber::operator/ (const BigNumber &number) //working progress
{
	return 0; ///nop
	///renunt...prea naspa
}

char BigNumber::operator[] (int index) //deoarece numarul este retinut invers pentru a usura calculele, indexul va fi calculat de la coada sirului
{
	int k = strlen(Number);
	k -= index;
	k--;
	return Number[k];
}

BigNumber BigNumber::operator() (int start, int end) //apelam intai functia de RealNumber pentru a avea sirul pus ca la inceput
{
	if (start > CharactersCount || end > CharactersCount)
		return 0;
	RealNumber();
	BigNumber dd;
	strcpy(dd.Number, "\0");
	strncpy(dd.Number, Number + start, end - start +1 );
	strcpy(dd.Number+(end-start+1), "\0");
	dd.CharactersCount = strlen(dd.Number);
	return dd;
}

bool operator == (const BigNumber & n1, const BigNumber & n2)
{
	if (!strcmp(n1.Number, n2.Number))
		return true;
	return false;
}

bool operator >= (const BigNumber & n1, const BigNumber & n2)
{
	if (!strcmp(n1.Number, n2.Number) || strcmp(n1.Number, n2.Number)>0)
		return true;
	return false;
}

bool operator <= (const BigNumber & n1, const BigNumber & n2)
{
	if (!strcmp(n1.Number, n2.Number) || strcmp(n1.Number, n2.Number)<0)
		return true;
	return false;
}

bool operator < (const BigNumber & n1, const BigNumber & n2)
{
	if (strcmp(n1.Number, n2.Number)<0)
		return true;
	return false;
}

bool operator > (const BigNumber & n1, const BigNumber & n2)
{
	if (strcmp(n1.Number, n2.Number)>0)
		return true;
	return false;
}

bool operator != (const BigNumber & n1, const BigNumber & n2)
{
	if (strcmp(n1.Number, n2.Number))
		return true;
	return false;
}

void BigNumber::testData() //Afiseaza numarul de caractere si sirul asa cum este retinut la momentul actual
{
	cout << CharactersCount << " : " << Number << '\n';
}

bool BigNumber::RealNumber() //Inverseaza sirul 
//util pentru ca la inceput sirul este retinut invers pentru a usura calculele;
{
	if (Number[0] == NULL)
		return false;
	for (int i = 0; i < (int)(strlen(Number)/2); i++)
		swap(Number[i], Number[strlen(Number) - i - 1]);
	return true;

}

bool BigNumber::Afisare()
{
	if (Number[0] == NULL)
		return false;
	RealNumber(); //Da reverse la sir pentru a-l afisa cum trebuie (NU inversat)
	cout << "Numarul este: " << Number << " (" << CharactersCount << ")" << '\n';
	return true;
}

