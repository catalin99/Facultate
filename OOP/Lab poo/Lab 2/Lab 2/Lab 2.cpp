// Lab 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "MyString.h"

int main()
{
	MyString test("plebii camerei 46:");
	///Concatenare test:
	//test.Add(" mihnea si andrei");
	///Setare test:
	//test.Set("Babuin");
	///end
	///New class for functions with MyString parameters 
	MyString bunoaca;
	bunoaca.Set("no plebs ");
	//bunoaca.Add(test);
	//bunoaca.Set(test);
	///end
	///Return dimension test:
	//cout << test.GetSize() << '\n';
	///Return text test:
	//cout << test.GetText() << '\n';
	///end
	///Substring tests:
	//MyString *xx = test.SubString(7, 7); //poz 7, primele 7 caractere
	//cout << "xx class: ";
	//xx->TestData();
	///end
	///delete test:
	//test.Delete(3, 4);
	//test.TestData();
	///end
	///cmp test::
	//cout<<test.Compare("plebii camerei 46:")<<'\n';
	//cout << test.Compare(bunoaca) << '\n';
	///end
	///return char de pe poz test
	//cout << test.GetChar(12) << '\n';
	//cout << test.GetChar(21) << '\n';
	///end
	///Insert to index test:
	//test.Insert(7, "pro ");
	//test.TestData();
	test.Insert(7, bunoaca);
	test.TestData();
	///end
	///find test
	//cout<<test.Find("ca");
	///find last test
	//cout<<test.FindLast("ca");
	///end
	//bunoaca.TestData();
    return 0;
}

