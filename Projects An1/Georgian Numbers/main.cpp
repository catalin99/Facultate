#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream fin("proiect.in");
ofstream fout("proiect.out");
ifstream f("numere.in");

struct numar{
                int nr;
                char s[50];

};
void init(numar georgian[101],int &nrelem)
{
    f>>nrelem;
    for(int i=0;i<=nrelem-1;i++)
    {
        f>>georgian[i].nr;
        f.getline(georgian[i].s,50);
    }

}
int primacifra(int n)
{
    while(n>9)
    {
        n=n/10;
    }
    return n;
}
int a2acifra(int n)
{
    while(n>99)
    {
        n=n/10;
    }
    return n%10;
}
int a3acifra(int n)
{
    while(n>999)
        n=n/10;
    return n%10;
}
int a4acifra(int n)
{
    while(n>9999)
        n=n/10;
    return n%10;
}
int numar_cifre(int n)
{
    return int(log10(n))+1;
}
void elimprimacifra(int &n)
{
    int fr[10];
    int k=0;
    while(n>0)
    {
        fr[++k]=n%10;
        n=n/10;
    }
    for(int i=k-1;i>=1;--i)
    {
        n=n*10+fr[i];

    }

}

void zeci(int n,numar georgian[])
{
    if(n<=20){fout<<georgian[n].s;
                cout<<georgian[n].s;}
    else if(n>20&&n<=39)
    {
        int lungime=strlen(georgian[20].s)-1;
        for(int i=0;i<lungime;i++)
                {fout<<georgian[20].s[i];
                 cout<<georgian[20].s[i];}
        n=n-20;
        fout<<"da"<<georgian[n].s;
        cout<<"da"<<georgian[n].s;
    }
    else if(n==40){fout<<"ormotsi";
                    cout<<"ormotsi";}
        else if(n>40&&n<60)
        {
            fout<<"orm";
            cout<<"orm";
            int lungime=strlen(georgian[20].s)-1;
        for(int i=0;i<lungime;i++)
                {fout<<georgian[20].s[i];
                 cout<<georgian[20].s[i];}
        n=n-40;
        fout<<"da"<<georgian[n].s;
        cout<<"da"<<georgian[n].s;

        }
        else if(n==60){fout<<"samotsi";
                       cout<<"samotsi";}
            else if(n>60&&n<80)
            {
                cout<<"sam";
                fout<<"sam";
                int lungime=strlen(georgian[20].s)-1;
            for(int i=0;i<lungime;i++)
                {   cout<<georgian[20].s[i];
                    fout<<georgian[20].s[i];}
            n=n-60;
            fout<<"da"<<georgian[n].s;
            cout<<"da"<<georgian[n].s;

            }
        else if(n==80){ cout<<"otkhmotsi";
                        fout<<"otkhmotsi";}
            else if(n>80&&n<=99)
            {
                cout<<"otkhm";
                fout<<"otkhm";
                int lungime=strlen(georgian[20].s)-1;
            for(int i=0;i<lungime;i++)
                {   cout<<georgian[20].s[i];
                    fout<<georgian[20].s[i];}
            n=n-80;
            cout<<"da"<<georgian[n].s;
            fout<<"da"<<georgian[n].s;

            }


}

