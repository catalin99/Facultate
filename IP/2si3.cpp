#include <iostream>
#include <fstream>
using namespace std;

int n;
int x[100];
int nr2[100];
int nr3[100];
int where[100];

int computeTheLongestSubstring(int n)
{
    int nr=0;
    for(int i=1;i<=n;i++)
    {
        if(nr3[i]-nr3[where[nr2[i]-nr-1]]==nr+1)
            nr++;
    }
    return nr*2;
}

int main()
{
    ifstream t1("2si3.in");
    t1>>n;
    for(int i=1;i<=n;i++)
    {
        t1>>x[i];
        nr2[i]=nr2[i-1];
        nr3[i]=nr3[i-1];
        if( x[i]==2)
        {
            nr2[i]++;
            where[nr2[i]]=i;
        }
        else nr3[i]++;
    }
    for(int i=1;i<=n;i++) cout<<nr2[i]<<' '; cout<<'\n';
    for(int i=1;i<=n;i++) cout<<nr3[i]<<' '; cout<<'\n';
    for(int i=1;i<=n;i++) cout<<where[i]<<' '; cout<<'\n';
    cout<<computeTheLongestSubstring(n);
    return 0;
}
