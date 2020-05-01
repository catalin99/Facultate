#include <iostream>
#include <cstring>
using namespace std;

struct coada
{
    int key;
    coada *next;
};

void push(coada *&cd, int x)
{
    coada *q=new coada;
    q->key=x;
    q->next='\0';
    if(!cd)
    {
        cd=q;
        return;
    }
    coada *parc=cd;
    while(parc->next)
        parc=parc->next;
    parc->next=q;
    return;
}

void pop(coada *&cd)
{
    if(!cd)
        return;
    coada *q=cd;
    cd=cd->next;
    delete q;
    return;
}

void front(coada *cd)
{
    if(!cd)
        return;
    cout<<cd->key<<'\n';
    return;
}

int main()
{
    char s[10];
    int numaroperatii;
    int valoare;
    int i;
    coada *cd='\0';
    cin>>numaroperatii;
    for(i=1; i<=numaroperatii; i++)
    {
        strcpy(s, "\0");
        cin>>s;
        if(!strcmp(s, "push"))
        {
            cin>>valoare;
            push(cd, valoare);
        }
        else if(!strcmp(s, "pop"))
            pop(cd);
        else
            front(cd);
    }
    return 0;
}
