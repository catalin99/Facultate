#include <iostream>
#include <cmath>
using namespace std;
#define MATRIX_HEIGHT 10
#define MATRIX_WIDTH 11
int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
void circle(int *ptr, int cx, int cy, int ray)
{
    int ret;
    double dist;
    for(int i=0; i<MATRIX_HEIGHT; i++)
        for(int j=0; j<MATRIX_WIDTH; j++)
        {
            int x=(i-cx)*(i-cx);
            int y=(j-cy)*(j-cy);
            dist=sqrt(abs(x)+abs(y));
            int dist1=ceil(dist);
            if(dist1==ray)
                *(ptr+(i*MATRIX_WIDTH+j))=1;
        }
}
int main()
{
    circle(&Matrix[0][0], 3, 3, 2);
    for(int i=0; i<MATRIX_HEIGHT; i++)
    {
        for(int j=0; j<MATRIX_WIDTH; j++)
            cout<<Matrix[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
