#include <iostream>
#include <cstring>
using namespace std;

struct situatie
{
    int linii, coloane;
    char a[100][100];
    char next[20];
}var;

int main()
{
    int i, j, albi, albj;
    cin>>var.linii>>var.coloane;
    for(i=0; i<var.linii; i++)
        for(j=0; j<var.coloane; j++)
        {
            cin>>var.a[i][j];
            if(var.a[i][j]=='A')
            {
                albi=i;
                albj=j;
            }
        }
    cin.get();
    cin.get(var.next, 18);
    //cout<<albi<<" "<<albj<<endl;
    if(var.a[albi-1][albj]==var.a[albi+1][albj] && var.a[albi-1][albj]==var.a[albi][albj-1] && var.a[albi-1][albj]==var.a[albi][albj+1])
    {
        if(var.a[albi-1][albj]=='V')
            cout<<"jucatorul cu piese verzi a castigat";
        else
            cout<<"jucatorul cu piese albastre a castigat";
    }
    else
        cout<<"Jocul nu s-a terminat";
    return 0;
}
