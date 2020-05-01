 #include <iostream>
    #include <fstream>
    #include <limits.h>
    #include <vector>
    using namespace std;
    ifstream fin("statisticiordine.in");
    ofstream fout("statisticiordine.out");

    unsigned v[4000001];
    long long  pivot(long long st,long long  dr)
{
    long long p,q,x;
    p=st;
    q=dr;
    x=v[p];
    while(p<q)
    {
        while(p<q&&v[q]>=x)
            q--;
        v[p]=v[q];
        while(p<q&&v[p]<=x)
            p++;
        v[q]=v[p];
    }
    v[p]=x;
    return p;
}

    long long quickselect(long long st,long long dr,long long k)
    {
        if(st<=dr)
        {
            int p=pivot(st,dr);
            if(p==k)return v[p];
            if(p>k)return quickselect(st,p-1,k);
            if(p<k)return quickselect(p+1,dr,k);

        }
    }
    int main()
    {
       long long n,k;
       fin>>n>>k;
       for(int i=1;i<=n;i++)
            fin>>v[i];
       fout<<quickselect(1,n,k);return 0;

    }
