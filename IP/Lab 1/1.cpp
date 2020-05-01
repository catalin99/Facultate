#include <iostream>
using namespace std;

int main()
{
    int n, s=0, i, x;
    cin>>n;
    for(i=1; i<n; i++)
    {
        cin>>x;
        s+=x;
    }
    cout<<(n*(n+1))/2-s;
    return 0;
}
