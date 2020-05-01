#include <iostream>
using namespace std;

bool bisect(int n)
{
    if((n%4==0) &&(n%100!=0))
        return true;
    if(n%400==0)
        return true;
    return false;
}
int main()
{
    struct data
    {
        int zi, luna, an;
    }date;
    cin>>date.zi>>date.luna>>date.an;
    if(date.zi<28)
        date.zi++;
    else if(date.zi==31 && date.luna==12)
    {
        date.zi=1;
        date.luna=1;
        date.an++;
    }
    else if((date.zi==28) && (date.luna==2) && (bisect(date.an)))
        date.zi++;
    else if((date.zi==28) && (date.luna==2) && (!bisect(date.an)))
    {
        date.zi=1;
        date.luna++;
    }
    else if((date.zi==31 && (date.luna==1 || date.luna==3 || date.luna==5 || date.luna==7 || date.luna==8 || date.luna==10)) || (date.zi==30 && (date.luna==4 || date.luna==6 || date.luna==9 || date.luna==11)))
    {
        date.zi=1;
        date.luna++;
    }
    else
        date.zi++;
    cout<<date.zi<<" "<<date.luna<<" "<<date.an;
    return 0;
}




