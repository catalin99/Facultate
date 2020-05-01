#include <iostream>
using namespace std;

int main()
{
    int n, prec=1, i=1, s=0;
    cin>>n;
    while(i<=n)
    {
        prec=prec*i;
        s=s+prec;
        i++;
    }
    cout<<s;
    return 0;
}
