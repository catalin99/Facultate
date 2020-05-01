#include <iostream>
bogdan@edusoft.ro
int primacifra(int numar) //functie pentru prima cifra a unui numar
{
    while(numar>9)
        numar/=10;
    return numar;
}

int cmmdc(int nr1, int nr2) //functie pentru cmmdc a doua numere
{
    while(nr1!=nr2)
        if(nr1>nr2)
            nr1=nr1-nr2;
        else
            nr2=nr2-nr1;
    return nr1;
}

int cmmmc(int nr1, int nr2) //functie pentru cmmmc a doua numere
{
    int p=nr1*nr2;
    return p/cmmdc(nr1, nr2);
}

bool primeintreele(int nr1, int nr2)//functie pentru verifiecare daca doua numere sunt prime intre ele;
{
    if(cmmdc(nr1, nr2)==1)
        return true;
    return false;
}

float mediaaritmetica(int x[100], int n)// functie pentru media aritmetica a numerelor din vector
{
    int s=0;
    for(int i=1; i<=n; i++)
        s=s+x[i];
    return (float)s/n;
}

int oglindit(int numar)//functie pentru oglinditul unui numar
{
    int c=1;
    int newnumber=0;
    while(numar)
    {
        newnumber=numar%10*c+newnumber;
        c*=10;
        numar/=10;
    }
    return newnumber;
}

int minim(int nr1, int nr2) //functie pentru minim
{
    if(nr1<nr2)
        return nr1;
    else
        return nr2;
}

int sumacifre(int numar) //functie pentru suma cifrelor unui numar
{
    int suma=0;
    while(numar)
    {
        suma+=numar%10;
        numar/=10;
    }
    return suma;
}

void citire(int citire[], int &elem) //citire
{
    std::cin>>elem;
    std::cout<<"Introduceti elementele vectorului "<<'\n';
    for(unsigned int i=1; i<=elem; i++)
        std::cin>>citire[i];
    return;
}

void afisare(int afisare[], int elem) //afisarea elementelor unui vector
{
    for(unsigned int i=1; i<=elem; i++)
        std::cout<<afisare[i]<<' ';
    std::cout<<'\0';
}

int f1(int x[100], int n) //f1= 1*x[1]+2*x[2]+3*x[3]+…+n*x[n];
{
    int i=1;
    int nr=0;
    for(i=1; i<=n; i++)
        nr+=(i*x[i]);
    return nr;
}

int f2(int x[100], int n) //f2 = 1*x[n]+2*x[n-1]+3*x[n-2]+…+2*x[n-1]+1*x[n];
{
    int i=1;
    int nr=0;
    for(i=1; i<=n; i++)
        nr+=(i*x[n-i+1]);
    return 2*nr;
}

int f3(int x[100], int n) //f3 = x[1]+x[1]*x[2]+x[1]*x[2]*x[3]+…+x[1]*x[2]*…*x[n];
{
    int i=1;
    int nr=0;
    int prec=1;
    for(i=1; i<=n; i++)
    {
        nr+=(x[i]*prec);
        prec=prec*x[i];
    }
    return nr;
}

int f4(int x[100], int y[100], int n) //f4= min(x[1],y[1])+min(x[2],y[2])+…+min(x[n],y[n]);
{
    int i;
    int nr=0;
    for(i=1; i<=n; i++)
        nr=nr+minim(x[i],y[i]);
    return nr;
}

int f5(int x[100], int y[100], int n) //f5 = x[1]/y[n]-x[2]/y[n-1]+x[3]/y[n-2]-…+…-…….. x[n]/y[1];
{
    int i;
    int nr=0;
    int semn=0;
    for(i=1; i<=n; i++)
        if(!semn)
        {
            nr=nr-x[i]/y[n-i+1];
            semn++;

        }
        else
        {
            nr=nr+x[i]/y[n-i+1];
            semn--;
        }
    return nr;
}

int f6(int x[100], int y[100], int n) //f6 = s(x[1]+y[1])+s(x[2]+y[2])+…+s(x[n]+y[n]), unde s(a) este suma cifrelor numarului a;
{
    int i;
    int nr=0;
    for(i=1; i<=n; i++)
        nr+=sumacifre(x[i]+y[i]);
    return nr;
}

void f7(int x[100], int y[100], int z[100], int n) // z[1]= min(x[1],y[1]), z[2] min(x[2],y[2]),…, z[n]=min(x[n],y[n]);
{
    int i;
    for(i=1; i<=n; i++)
        z[i]=minim(x[i], y[i]);
    afisare(z, n);
    return;
}

void f8(int x[100], int y[100], int z[100], int n)//z[1] =cmmdc(x[1],y[n]), z[2]=cmmdc(x[2],y[n-1])
{
    int i;
    for(i=1; i<=n; i++)
        z[i]=cmmdc(x[i], x[n-i+1]);
    afisare(z, n);
    return;
}

