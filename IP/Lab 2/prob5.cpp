#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float x, minim, maxim, first, second;
    cin>>n;
    cin>>x;
    minim=x; maxim=x;
    for(int i=2; i<=n; i++)
    {
        cin>>x;
        if(x>maxim)
            maxim=x;
        else if (x<minim)
            minim=x;
    }
    first=maxim-minim;
//    second=minim-maxim;
//    if(first>=second)
//        cout<<first;
//    else
        cout<<|maxim-minim|;
    return 0;
}
