// Lab9.cpp : Defines the entry point for the console application.
//

#pragma warning(disable:4996)
#include "stdafx.h"
#include "Vector.h"
/*
class generic_err
{
public:
	virtual void Err()
	{
		cout << "test clasa generic err\n";
	}
};
class Exc :public exception //clasa predefinita de exceptii
{
public:
	const char* what()const throw()
	{
		return "test complete exc\n";
	}
};
class B:public generic_err
{
public:
	void dd()
	{
		cout << "test clasa mostenitoare\n";
	}
}; */
int main()
{
	/*try
	{
		generic_err z;
		throw z;

		//throw A();
		//throw "Exceptie";
		//throw 1;
	}
	catch (generic_err z)
	{
		z.Err();
	}
	catch (const char* s)//catch (int s)
	{
		cout << "!!!" << s;
	}
	catch (...)
	{
		cout << "Default\n";
	}
	cout << '\n' << '\n';*/
	try {
		Vector <char>z;
		z.PushBack('a');
		z.PushBack('n');
		z.PushBack('b');
		z.InsertAtPos(3, '7');
		z.InsertAtPos(2, 'd');
		z.InsertAtPos(4, 'z');
		z.InsertAtPos(1, 'r');
		z.EraseAtPos(0);
		cout << z.RetAtPos(3) << ' ' << z.RetAtPos(5) << '\n';
		z.Sort();
		z.PrintVect();
		Vector <const char*>r;
		r.PushBack("mama");
		r.PushBack("are albine si pere");
		r.PushBack("D23456789012345678901234567890asdasdasdasdasdasdadas1");
		r.PushBack("Nimeni nu-i cuminte. Alune si prune foarte multe");
		r.InsertAtPos(15, "Insert test");
		r.EraseAtPos(2);
		r.Sort();
		r.PrintVect();
	}
	catch (const char *d)
	{
		cout << d;
	}
	catch (char zz)
	{
		cout << "Exception at return at pos\n";
	}
	return 0;
}