void sute(int n,numar georgian[101])
{

    int x=primacifra(n);
    int y=a2acifra(n);
    if(n==100){ cout<<georgian[21].s;
               fout<<georgian[21].s;}
    else if(n%100==0&&n!=100&&n!=900){
                    int lungime=strlen(georgian[x].s)-1;
                    for(int i=0;i<=lungime-1;i++)
                            {fout<<georgian[x].s[i];
                             cout<<georgian[x].s[i];}
                    cout<<georgian[21].s;
                    fout<<georgian[21].s;

                }
    else if(n==900){cout<<georgian[9].s;
                    fout<<georgian[9].s;
                cout<<georgian[21].s;
                fout<<georgian[21].s;}
            else if(x!=9){

                    if(x==1){fout<<georgian[21].s;cout<<georgian[21].s;}
                    else {

                                int lungime=strlen(georgian[x].s)-1;
                                for(int i=0;i<=lungime-1;i++)
                                    {fout<<georgian[x].s[i];
                                     cout<<georgian[x].s[i];}
                               if(x<=y)
                               {
                                   int lungime2=strlen(georgian[21].s)-1;
                                   for(int i=0;i<=lungime2;i++)
                                        {fout<<georgian[21].s[i];
                                         cout<<georgian[21].s[i];}

                               }
                               else{
                                        int lungime2=strlen(georgian[21].s)-1;
                                   for(int i=0;i<=lungime2-1;i++)
                                        {fout<<georgian[21].s[i];
                                         cout<<georgian[21].s[i];}

                                        }

                        }
                    cout<<" ";
                    fout<<" ";

                    elimprimacifra(n);
                    int nr=numar_cifre(n);
                    if(nr<=2)zeci(n,georgian);
                }
                else
                {
                    cout<<georgian[x].s;
                    fout<<georgian[x].s;
                    cout<<georgian[21].s;
                    fout<<georgian[21].s;
                    cout<<" ";
                    fout<<" ";
                    elimprimacifra(n);
                     int nr=numar_cifre(n);
                    if(nr<=2)zeci(n,georgian);
                }

}
void mii(int n, numar georgian[])
{
    int x=primacifra(n);
    int y=a2acifra(n);
    if(n==1000){ cout<<georgian[22].s;
                fout<<georgian[22].s;}
    else if(x==1){
                    cout<<georgian[22].s;
                    fout<<georgian[22].s;
                    cout<<" ";
                    fout<<" ";
                    elimprimacifra(n);
                    int nr=numar_cifre(n);
                    if(nr==3)sute(n,georgian);
                    else if(nr<=2)zeci(n,georgian);
                }
    else if(n%1000==0)
    {
        cout<<georgian[x].s<<" ";
        fout<<georgian[x].s<<" ";
        cout<<georgian[22].s<<" ";
        fout<<georgian[22].s<<" ";
    }
    else
    {
        cout<<georgian[x].s<<" ";
        fout<<georgian[x].s<<" ";
        if(x>y)
        {
            int lungime=strlen(georgian[22].s)-1;
            for(int i=0;i<=lungime-1;i++)
                {fout<<georgian[22].s[i];
                 cout<<georgian[22].s[i];}
        }
        else {  cout<<georgian[22].s;
                fout<<georgian[22].s;}
        cout<<" ";
        fout<<" ";
        elimprimacifra(n);
        int nr=numar_cifre(n);
        if(nr==3)sute(n,georgian);
        else if(nr<=2)zeci(n,georgian);

    }
}
void zeci_mii(int n,numar georgian[])
{
    int x=primacifra(n);
    int y=a2acifra(n);
    int t=a3acifra(n);
    int z=x*10+y;
    elimprimacifra(n);
    elimprimacifra(n);
    zeci(z,georgian);
    cout<<" ";
    fout<<" ";
    if(t<y)
    {

        int lungime=strlen(georgian[22].s)-1;
        cout<<" ";
        fout<<" ";
        for(int i=0;i<=lungime-1;i++)
            {fout<<georgian[22].s[i];
              cout<<georgian[22].s[i];}
    }
    else {  cout<<georgian[22].s;
            fout<<georgian[22].s;}
    cout<<" ";
    fout<<" ";
    int nr=numar_cifre(n);
    if(nr==3)sute(n,georgian);
    else if(nr==2||nr==1)zeci(n,georgian);

}
void sute_mii(int n,numar georgian[])
{
    cout<<'\t';
    int x=primacifra(n);
    int y=a2acifra(n);
    int z=a3acifra(n);
    int t=a4acifra(n);
    int rasp=x*100+y*10+z;
    sute(rasp,georgian);
    cout<<" ";
    fout<<" ";
    if(t<z){
                int lungime=strlen(georgian[22].s)-1;
                for(int i=0;i<lungime;i++)
                    {fout<<georgian[22].s[i];
                     cout<<georgian[22].s[i];}
            }
    else {  cout<<georgian[22].s;
            fout<<georgian[22].s;}
    cout<<" ";
    fout<<" ";
    elimprimacifra(n);
    elimprimacifra(n);
    elimprimacifra(n);
    int nr=numar_cifre(n);
    if(nr==3)sute(n,georgian);
    else if(nr==2||nr==1)zeci(n,georgian);

}
void baza10_georgiana()
{
    cout<<endl<<endl<<'\t'<<'\t'<<"BAZA10->Limba georgiana(caractere latine)";
    cout<<endl<<'\t'<<"Pentru optiunea dumneavoastra, programul va afisa numarul introdus in fiesierul de iesire"<<endl<<'\t'<<"<proiect.out>,";
    cout<<"dar si imediat pe ecran, cu caractere latine, in limba georgiana.";
    cout<<endl<<'\t'<<"Reguli:"<<endl<<'\t'<<"1.Numerele introduse vor fi naturale si mai mici decat 999999";
    cout<<endl<<'\t'<<"2.Va rog, respectati toate instructiunile oferite pe parcurs:" ;
}
void rezolva(int n,numar georgian[])
{

    cout<<endl<<endl<<'\t'<<"Introduceti primul numar: "<<endl;
    cout<<endl<<'\t';

    char raspuns[21];
    int i=1;
    int ok;
    do{
            cout<<'\t';

        if(i==1)cin>>n;
        else {cout<<endl<<'\t'<<"Introduceti noul numar: ";
                cin>>n;}
        i++;

        ok=0;

        int nr=numar_cifre(n);
        if(nr<=5)fout<<n<<"=";
        int k=0;
    switch(nr)
    {
        case 1:{zeci(n,georgian);fout<<endl;
                cout<<endl<<'\t'<<"Numarul introdus se afla in fisierul de intrare de mai sus. Doriti sa introduceti si alt numar ?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0&&k<5)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.getline(raspuns,21);
                    k++;


                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}

                break;





        }






        case 2:{zeci(n,georgian);
                fout<<endl;
                cout<<endl<<'\t'<<"Numarul introdus se afla in fisierul de intrare de mai sus. Doriti sa introduceti si alt numar ?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0&&k<5)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.getline(raspuns,21);
                    k++;



                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}
                break;}
        case 3:{sute(n,georgian);
                fout<<endl;
                cout<<endl<<'\t'<<"Numarul introdus se afla in fisierul de intrare de mai sus. Doriti sa introduceti si alt numar ?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0&&k<5)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.getline(raspuns,21);
                    k++;



                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}
                break;}
        case 4:{mii(n,georgian);
                fout<<endl;
                cout<<endl<<'\t'<<"Numarul introdus se afla in fisierul de intrare de mai sus. Doriti sa introduceti si alt numar ?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0&&k<5)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.getline(raspuns,21);
                    k++;



                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}
                break;}
        case 5:{zeci_mii(n,georgian);
        fout<<endl;
                cout<<endl<<'\t'<<"Numarul introdus se afla in fisierul de intrare de mai sus. Doriti sa introduceti si alt numar ?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0&&k<5)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.getline(raspuns,21);
                    k++;



                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}
                break;}
        case 6:{
                 sute_mii(n,georgian);
        fout<<endl;
                cout<<endl<<'\t'<<"Numarul introdus se afla in fisierul de intrare de mai sus. Doriti sa introduceti si alt numar ?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0&&k<5)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.getline(raspuns,21);
                    k++;



                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}
                break;
              }
        default :
            {
                cout<<endl<<'\t'<<"Imi pare rau, dar acest numar nu respecta parametrii impusi";
                cout<<"Doriti sa incercati alt numar?";
                cout<<endl<<'\t'<<"Variantele de raspuns pot fi doar da sau nu";cout<<endl;
                cin.get();
                cout<<'\t';
                cin.getline(raspuns,21);

                while(strcmp(raspuns,"da")!=0&&strcmp(raspuns,"nu")!=0)
                {
                    cout<<endl<<'\t'<<"Imi pare rau, acest raspuns nu este un raspuns valid!";
                    cout<<endl<<'\t'<<'\t'<<"Introduceti din nou acest raspuns:";
                    cout<<endl;
                    cout<<'\t';
                    cin.get();
                    cin.getline(raspuns,21);



                }
                if(strcmp(raspuns,"da")==0)ok=1;
                if(k==5){cout<<endl<<'\t'<<"Imi pare rau, dar numarul introdus de dumneavostra nu este valid sau raspunsul a depasit numarul de incercari!!";
                         cout<<endl<<'\t'<<"Acest program va fi oprit.";
                         ok=0;}
                break;
            }

    }
}while(ok==1);
cout<<endl<<endl;
    }







