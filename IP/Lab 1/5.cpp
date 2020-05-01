#include <iostream>
using namespace std;

int main()
{
    int n, x=0, cop;
    cin>>n;
    cop=n;
    while(n)
    {
        x=x*10+n%10;
        n/=10;
    }
    if(x==cop)
        cout<<"Da";
    else
        cout<<"Nu";
    return 0;
}
