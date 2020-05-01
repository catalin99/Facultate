#include <iostream>
#include <cstring>
using namespace std;

char sixteen(int nr)
{
    int c;
    if(nr>=0 && nr<=10)
        c=nr+'0';
    else
    {
        if(nr==10)
            c='A';
        if(nr==11)
            c='B';
        if(nr==12)
            c='C';
        if(nr==13)
            c='D';
        if(nr==14)
            c='E';
        if(nr==15)
            c='F';
    }
    return c;
}
bool convert(unsigned int numar, unsigned int toBase, char * result, unsigned int MaxSize)
{
    if (toBase<2 || toBase>16)
        return false;
    int i=0;
    int rest;
    while(numar)
    {
        rest=numar%toBase;
        result[i]=sixteen(rest);
        i++;
        result[i]='\0';
        numar=numar/toBase;
    }
    if(strlen(result)>MaxSize)
        return false;
    if(result=='\0')
        return false;
    int k=strlen(result)-1;
    int j=0;
    char temp;
    //cout<<result;
    while(j<=k)
    {
        swap(result[j], result[k]);
        j++;
        k--;
    }
    return true;
}
int main()
{
    unsigned int numar;
    unsigned int base;
    char d[200];
    cin>>numar;
    cin>>base;
    convert(numar, base, d, 50);
    cout<<d;
}
