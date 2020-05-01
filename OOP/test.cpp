#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
using namespace std;

class A
{
public:
        int a;
};

class B
{
public:
    int b;
};

class C: public A, public B
{
public:
    int c;
};

int main()
{
    A oba;
    oba.a=1;
    B obb;
    obb.b=2;
    C obc;
    obc.a=4;
    obc.b=5;
    obc.c=8;
    A *pta=new A;
    pta->a=20;
    B *ptb=new B;
    ptb->b=25;
    C *ptc=new C;
    pta=ptc;
    ptc->a=33;
    ptc->b=39;
    ptc->c=41;
    printf("A %d, B %d, C.a %d, C.b %d, C.c %d\n",oba.a,obb.b,obc.a,obc.b,obc.c);
    printf("PTR: A %d, B %d, C ref a: %d\n",pta->a,ptb->b,ptc->a);
    printf("Test 2: Ptc.b: %d, Ptc.c %d\n", ptc->b,ptc->c);
    printf("sizeof obiect clasa c: %d",sizeof(obc));
    printf("\n\n\t test string: \n\n");
    string s1("Mama ");
    string s2(s1+"are alune");
    string s3(" si pere");
    string s4(s2+s3);
    printf("%s *printf s.c_str()* \n",s4.c_str()); //!!!!!!!!!!!!!!!!!!!
    cout<<s4<<" *cout<<s4*\n";
}
