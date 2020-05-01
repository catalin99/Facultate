#include <iostream>
using namespace std;

int main()
{
    int x[100][100], n, s=0;
    cin>>n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>x[i][j];
            if(x[i][j]>0 && i>j)
                s+=x[i][j];
        }
    cout<<s;
    return 0;

}
