#include <iostream>
using namespace std;
int main()
{
    int i=1, j=1, k=1, z=0;
    for(;i<=10;i++)
        while(j<=10)
        {
            j++;
            do
            {
                k++;
                z++;
            } while (k<=10);
        }
    cout<<z;
}
