// Lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

class A
{
	int a;
	int b;
public:
	A() {
		a = 0; b = 0;
	}
	A(int aa, int bb)
	{
		a = aa;
		b = bb;
	}
	int getA() { return a; };
};

int cmp(const void*a, const void *b)
{
	int x = *((int*)a);
	int y = *((int*)b);
	return x > y ? 1 : -1;

}

template <class T> //problema 1
void Sort(vector<T> &lista, int(*Compare)(T &e1, T &e2))
{
	for (unsigned int i = 0; i < lista.size() - 1; i++)
		for (unsigned int j = i + 1; j < lista.size(); j++)
			if (Compare(lista[i], lista[j]) > 0)
			{
				T temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
}


template <class T> //problema 2 + qs
void Sort2(vector<T> &v, function<int(T &e1, T &e2)>Compare, int left = 0, int right = -1) 
{
	if (right == -1)
		right = v.size() - 1;

	if (right == left)
		return;

	int pivot = right, wall = left, objCurr = left;
	while (objCurr < pivot) {
		if (Compare(v[objCurr], v[pivot])) 
		{ //v[objCurr] <= v[pivot]
			swap(v[objCurr], v[wall]);
			wall++;
		}
		objCurr++;
	}
	swap(v[wall], v[pivot]);

	Sort2<T>(v, Compare, left, wall - 1);
	Sort2<T>(v, Compare, wall, right);
}
int main()
{
	int a[] = { 2,4,9,13,7 };
	qsort(a, 5, sizeof(int), cmp);
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	//int(*Compare) (int a, int b);
	//function<int(int a, int b)>Compare;
	cout << '\n';
	int value = 100;
	int value2 = 200;
	int xx = -1;
	A b(2,3);
	auto f = [value](int x) -> int {return x + value;};
	//int z = b.getA();
	auto cls = [m=b.getA()](int x) -> int {return x * m;};
	//auto f = [=](int x) {return x + value+value2+xx ;}; //= ia toti parametri
	vector<int> v;
	v.push_back(55);
	v.push_back(31);
	v.push_back(49);
	v.push_back(11);
	Sort<int>(v, [](int &e1, int&e2) -> int {return e1 > e2 ? 1 : -1;}); //prob1
	cout << f(5)<<'\n';
	cout << cls(20)<<'\n';
	for (unsigned int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << '\n';
	vector<int> v2;
	v2.push_back(31);
	v2.push_back(13);
	v2.push_back(25);
	v2.push_back(100);
	v2.push_back(55);
	Sort2<int>(v2, [](int &a, int &b) ->int { return a <= b; });
	for (unsigned int i = 0; i < v2.size(); i++)
		cout << v2[i] << ' ';
}

