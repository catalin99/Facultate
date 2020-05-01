#include "stdafx.h"
#pragma once
#pragma warning(disable:4996)
#define MAX_SIZE 100
typedef unsigned int ui;
template <class T>
class Vector
{
private:
	T vect[MAX_SIZE];
	ui len;
	void _Swap(T &char1, T &char2)
	{
		T temp = char1;
		char1 = char2;
		char2 = temp;
	}
public:
	Vector()
	{
		for (ui i = 0; i < MAX_SIZE; i++)
			vect[i] = 0;
		len = 0;
		cout << "constructor default \n";
	}
	void PrintVect()
	{
		for (ui i = 0; i < len; i++)
			cout << vect[i] << ' ';
		cout << '\n';
	}
	void PushBack(T character)
	{
		vect[len] = character;
		len++;
	}
	bool InsertAtPos(ui poz, T character)
	{
			if (poz > len)
				//return false;
				throw "Exception: poz>len (Insert At Pos default template) \n";
		for (ui i = len; i > poz; i--)
			vect[i] = vect[i - 1];
		vect[poz] = character;
		len++;

		return true;

	}
	bool EraseAtPos(ui poz)
	{
		if (poz >= len)
			//return false;
			throw "Exception: poz>len (Erase at pos default template) \n";
		for (ui i = poz; i < len; i++)
			vect[i] = vect[i + 1];
		len--;
		return true;
	}

	T RetAtPos(ui poz)
	{
		if (poz >= len)
			//return NULL;
			throw NULL;
		return vect[poz];
	}

	bool Sort()
	{
		if (len <= 1)
			//return false;
			throw "Exception len<=1 (Sort default template) \n";
		for (ui i = 0; i < len - 1; i++)
			for (ui j = i + 1; j < len; j++)
				if (vect[i] > vect[j])
					_Swap(vect[i], vect[j]);
		return true;

	}
};
#undef MAX_SIZE
#define MAX_SIZE 15
template<>
class Vector<const char *>
{
private:
	char* vect[MAX_SIZE];
	ui len;
	void _CSwap(char* &char1, char* &char2)
	{
		char* temp = new char[256];
		strcpy(temp, char1);
		strcpy(char1, char2);
		strcpy(char2, temp);
	}
public:
	Vector()
	{

		for (ui i = 0; i < MAX_SIZE; i++)
		{
			vect[i] = new char[256];
			strcpy(vect[i], "\0");
		}
		len = 0;
		cout << "constructor default const char* \n";
	}
	void PrintVect()
	{
		for (ui i = 0; i < len; i++)
			cout << vect[i] << ' ';
		cout << '\n';
	}
	void PushBack(const char* sir)
	{
		strcpy(vect[len], sir);
		len++;
	}
	bool InsertAtPos(ui poz, const char* sir)
	{
		if (poz > len)
			//return false;
			throw "Exception: poz>len (InsertAtPos const char*) \n";
		for (ui i = len; i > poz; i--)
			strcpy(vect[i], vect[i - 1]);
		strcpy(vect[poz], sir);
		len++;
		return true;
	}
	bool EraseAtPos(ui poz)
	{
		if (poz >= len)
			//return false;
			throw "Exception: poz>=len (EraseAtPos const char*) \n";
		for (ui i = poz; i < len; i++)
			strcpy(vect[i], vect[i + 1]);
		len--;
		return true;
	}

	char* RetAtPos(ui poz)
	{
		if (poz >= len)
			//return NULL;
			throw NULL;
		return vect[poz];
	}

	bool Sort()
	{
		if (len <= 1)
			//return false;
			throw "Exception len<=1 (Sort const char*) \n";
		for (ui i = 0; i < len - 1; i++)
			for (ui j = i + 1; j < len; j++)
				if (strcmp(vect[i], vect[j])>0)
					_CSwap(vect[i], vect[j]);
		return true;

	}
};

