#include <iostream>
using namespace std;

int main()
{
    int x[10000], n, i, j, cop;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>x[i];
    for(i=1; i<=n; i++)
        if(x[i]<0)
        {
            j=i;
            while(x[j-1]>0)
            {
                cop=x[j];
                x[j]=x[j-1];
                x[j-1]=cop;
                j--;
            }
        }
    for(i=1; i<=n; i++)
        cout<<x[i]<<' ';
    return 0;
}
