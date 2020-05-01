#include <iostream>
using namespace std;

unsigned int sumaFib(int index)
{
    int f3;
    int f1=0;
    int f2=1;
    int s=1;
    for(int i=2; i<=index;i++)
	{
	    f3=f1+f2;
        s+=f3;
        f1=f2;
        f2=f3;
	}
	return s;
}

int main()
{
    int n;
	cin>>n;
	cout<<sumaFib(n);
	return 0;
}
