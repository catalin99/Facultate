#include <iostream>
#include <cstring>

using namespace std;
typedef unsigned int ui;
void html(char s[240])
{
    //char s[50];
    //cin.get(s, 49);
    for(ui i=1; i<strlen(s)-1; i++)
    {
        //if(s[i]=='r')
            //cout<<"DA";
        if(s[i-1]=='<' && s[i+1]=='>' && (s[i]=='b' || s[i]=='u' || s[i]=='i' || s[i]=='B' || s[i]=='U' || s[i]=='I'))
        {
            strcpy(s+(i-1), s+(i+2));
            i-=2;
        }
        else if(s[i-1]=='<' && s[i]=='/' && s[i+2]=='>' && (s[i+1]=='b' || s[i+1]=='u' || s[i+1]=='i' || s[i+1]=='B' || s[i+1]=='U' || s[i+1]=='I'))
        {
            strcpy(s+(i-1), s+(i+3));
            i-=3;
        }
    }
    cout<<s;
}

int main()
{
    char s[250];
    cin.get(s,240);
    html(s);
    return 0;
}
