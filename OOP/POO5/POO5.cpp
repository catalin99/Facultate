// POO5.cpp : Defines the entry point for the console application.
//

#pragma warning(disable:4996)
#include "stdafx.h"
#include "Vector.h"

int main()
{
	Vector <int>v;

	v.PushBack(1);
	v.PushBack(5);
	v.PushBack(3);

	v.Print();
	cout << v.AtPos(0) << endl;
	v.InsertAtPos(9, 2);
	v.Print();
	v.EraseAtPos(2);
	v.Print();
	v.Sort();
	v.Print();

	Vector <const char*>siruri;

	siruri.PushBack("madam");
	siruri.PushBack("tata");
	siruri.PushBack("abc");
	siruri.Print();
	siruri.Sort();
	siruri.Print();
	_getch();
    return 0;
}

