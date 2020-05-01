// Lab5.cpp : Defines the entry point for the console application.
//
#pragma warning(disable:4996)
#include "stdafx.h"
#include "Vector.h"

int main()
{
	Vector <char>z;
	z.PushBack('a');
	z.PushBack('n');
	z.PushBack('b');
	z.InsertAtPos(3, '7');
	z.InsertAtPos(2, 'd');
	z.InsertAtPos(4, 'z');
	z.InsertAtPos(1, 'r');
	z.EraseAtPos(0);
	cout<<z.RetAtPos(3) <<' '<< z.RetAtPos(5) << '\n';
	z.Sort();
	z.PrintVect();
	Vector <const char*>r;
	r.PushBack("mama");
	r.PushBack("are albine si pere");
	r.PushBack("D23456789012345678901234567890asdasdasdasdasdasdadas1");
	r.PushBack("Mihnea e cuminte. Alune si prune foarte multe");
	r.InsertAtPos(2, "Insert test");
	r.EraseAtPos(0);
	r.Sort();
	r.PrintVect();
    return 0;
}

