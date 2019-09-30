//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#define N 5

void diagScan(int mat[][N]);

int main(void)
{
    int x[][N] = {{1,12,13,49,8},
                  {5,16,17,81,6},
                  {9,10,11,20,0},
                  {2,45,19,14,7},
                  {1,12,13,49,1}};
    diagScan(x);

    return 0;
}

void diagScan(int mat[][N])
{
    for (int i=0;i<N;i++) {  //cycle thru row
        for (int j=0;j<N;j++) { //cycle thru column
            if ((i-j)>=0) {printf("%d ",mat[i-j][j]);}  //print the index of the difference of row and the column
                                                        //and the current column
        }
    }
    for (int x=0;x<N;x++) { //cycle thru row
        int temp = N-1; //we want the row number that is the size of the array minus 1 
        for (int y=x+1;y<N;y++) { //cycle thru column, y will become larger as x increases
            printf("%d ",mat[temp][y]); 
            temp--; //we want the row above so decrement.
        }
    }
}