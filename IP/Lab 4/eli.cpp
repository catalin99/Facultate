#include <iostream>
using namespace std;
struct punct
{
    float x, y;
};
struct segment
{
    punct A; punct B;
};
//using coordonate=punct;
//#define punct coordonate
void mijloc(segment S, punct &M)
{
    M.x=(S.A.x+S.B.x)/2;
    M.y=(S.A.y+S.B.y)/2;
    //cout<<"M("<<M.x<<","<<M.y<<")";
    //return M;

}
int main()
{
    punct A, B, M;
    segment S;
    cout<<"Dati coordonatele primului punct: ";
    cin >> S.A.x>>S.A.y;
    cout<<"Dati coordonatele celui de-al doilea punct: ";
    cin>>S.B.x>>S.B.y;
    mijloc (S, M);
    cout<<"M("<<M.x<<","<<M.y<<")";
    return 0;
}
