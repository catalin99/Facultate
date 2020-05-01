#include <iostream>
using namespace std;
int main()
{
    int n, x[10000], i, j;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>x[i];
    for(i=1; i<n; i++)
        if(x[i]<0)
        {
            for(j=i; j<n; j++)
                x[j]=x[j+1];
            n--;
            i--;
        }
    if(x[n]<0)
        n--;
    for(i=1; i<=n; i++)
        cout<<x[i]<<' ';
    return 0;


}
