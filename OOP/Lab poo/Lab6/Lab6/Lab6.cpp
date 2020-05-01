// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <gtest/gtest.h>

#pragma warning(disable:4996)
#pragma once
typedef unsigned int ui;
using namespace std;
FILE *pfile = fopen("input.txt", "r");
char* sirlungmax(vector<const char*> t)
{
	int max = -1;
	char *d = new char[30];
	d[0] = '\0';
	vector<const char*>::iterator it;
	for(it=t.begin();it<t.end();it++)
	{
		int r = strlen(*it);
		if (r > max)
		{
			max = r;
			strcpy(d, *it);
		}
	}
	return d;
}

const char *vocale = "aeiouAEIOU";
ui MoreThan4Vowels(vector<const char*> t)
{
	ui nr = 0;
	ui nrtemp = 0;
	for (ui i = 0; i<ui(t.size()); i++)
	{
		nrtemp = 0;
		for (ui j = 0; j < ui(strlen(t[i]));j++)
			if (strchr(vocale, t.at(i)[j]))
				nrtemp++;
		if (nrtemp >= 4)
			nr++;
	}
	return nr;
}

deque<const char*> NoVowelAtBeginPos(vector<const char*> t)
{
	deque<const char*> dq;
	for (ui i = 0; i < ui(t.size()); i++)
	{
		if (!strchr(vocale, t[i][0]))
			dq.push_front(t[i]);
	}
	return dq;
}


class PQCompare //Vom suprascrie operatorul () pentru a face comparatia dorita de noi (>)
{
public:
	bool operator()(const char* &s1, const char* &s2) const {
		//char* tmpS1 = _strdup(s1); //aloca memorie pentru ceea ce vom pune 
		//char* tmpS2 = _strdup(s2);//echivalent cu char* tmpS1=new char[20]; strcpy(tmpS1,s1); ~cred...
		//_strlwr(tmpS1); //transform to lower case
		//_strlwr(tmpS2);
		//return strcmp(tmpS1, tmpS2) >= 0;
		return stricmp(s1, s2) > 0;
	}
};

priority_queue<const char*, vector<const char*>, PQCompare > SortAllStrings(vector<const char*> t)
{
	priority_queue<const char*, vector<const char*>, PQCompare > pq;
	for (ui i = 0; i < t.size(); i++)
	{
		pq.push(t[i]);
	}
	/* nu prea merge...
	for(ui i=0; i<t.size()-1; i++)
		for(ui j=i+1; j<t.size(); j++)
			if (stricmp(t[i],t[j])>0)
			{
				const char* temp = new char[30];
				temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
	
	for (ui i = 0; i < t.size(); i++)
	{
		pq.push(t.at(i));
		cout << t.at(i) << ' ';
	} */
	return pq;
}

bool DeleteMoreThanX(vector<const char*> &t, ui x)
{
	if (x == 0)
		return false;
	vector<const char*>::iterator bb=t.begin();
	while (bb < t.end())
		if (ui(strlen(*bb)) > x)
			bb=t.erase(bb);
		else
			bb++;
	return true;
	/* //sauu
	for (ui i = 0; i < t.size(); i++)
	{
		if (ui(strlen(t.at(i))) > x)
		{
			cout << strlen(t.at(i)) << ' ';
			vector<const char*>::iterator bb = t.begin()+i;
			t.erase(bb);
			i--;
		}
	}
	return true; */
}

vector<const char*> ReverseVector(vector<const char*> t)
{
	vector<const char*> z;
	stack<const char *, vector<const char*>> St;
	for (ui i = 0; i < t.size(); i++)
		St.push(t.at(i));
	while(!St.empty())
	{
		z.push_back(St.top());
		St.pop();
	}
	return z;
}

bool AfisareAllVect(vector<const char*> t)
{
	if (t.empty())
		return false;
	vector<const char*>::iterator ii;
	for (ii = t.begin(); ii < t.end(); ii++)
	{
		cout << *ii <<' ';
	}
	cout << "\n\n";
	return true;
}


int main()
{
	vector<const char*> t;
	char *zzz = new char[30];
	while (fgets(zzz, 31, pfile) != '\0')
	{
		char *temp = new char[30];
		strcpy(temp, zzz);
		if (temp[strlen(temp) - 1] == '\n')
			temp[strlen(temp) - 1] = '\0';
		t.push_back(temp);
	}
	fclose(pfile);
	cout << "Testare citire fisier:\n";
	AfisareAllVect(t);
	cout << "Sirul de lungime maxima este: ";
	cout << sirlungmax(t) << "\n\n";
	cout << "Sirurile care au mai mult de 4 vocale sunt: ";
	cout << MoreThan4Vowels(t) << "\n\n";
	deque<const char*> ddqq = NoVowelAtBeginPos(t);
	cout << "Testare deque:\n";
	for (ui i = 0; i < ui(ddqq.size()); i++)
		cout << ddqq.at(i) << ' ';
	cout << "\n\n";
	DeleteMoreThanX(t, 5);
	cout << "Testare stergere:\n";
	AfisareAllVect(t);
	cout << "Testare priority queue:\n";
	priority_queue<const char*, vector<const char*>, PQCompare > ppqq = SortAllStrings(t);
	while (!ppqq.empty())
	{
		cout << ppqq.top() << ' ';
		ppqq.pop();
	}
	cout << "\n\n";
	vector<const char*> revect = ReverseVector(t);
	cout << "Testare reverse vector:\n";
	AfisareAllVect(revect);

}


