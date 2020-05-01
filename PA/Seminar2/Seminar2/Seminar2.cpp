// Seminar2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

///p1
int AlgEuclidScaderiRepetate(int a, int b)
{
	if (a + b == 0)
		return 0;
	if (a == 0 || b == 0)
		return 0;
	while (a != b)
		if (a > b)
			a = a - b;
		else
			b = b - a;
	return a;
}
int AlgEuclidImpartiriRepetate(int a, int b)
{
	if (a + b == 0)
		return 0;
	if (a == 0 || b == 0)
		return 0;
	int r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int CmmdcCautareExplicita(int a, int b)
{
	if (a + b == 0)
		return 0;
	if (a == 0 || b == 0)
		return 0;
	for (int i = __min(a,b) ; i>=1 ; i--)
		if (a%i == 0 && b%i == 0)
			return i;
	return 0;
}
///p2
//input: 15,75 -> output: 15
//input: 99,9 -> output: 9

///p3
//Raspuns: NU, deoarece problema ce urmeaza este decizionala ->afiseaza "DA" sau "NU" la output in functie de existenta cmmdc
//+ P1 are in plus conditia a+b!=0
void p3(int a, int b)
{
	int rez = AlgEuclidScaderiRepetate(a, b);
	if (rez == 0)
		cout << "NU" << '\n'; 
	else
		cout << "DA" << '\n';
	return;
}

///p4
//complex in cazul cel mai nefavorabil
//uniform: ...DA :|
//logaritmic: ...DA :|

///p5 - PROBLEMA CELOR 8 REGINE
//Enunt: (Fiind dată o tablă de şah de dimensiune 8 x 8, se cere să se aranjeze cele 8 dame în toate modurile posibile pe tabla de şah, 
//		astfel încât să nu se afle pe aceeaşi linie, coloană, sau diagonală(damele să nu se atace).)
//-input: Tabla de sah 8X8 
//-output:  O asezare a 8 regine pe tabla astfel incat nicio regina sa nu atace o alta.
int v[100], sol;
void afisare()
{
	int i, j;
	sol++; cout << "\n Solutia: " << sol << '\n';
	for (i = 1;i <= 8;i++)
	{
		for (j = 1;j <= 8;j++)
			if (v[i] == j) cout << "D ";
			else cout << "_ ";
			cout << '\n';
	}
}
int valid(int k)
{
	int i;
	for (i = 1;i <= k - 1;i++)
		if ((v[i] == v[k]) || (abs(v[k] - v[i]) == (k - i)))
			return 0;
	return 1;
}
int solutie(int k)
{
	if (k == 8)
		return 1;
	return 0;
}
void BK(int k)
{
	int i;
	for (i = 1;i <= 8;i++)
	{
		v[k] = i;
		if (valid(k) == 1)
		{
			if (solutie(k) == 1)
				afisare();
			else
				BK(k + 1);
		}
	}
}

///p6 - problema sortarii in ordine crescatoare a unui sir de numere naturale
//Enunt:
//-Input: n, (a0,a1..an-1), ai-nr nat, oricare ar fi 0<= i <n
//-Output: (ai0,ai1,..ain-1), unde (i0,i1..in-1) apartin (0, 1...n-1)
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    //plasam  pivotul la final
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
///p7
bool bubblesort(int v[], int size)
{
	if (size == 0)
		return 0;
	bool status = true;
	while (status == true)
	{
		status = false;
		for (int i = 1; i < size; i++)
			if (v[i] < v[i - 1])
			{
				swap(v[i], v[i - 1]);
				status = true;
			}
	}
	return 1;
}
bool insertsort(int vect[], int nr)
{
	if (nr == 0)
		return 0;
	int i, j, temp;
	for (i = 1; i < nr; i++)
	{
		j = i - 1;
		temp = vect[i];
		while ((j >= 0) && (vect[j]>temp))
		{
			vect[j + 1] = vect[j];
			j--;
		}
		if (vect[j + 1] != temp)
			vect[j + 1] = temp;
	}
	return 1;
}
bool selectionSort(int arr[], int n)
{
	if (n == 0)
		return false;
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}
	return true;
}

///p8 - pentru orice instanta data ca input, vom avea ca output sirul sortat crescator
//-demonstratia: ...

///p9
///o(n^2) la toate
//modelul uniform: ...
//modelul logaritmic: ...

///p10 - problema satisfiabilitatii pentru formule din LP ca pereche Input-Output
//DA...

///p11 - problema satisfiabilitatii pentru formule din LP1 ca pereche Input-Output
//DA...

///p12 - Problema opririi
//Instance: O configuratie hA, σ0i, unde A este un algoritm  ̧si σ0 codificarea unei intrari pentru A
//Question: Executia care pleaca din configuratia initiala hA, σ0i este finita?

///p13
/*
1) Binary search:
input: Tablou de n elemente sortate crescator, un numar z;
output: true, daca z a fost gasit, false altfel (complexitate O(log2n)
2) Bubblesort:
Input: n, (a0,a1..an-1), ai-nr nat, oricare ar fi 0<= i <n
Output: (ai0,ai1,..ain-1), unde (i0,i1..in-1) apartin (0, 1...n-1)
3) AlgEuclidPrinScaderiRepetate
Input: doua numere a si b, a+b!=0
Output: cmmdc(a,b)
*/

///p14
//Probleme decizionale: P3
//Probleme rezolvabile: toate in afara de problema opririi (P12)

///p15 
//a) problema adunarii
//input (a0,a1,a2,a3..an-1), n=numarul de cifre, b(b0,b1...bm-1), m=numarul de cifre
//output (c0,c1...cr-1), sirul c reprezentand numarul format din adunarea a si b, r=nr de cifre rezultat.
//b) problema inmultirii
//input (a0,a1,a2,a3..an-1), n=numarul de cifre, b(b0,b1...bm-1), m=numarul de cifre
//output (c0,c1...cr-1), sirul c reprezentand numarul format din inmultirea a si b, r=nr de cifre rezultat.

///p16
//...Vezi in BigNumber 

///p17...

///p18...24
int main()
{
	///p1
	//cout << AlgEuclidScaderiRepetate(15, 75) << '\n';
	//cout << AlgEuclidImpartiriRepetate(99, 9) << '\n';
	//cout << CmmdcCautareExplicita(6, 15) << '\n';
	///p3
	//p3(6, 9);
	///p5
	//BK(1);
	///p6
	//int arr[] = { 13, 5, 8, 9, 1, 21 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//quickSort(arr, 0, n - 1);
	//printf("Sorted array: ");
	//printArray(arr, n);
	///p7
	/*
	int arr[] = { 13, 5, 8, 9, 1, 21 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//bubblesort(arr, n);
	//insertsort(arr, n);
	selectionSort(arr, n);
	printArray(arr, n);
	*/
    return 0;
}

