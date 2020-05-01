#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include <cmath>
using namespace std;

ifstream cryptedlist("convertlist.rzz");
ifstream in("fis.in");
ofstream out("fis.out");

char null[2]="\0";
char randvar[12]="@&nM7p2V+)";
long long seed=rand()%15;
long long trand;

void randomhelper(long long &seed, long long &trand)
{
    long long d=sqrt(seed);
    seed+=(seed+(d+trand));
    if(seed%2==0)
        trand+=2;
    else
        trand+=3;
}

short random()
{
    short x;
    randomhelper(seed, trand);
    srand(seed);
    x=rand()%100;
    return x;
}

char selectvar()
{
    int x;
    x=random(); //@&nM7p2V+)
    char var='\0';
    if(x<10)
        var='@';
    else if (x>=10 && x<20)
        var='&';
    else if (x>=20 && x<30)
        var='n';
    else if (x>=30 && x<40)
        var='M';
    else if (x>=40 && x<50)
        var='7';
    else if (x>=50 && x<60)
        var='p';
    else if (x>=60 && x<70)
        var='2';
    else if (x>=70 && x<80)
        var='V';
    else if (x>=80 && x<90)
        var='+';
    else
        var=')';
    return var;
}

void howmuch(short &number)
{
    int x;
    x=random();
    if(x<15)
        number=0;
    else
        number=1;
}

void encrypt(char letter, char ecl[])
{
    strcpy(ecl, null);
    cryptedlist.seekg(0);
    while(!cryptedlist.eof())
    {
        cryptedlist.getline(ecl, 11);
        if(ecl[0]==letter)
        {
            strcpy(ecl, ecl+2);
            for(int i=0; i<strlen(ecl); i++)
            {
                char b;
                char copie[50];
                srand(time(NULL));
                randomhelper(seed, trand);
                srand(seed);
                short number;
                howmuch(number);
                if(number)
                {
                    randomhelper(seed, trand);
                    srand(seed);
                    b=selectvar();
                    strcpy(copie, ecl+i);
                    ecl[i]=b;
                    strcpy(ecl+(i+1), copie);
                    i++;
                }
            }
            return;
        }
    }
    strcpy(ecl, "err");
    return;
}

void decrypt(char encrypts[], char &letter)
{
    char s[50];
    cryptedlist.seekg(0);
    while(!cryptedlist.eof())
    {
        cryptedlist.getline(s, 49);
        if(strstr(s, encrypts))
        {
            if(s[2]=='z' && s[0]=='z')
            {   letter=s[1];
                //out<<' ';
                return;
            }
            else
            letter=s[0];
            return;
        }
    }
    letter='\0';
    return;
}

void encryptstring()
{
    char s[50];
    char alpha[10000];
    char let;
    while(!in.eof())
    {
        in.getline(alpha, 9999);
        {
            for(int i=0; i<strlen(alpha); i++)
            {
                let=alpha[i];
                strcpy(s, null);
                if(let==' ')
                    strcpy(s,"cU%;1");
                else
                    encrypt(let, s);
                let='\0';
                out<<s;
            }
        }
    }
}

void decryptstring()
{
    char let;
    char word[60];
    char phrase[10000];
    while(!in.eof())
    {
        in.getline(phrase, 9999);
        if(!phrase)
            break;
        strcpy(word, null);
        int z=0;
        for(int i=0; i<strlen(phrase); i++)
        {
            if(!strchr(randvar,phrase[i]))
            {
                if(z>=5)
                {
                    decrypt(word, let);
                    out<<let;
                    strcpy(word, null);
                    z=0;
                    word[z++]=phrase[i];
                    word[z]='\0';
                }
                else
                {
                    word[z++]=phrase[i];
                    word[z]='\0';
                }
            }
        }
        decrypt(word, let);
        out<<let;
    }
}

int main()
{
    srand(time(NULL));
    trand=rand()%100;
    short nr=0, input=0;
    cout<<"Alege metoda de input!"<<'\n';
    cout<<"Scrieti 1 pentru a citi datele de la tastatura (consola)"<<'\n';
    cout<<"Pentru orice alta valoare introdusa datele se vor citi din fisierul fis.in"<<'\n';
    cin>>input;
    if(input==1)
    {
        ofstream keyin("fis.in");
        cin.get();
        char sinput[10000];
        cout<<"Introduceti textul pe care vreti sa il criptati/decriptati"<<'\n';
        cin.getline(sinput, 9999);
        keyin<<sinput;
        keyin.close();
    }
    else
        cout<<"Textul pentru criptat/decriptat trebuie sa se afle in fis.in"<<'\n';

    if(!in.is_open()&&input==1)
    {
        cout<<"Error"<<'\n';
        out<<"Error opening file";
    }

    cout<<"Alege metoda de criptare!"<<'\n';
    cout<<"Scrieti 1 pentru a cripta"<<'\n';
    cout<<"Scrieti 2 pentru a decripta"<<'\n';
    cout<<"Textul final se va afla in fis.out"<<'\n';
    cin>>nr;
    if(nr==1)
        encryptstring();
    else if(nr==2)
        decryptstring();
    else
        cout<<"Ati introdus o valoare gresita";
    return 0;
}