///incepe pe litere aici:::
#include <iostream>
#include <cstring>
using namespace std;
int unitati(char intrebare[])///merge
{
    int x=0;
    if(strcmp(intrebare,"erti")==0){x=x*10+1;return x;}
    if(strcmp(intrebare,"ori")==0||strcmp(intrebare,"or")==0){x=x*10+2;return x;}
    if(strcmp(intrebare,"sami")==0||strcmp(intrebare,"sam")==0||strcmp(intrebare,"m")==0){x=x*10+3;return x;}
    if(strcmp(intrebare,"otkhi")==0||strcmp(intrebare,"otkh")==0){x=x*10+4;return x;}
    if(strcmp(intrebare,"khuti")==0||strcmp(intrebare,"khut")==0){x=x*10+5;return x;}
    if(strcmp(intrebare,"ekvsi")==0||strcmp(intrebare,"ekvs")==0||strcmp(intrebare,"ekv")==0){x=x*10+6;return x;}
    if(strcmp(intrebare,"svidi")==0||strcmp(intrebare,"svid")==0||strcmp(intrebare,"svidi")==0){x=x*10+7;return x;}
    if(strcmp(intrebare,"rva")==0||strcmp(intrebare,"rv")==0){x=x*10+8;return x;}
    if(strcmp(intrebare,"tskhra")==0||strcmp(intrebare,"t")==0){x=x*10+9;return x;}
    return x;

}
int lowerthan20(char intrebare[])
{
    int x=0;
    if(strcmp(intrebare,"ati")==0){x=10;return x;}
    if(strcmp(intrebare,"tertmet'i")==0){x=11;return x;}
    if(strcmp(intrebare,"tormet'i")==0){x=12;return x;}

    if(strcmp(intrebare,"tsamet'i")==0){x=13;return x;}
    if(strcmp(intrebare,"totkhmet'i")==0){x=14;return x;}
    if(strcmp(intrebare,"tkhutmet'i")==0){x=15;return x;}
    if(strcmp(intrebare,"tekvsmet'i")==0){x=16;return x;}
    if(strcmp(intrebare,"svidmet'i")==0){x=17;return x;}
    if(strcmp(intrebare,"tvramet'i")==0){x=18;return x;}
    if(strcmp(intrebare,"tskhramet'i")==0){x=19;return x;}
    return x;
}
int zeci(char intrebare[])
{

    int x=0;
    if(strcmp(intrebare,"ati")==0){x=10;return x;}
    if(strcmp(intrebare,"tertmet'i")==0){x=11;return x;}
    if(strcmp(intrebare,"tormet'i")==0){x=12;return x;}

    if(strcmp(intrebare,"tsamet'i")==0){x=13;return x;}
    if(strcmp(intrebare,"totkhmet'i")==0){x=14;return x;}
    if(strcmp(intrebare,"tkhutmet'i")==0){x=15;return x;}
    if(strcmp(intrebare,"tekvsmet'i")==0){x=16;return x;}
    if(strcmp(intrebare,"svidmet'i")==0){x=17;return x;}
    if(strcmp(intrebare,"tvramet'i")==0){x=18;return x;}
    if(strcmp(intrebare,"tskhramet'i")==0){x=19;return x;}
    if(strcmp(intrebare,"otsi")==0){x=20;return x;}
    if(strcmp(intrebare,"ormotsi")==0){x=40;return x;}
    if(strcmp(intrebare,"samotsi")==0){x=60;return x;}
    if(strcmp(intrebare,"otkhmotsi")==0){x=80;return x;}
    if(strstr(intrebare,"samo")!=NULL)
    {

        x=x+60;
        char d[23];
        char langa20[25];int k=0;
        strncpy(d,intrebare,8);
        d[8]=NULL;

        int n=strlen(intrebare)-1;
        for(int i=0;i<=n;i++)
            if(i>=8)langa20[k++]=intrebare[i];
        langa20[k]=NULL;
        int y=unitati(langa20);
        if(y==0)y=lowerthan20(langa20);
        x=x+y;

    }
    else if(strstr(intrebare,"ormots")!=NULL)
    {


        x=x+40;
        char d[23];
        char langa20[25];int k=0;
        strncpy(d,intrebare,8);
        d[8]=NULL;

        int n=strlen(intrebare)-1;
        for(int i=0;i<=n;i++)
            if(i>=8)langa20[k++]=intrebare[i];
        langa20[k]=NULL;
        int y=unitati(langa20);
        if(y==0)y=lowerthan20(langa20);
        x=x+y;
    }


   else  if(strstr(intrebare, "ots")!=NULL&&strstr(intrebare,"otkh")==NULL&&strstr(intrebare,"ormots")==NULL&&strcmp(intrebare,"otkhi")!=0)
    {

        x=x+20;
        char d[23];
        char langa20[25];
        int k=0;
        strncpy(d,intrebare,5);
        d[5]='\0';

        int n=strlen(intrebare)-1;
        for(int i=0;i<=n;i++)
            if(i>=5)langa20[k++]=intrebare[i];
        langa20[k]=NULL;

        int y=unitati(langa20);
        if(y==0)y=lowerthan20(langa20);
        x=x+y;

    }
    else if(strstr(intrebare,"otkh")!=NULL&&strcmp(intrebare,"otkhi")!=0)
    {


        x=x+80;
        char d[23];
        char langa20[25];int k=0;
        strncpy(d,intrebare,10);
        d[8]=NULL;

        int n=strlen(intrebare)-1;
        for(int i=0;i<=n;i++)
            if(i>=10)langa20[k++]=intrebare[i];
        langa20[k]=NULL;
        int y=unitati(langa20);
        if(y==0)y=lowerthan20(langa20);
        x=x+y;

    }


return x;




}
int sute(char intrebare[])///merge
{

    if(strstr(intrebare,"asi")==NULL&&strstr(intrebare,"as")==NULL)return 0;
    char copie[100];
    char copie2[100];
    strcpy(copie,intrebare);
    strcpy(copie2,intrebare);
    char *p=strtok(copie," ");

    int y;
    if(strcmp(p,"asi")==0||strcmp(p,"as")==0)y=100;
    else if(strcmp(p,"orasi")==0||strcmp(p,"oras")==0)y=200;
    else if(strcmp(p,"samasi")==0||strcmp(p,"samas")==0)y=300;
    else if(strcmp(p,"otkhasi")==0||strcmp(p,"otkhas")==0)y=400;
    else if(strcmp(p,"khutasi")==0||strcmp(p,"khutas")==0)y=500;
    else if(strcmp(p,"ekvsasi")==0||strcmp(p,"ekvsas")==0)y=600;
    else if(strcmp(p,"svidasi")==0||strcmp(p,"svidas")==0)y=700;
    else if(strcmp(p,"rvaasi")==0||strcmp(p,"rvaas")==0||strcmp(p,"rvasi")==0||strcmp(p,"rvas")==0)y=800;
    else if(strcmp(p,"tskhraasi")==0||strcmp(p,"tskhraas")==0)y=900;
    return y;


}
void elimina_pana_asi(char sir[])
{
    int n=strlen(sir)-1;

    char cuv[30];
    int k=0;
    int ok=0;
    for(int i=0;i<=n&&ok==0;i++)
    {
        if(sir[i]!=' '&&strlen(sir)>0){strcpy(sir+i,sir+i+1);i--;
                       }
        else if(sir[i]==' '||strlen(sir)==0){ok=1;

                             strcpy(sir+i,sir+i+1);i--;}
    }
}
int mii(char intrebare[])
{
    int y=0;
    if(strstr(intrebare,"atasi")==NULL&&strstr(intrebare,"atas")==NULL)return 0;///mai mic de o mie
    char copie[245];
    char a[20][245];
    int k=0;
    strcpy(copie,intrebare);
    char *p=strtok(intrebare," ");

    if(strcmp(p,"atas")==0||strcmp(p,"atasi")==0){y=1000;return y;}
    int ok=0;
    while(p&&ok==0)
    {
        if(strcmp(p,"atasi")!=0&&strcmp(p,"atas")!=0)
        {strcpy(a[k++],p);
        p=strtok(NULL," ");}
        else {
                ok=1;
        }
    }
    char f[245];
    strcpy(f,a[0]);
    for(int i=1;i<k;i++)
        {
            strcat(f," ");
            strcat(f,a[i]);
        }

    int z=0;
     z=sute(f);

    if(z==0){
                z=zeci(f);
                if(z==0) z=unitati(f);
                else z=z+unitati(f);

            }
    else{

         elimina_pana_asi(f);

         int p=zeci(f);

         if(p==0)z=z+unitati(f);
         else z=z+p;

        }
    y=z*1000;
    strcpy(intrebare,copie);
    return y;
}
void ce_e_dupa_atasi(char intrebare[])
{
    char cuv[25];
    int k=0;
    int j=0;
    int n=strlen(intrebare)-1;
    int ok=0;
    for(int i=0;i<=n&&ok==0;i++)
    {
        if(intrebare[i]!=' '){cuv[k++]=intrebare[i];j++;}
        else{
             cuv[k++]=intrebare[i];
             cuv[k]='\0';

            if(strcmp(cuv,"atas ")==0||strcmp(cuv,"atasi ")==0){ok=1;j=i;}
            else k=0;
            }
    }
   char dupa[256];
   strcpy(dupa,intrebare+j+1);
   strcpy(intrebare,dupa);




}
void rezolvabaza10()
{
    cout<<endl<<'\t'<<"Introduceti sirul pe care doriti sa il convertiti:"<<endl<<'\t';
    char intrebare[256];
    cin.getline(intrebare,256);

    int x=mii(intrebare);

    if(x==0){
                x=sute(intrebare);
                if(x==0) {
                          x=zeci(intrebare);
                            if(x==0)x=unitati(intrebare);

                        }
                else{
                        elimina_pana_asi(intrebare);
                        int y=zeci(intrebare);
                        if(y==0)y=unitati(intrebare);
                        x=x+y;
                    }
                    }
    else{

         ce_e_dupa_atasi(intrebare);

         int y=sute(intrebare);
         if(y==0){
                    y=zeci(intrebare);
                    if(y==0) y=unitati(intrebare);

                }
         else{
                    elimina_pana_asi(intrebare);
                    int z=zeci(intrebare);
                    if(z==0)z=unitati(intrebare);
                    y=y+z;
            }
        x=x+y;
        }
    if(x!=0)
            cout<<endl<<'\t'<<x;
    else {
                if(x==0&&strcmp(intrebare,"nuli")!=0)cout<<endl<<'\t'<<"Exista o eroare in scrierea numarului;";
            }


}

