#include <iostream>
#include <cstring>
using namespace std;

struct stiva
{
    int key;
    stiva *next;
};

void push(stiva *&st, int x)
{
    stiva *q=new stiva;
    q->key=x;
    if(!st)
    {
        q->next='\0';
        st=q;
    }
    else
    {
        q->next=st;
        st=q;
    }
    return;
}

void pop(stiva *&st)
{
    if(!st)
        return;
    stiva *q=st;
    st=st->next;
    delete q;
    return;
}

void top(stiva *st)
{
    if(!st)
        return;
    cout<<st->key<<'\n';
}

int main()
{
    char s[10];
    int numaroperatii;
    int valoare;
    int i;
    stiva *st=NULL;
    cin>>numaroperatii;
    for(i=1; i<=numaroperatii; i++)
    {
        strcpy(s, "\0");
        cin>>s;
        if(!strcmp(s, "push"))
        {
            cin>>valoare;
            push(st, valoare);
        }
        else if(!strcmp(s, "pop"))
            pop(st);
        else
            top(st);
    }
    return 0;
}
