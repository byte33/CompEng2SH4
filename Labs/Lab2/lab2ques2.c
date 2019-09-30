//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#include <math.h>
#define N 3

int isDiagDom(int mat[][N]);

int main(void)
{
    int x[][N] = {{4,2,1},{2,8,3},{6,3,10}};
    int val = 0;
    val = isDiagDom(x);
    if (val) {printf("The matrix is diagonally dominant");}
    else {printf("The matrix is not diagonally dominant");}

    return 0;
}




int isDiagDom(int mat[][N])
{
    int diag;
    int sum;
    int val;
    for (int i=0;i<N;i++) {
        sum = 0; //set sum = 0 for every loop
        diag = (int)fabs(mat[i][i]); //get the diagonal value for the current row
        for (int j=0;j<N;j++) {
            if (!(i==j)) {sum+=mat[i][j];}  //add all the values other than the diagonal
        }
        sum = (int)fabs(sum);
        if (diag<=sum) {break;} //if diag is less than the sum, it is not diag dom so break out of loop
    }
    val = (diag<=sum? 0 : 1); //if diag is less than sum, return 0 b/c its not diag dom
    return val;
}