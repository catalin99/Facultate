#include <iostream>
using namespace std;
int x[100], rez;
int buturuga(int i, int cost[])
{
    if(i==0)
        return x[i]=0;
    if(x[i]!=-1)
        return x[i];
    else
    {
        rez=cost[1]+buturuga(i-1,cost);
        for(int j=2; j<=i; j++)
            if(rez<cost[j]+buturuga(i-j,cost))
                rez=cost[j]+buturuga(i-j,cost);
        return x[i]=rez;
    }
}

int main()
{
    int n;
    int costt[100];
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>costt[i];
    for(int i=0; i<100; i++)
        x[i]=-1;
    cout<<buturuga(n,costt);

}
