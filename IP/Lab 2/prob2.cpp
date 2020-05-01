#include <iostream>
using namespace std;
int main()
{
    int n, pozf, lmax=1, nr=1, pozm=1, i;
    float x, y;
    cin>>n;
    cin>>y;
    for(i=2; i<=n; i++)
    {
        cin>>x;
        if(x==y)
        {
            nr++;
            if(nr>lmax)
            {
                lmax=nr;
                pozf=pozm;
            }
        }
        else
        {
             nr=1;
             pozm=i;
             y=x;
        }
    }
    cout<<"lungimea maxima "<<lmax<<endl;
    cout<<"pozitia primului element al secventei "<<pozf;
    return 0;
}
