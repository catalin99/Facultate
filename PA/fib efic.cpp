#include <iostream>
using namespace std;

long long int v[100];
long long int fib_eficient(int n)
{
    if(n==0)
    {
        if(v[0]==-1)
            v[0]=0;
        return v[0];
    }
    else if(n==1)
    {
        if(v[1]==-1)
            v[1]=1;
        return v[1];
    }
    else
    {
        if(v[n]==-1)
            v[n]=fib_eficient(n-1)+fib_eficient(n-2);
        return v[n];
    }

}
int main()
{
    for (int i=0; i<100; i++)
    {
        v[i]=-1;
    }
    int n;
    cin>>n;
    cout<<fib_eficient(n);
    return 0;
}