void f9(int x[100], int y[100], int z[100], int n)// z[1] = uc(x[1]+y[1]), z[2]=uc(x[2]+y[2]),…, z[n]=uc(x[n],y[n]), unde uc(a) este ultima cifra a numarului a;
{
    int i;
    for(i=1; i<=n; i++)
        z[i]=(x[i]+y[i])%10;
    afisare(z, n);
    return;
}

bool f10(int x[100], int y[100], int z[100], int n)//z[1]==x[1]*y[1], z[2]==x[2]*y[2],…, z[n]==x[n]*y[n];
{
    for(int i=1; i<=n; i++)
        if(z[i]!=x[i]*y[i])
            return false;
    return true;
}

bool f11(int x[100], int y[100], int z[100], int n)//z[1]==cmmmc(x[1]*2,y[n]*3), z[2]=cmmmc(x[2]*2,y[n-1]*3), …, z[n]==cmmmc(x[n]*2,y[1]*3)
{
    for(int i=1; i<=n; i++)
        if(z[i]!=cmmmc(x[i]*2,y[n-i+1]*3))
            return false;
    return true;
}

bool f12(int x[100], int y[100], int z[100], int n)//z[1]==pc(x[1]+y[1]*1), z[2]=pc(x[2]+y[2]*2),…, z[n]=pc(x[n]+y[n]*n)
{
    for(int i=1; i<=n; i++)
        if(z[i]!=primacifra(x[i]+y[i]*i))
            return false;
    return true;
}

int f13(int x[100], int n) //k1 = 1, daca toate elementele din x sunt identice intre ele, respectiv 0 in caz contrar
{
    int k1=1;
    for(int i=2; i<=n; i++)
        if(x[i]!=x[1])
        {
            k1=0;
            break;
        }
    return k1;
}
int f14(int x[100], int n)//k2 = numarul de perechi de elemente prime intre ele, aflate pe pozitii egal distantate de centrul vectorului
{
    int i, j, mij, k2=0;
    if(n%2==1)
    {
        mij=n/2+1;
        i=mij-1;
        j=mij+1;
    }
    else
    {
        i=n/2;
        j=n/2+1;
    }
    while(i>=1 && j<=n)
    {
        if(primeintreele(x[i], x[j]))
            k2++;
        i--;
        j++;
    }
    return k2;
}

int f15(int x[100], int n) //k3 = numarul de aparitii ale valorii x[1] in vectorul x
{
    int k3=1;
    for(int i=2; i<=n; i++)
        if(x[1]==x[i])
            k3++;
    return k3;
}

void f16(int x[100], int n)//x[n], x[n-1], x[n-2], …, x[3], x[2], x[1];
{
    for(int i=1; i<=n/2; i++)
        std::swap(x[i], x[n]);
    afisare(x, n);
    return;
}

void f17(int x[100], int n)//x[2], x[1], x[4], x[3], …., x[n-1], x[n]; (aici n este par)
{
    for(int i=1; i<=n-1; i+=2)
        std::swap(x[i], x[i+1]);
    afisare(x, n);
    return;
}

void f18(int x[100], int n)//x[2], x[3], x[4], …, x[n], x[1];
{
    int a=x[1];
    for(int i=1; i<=n-1; i++)
        x[i]=x[i+1];
    x[n]=a;
    afisare(x, n);
    return;
}

void f19(int x[100], int n)//x[n],x[1],x[2],…,x[n-1];
{
    int a=x[n];
    for(int i=n; i>=2; i--)
        x[i]=x[i-1];
    x[1]=a;
    afisare(x, n);
    return;
}

void f20(int x[100], int n)//x[1], 0, x[3], 0, x[5], 0, …;
{
    for(int i=1; i<=n; i++)
        if(i%2==0)
            x[i]=0;
    afisare(x, n);
}

void f21(int x[100], int n)//1*x[1], 2*x[2], 3*x[3], …, n*x[n];
{
    for(int i=1; i<=n; i++)
        x[i]=i*x[i];
    afisare(x, n);
}

void f22(int x[100], int n)//x[1], -x[2], x[3], -x[4], …, ;
{
    for(int i=1; i<=n; i++)
        if(i%2==0)
            x[i]=0-x[i];
    afisare(x, n);
    return;
}

void f23(int x[100], int n)//0, x[2], x[3], 0, x[5], x[6], 0, x[8], x[9], …;
{
    for(int i=1; i<=n; i+=3)
        x[i]=0;
    afisare(x, n);
    return;

}

void f24(int x[100], int n)//n*x[1], (n-1)*x[2], (n-2)*x[3], …, 1*x[n];
{
    for(int i=1; i<=n; i++)
        x[i]=x[i]*(n-i+1);
    afisare(x, n);
    return;
}

