#include <iostream>
using namespace std;

// Sa se determine daca un element apare de mai mult de n/2 ori in vector. complexitate o(n)
int ElemMajoritar(int n, int a[])
{
    int maj=0, k=0;
    for (int i=1; i<=n; i++)
    {
        if (k==0)
        {
            maj=a[i];
            k=1;
        }
        else if (a[i]==maj)
            k++;
        else
            k--;
    }
    int nr=0;
    for (int i=1; i<=n; i++)
        if (a[i]==maj)
            nr++;
    if (nr>n/2)
        return true;
    else
        return false;
}

int main()
{
    int n, v[1000];
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>v[i];
    cout<<ElemMajoritar(n, v);
    return 0;
}
