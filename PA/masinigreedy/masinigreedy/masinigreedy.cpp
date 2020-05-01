// masinigreedy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream in("masini.in");
ofstream out("masini.out");

int main()
{
	int n, T, x;
	multiset<int> v;
	in >> n >> T;
	for (int i = 1; i <= n; i++)
	{
		in >> x;
		v.insert(x);
	}
	int s = 0;
	int ct = 0;
	for (auto i : v)
	{
		s += i;
		if (s>T)
			break;
		ct++;
	}
	out << ct;
	return 0;
	
}


