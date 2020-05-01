#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
ifstream in("masini.in");
ofstream out("masini.out");

int main()
{
    int n, T;
    unordered_set<int> v;
    in>>n>>T;
    for(int i=1; i<=n; i++)
    {
        in>>x;
        v.push_back(x);
    }
    s=0;
    ct=0;
    for(auto i:v)
    {
        s+=v[i];
        if(s>T)
            break;
        ct++;
    }
    out<<ct;
    return 0;
}
