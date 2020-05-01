#include <iostream> //n(n+1)(2n+1)/6
using namespace std;
int main()
{
    int n, x, a[100], i, s=0, found=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        s+=a[i];
        if(i>1 && !found)
            for(int j=i-1; j>=1; j--)
                if(a[i]==a[j])
                {
                    x=a[i];
                    break;
                }
    }
    cout<<x<<' ';
    cout<<(n*(n+1)/2)-(s-x);
    return 0;
}