int f25(int x[100], int n)//k4 = numarul de elemente din x care sunt egale cu suma vecinilor sai;
{
    int k4=0;
    for(int i=2; i<=n-1; i++)
        if(x[i]==x[i-1]+x[i+1])
            k4++;
    return k4;
}

int f26(int x[100], int n)//k5 = numarul de perechi de elemente prime intre ele, aflate pe pozitii consecutive in vector;
{
    int k5=0;
    for (int i=2; i<=n; i++)
        if(primeintreele(x[i-1],x[i]))
            k5++;
    return k5;
}

int f27(int x[100], int n)//k6 = numarul de elemente negative din vector, aflate pe pozitii divizibile prin 3;
{
    int k6=0;
    for(int i=1; i<=n; i++)
        if(x[i]<0 && i%3==0)
            k6++;
    return k6;
}

int f28(int x[100], int n)//k7 = numarul de elemente din x care sunt mai mari decat media aritmetica a elementelor vectorului;
{
    int k7=0;
    float m=mediaaritmetica(x, n);
    for(int i=1; i<=n; i++)
        if(x[i]>m)
            k7++;
    return k7;
}
int f29(int x[100], int n)//k8 = numarul de elemente din vector care sunt egale cu oglinditele lor;
{
    int k8=0;
    for(int i=1; i<=n; i++)
        if(x[i]==oglindit(x[i]))
            k8++;
    return k8;
}

int f30(int x[100], int n)//k9 = numarul de elemente pozitive si pare din vector, aflate pe pozitii impare;
{
    int k9=0;
    for(int i=1; i<=n; i++)
        if(x[i]>=0 && x[i]%2==0 && i%2==1)
            k9++;
    return k9;
}

void copiere(int u[100], int v[100], int n) //creeaza o copie a lui u in vectorul v
{
    for(int i=1; i<=n; i++)
        v[i]=u[i];
    return;
}

int main()
{
    int a[100], b[100], c[100], d[100], s[100], n;
    std::cout<<"Introduceti nr elemente pentru primul vector "<<'\n';
    citire(a, n);
    std::cout<<"Introduceti nr elemente pentru al doilea vector "<<'\n';
    citire(b, n);
    std::cout<<"Introduceti nr elemente pentru al treilea vector "<<'\n';
    citire(d, n);
    copiere(a, s, n); //creeaza o copie pentru vectorul a
    std::cout<<"Rezultatul pentru 1 a): "<<f1(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 1 b): "<<f2(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 1 c): "<<f3(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 2 a): "<<f4(a, b, n)<<'\n';
    std::cout<<"Rezultatul pentru 2 b): "<<f5(a, b, n)<<'\n';
    std::cout<<"Rezultatul pentru 2 c): "<<f6(a, b, n)<<'\n';
    std::cout<<"Rezultatul pentru 3 a): ";
    f7(a, b, c, n); std::cout<<'\n';
    std::cout<<"Rezultatul pentru 3 b): ";
    f8(a, b, c, n); std::cout<<'\n';
    std::cout<<"Rezultatul pentru 3 c): ";
    f9(a, b, c, n); std::cout<<'\n';
    std::cout<<"Rezultatul pentru 4 a): ";
    if(!f10(a, b, d, n))
        std::cout<<"false"<<'\n';
    else
        std::cout<<"true"<<'\n';
    std::cout<<"Rezultatul pentru 4 b): ";
    if(!f11(a, b, d, n))
        std::cout<<"false"<<'\n';
    else
        std::cout<<"true"<<'\n';
    std::cout<<"Rezultatul pentru 4 c): ";
    if(!f12(a, b, d, n))
        std::cout<<"false"<<'\n';
    else
        std::cout<<"true"<<'\n';
    std::cout<<"Rezultatul pentru 5 a): "<<f13(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 5 b): "<<f14(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 5 c): "<<f15(a, n)<<'\n';
    //afisare(a, n); std::cout<<'\n';
    std::cout<<"Rezultatul pentru 6 a): ";
    f16(a, n); std::cout<<'\n';
    copiere(s, a, n); //reface vectorul a conform datelor introduse de la tastatura
    //afisare(a, n); std::cout<<'\n';
    std::cout<<"Rezultatul pentru 6 b): ";
    f17(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 6 c): ";
    f18(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 7 a): ";
    f19(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 7 b): ";
    f20(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 7 c): ";
    f21(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 8 a): ";
    f22(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 8 b): ";
    f23(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 8 c): ";
    f24(a, n); std::cout<<'\n';
    copiere(s, a, n);
    std::cout<<"Rezultatul pentru 9 a): "<<f25(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 9 b): "<<f26(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 9 c): "<<f27(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 10 a): "<<f28(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 10 b): "<<f29(a, n)<<'\n';
    std::cout<<"Rezultatul pentru 10 c): "<<f30(a, n)<<'\n';
    return 0;
}
