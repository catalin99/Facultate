#include<iostream>



#define r 5

#define c 5



using namespace std;



void zigzag(int mat[][c], int rand, int col) {

    int i = 0, j = 0;



    while (i < rand) {



        cout<<mat[i][j];

        if (i == rand - 1) {

            i = j + 1;

            j = col - 1;

        } else if (j == 0) {

            j = i + 1;

            i = 0;

        }



        else {

            j--;

            i++;

        }



    }



    cout<<"\n";

}



int main() {



    int m[][5] = { { 1, 2, 3, 4, 5 },

                   { 6, 5, 5, 6, 7 },

                   { 4, 6, 8, 8, 9 },

                   { 7, 7, 7, 6, 8 },

                   { 6, 6, 5, 7, 9 } };

    cout<<"Elementele spiralei sunt:";



    zigzag(m, r, c);

    return 0;

}