void georgiana_baza10()
{
    cout<<endl<<endl<<'\t'<<'\t'<<"Limba georgiana->BAZA10";
    cout<<endl<<'\t'<<"Acest subprogram va transforma orice numar in limba georgiana, scris cu caractere latine, intr-un numar in baza10";
    cout<<endl<<'\t'<<'\t'<<"REGULI :"<<endl<<'\t'<<"1.Pentru ca programul sa functioneze corect, va rugam sa sa introduceti numere in limba georgiana"<<endl;
    cout<<'\t'<<" fara ca acestea sa contina greseli de scriere.Nerespectarea acestei reguli poate duce la afisarea unui rezultat gresit";
    cout<<endl<<'\t'<<"2.Numerele sunt NATURALE si mai mici sau egale decat 999999";

}

void meniu()
{
    numar georgian[101];
    int nrelem,n;

    init(georgian,nrelem);

    georgiana_baza10();
    cout<<endl;
    baza10_georgiana();
    cout<<endl<<endl<<'\t'<<"Programul dispune de urmatoarele optiuni:";
    cout<<endl<<'\t'<<"1.Convertirea unui sir de caractere in limba georgiana, la un numar in baza10";
    cout<<endl<<'\t'<<"2.Convertirea unui numar in baza 10 la un sir de caractere care reprezinta scrierea lui in limba georgiana";
    char raspuns;
    cout<<endl<<'\t'<<"Alegeti va rog, una din optiunile de mai sus, alegerea oricarei alte optiuni in afara celor prezente mai sus, va conduce la inchiderea programului";
    cout<<endl<<'\t';
    cin>>raspuns;
    cin.get();
    while(raspuns=='1'||raspuns=='2')
    {
        if(raspuns=='1'){
                        rezolvabaza10();
                         cout<<endl<<'\t'<<"Doriti sa testati din nou una din cele 2 optiuni? Va reamintim ca pentru a iesi din program apasati orice tasta in afara de 1 sau 2";
                         cout<<endl<<'\t';cin>>raspuns;cin.get();}
        else if(raspuns=='2'){rezolva(n,georgian);
                              cout<<endl<<'\t'<<"Doriti sa testati din nou una din cele 2 optiuni? Va reamintim ca pentru a iesi din program apasati orice tasta in afara de 1 sau 2";
                                cout<<endl<<'\t';
                             cin>>raspuns;cin.get();}


    }
    cout<<endl<<endl<<'\t'<<"Programul se va inchide. Puteti verifica acum fisierul de iesire";
}

int main()
{

    meniu();

//cam atat :)) pai sati nu mi-ai aratat cum a tradus din georgiana

    return 0;
}
