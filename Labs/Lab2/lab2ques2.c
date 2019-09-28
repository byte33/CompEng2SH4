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
    printf("%d",val);

    return 1;
}




int isDiagDom(int mat[][N])
{
    int diag;
    int sum;
    int val;
    for (int i=0;i<N;i++) {
        sum = 0;
        diag = (int)fabs(mat[i][i]);
        for (int j=0;j<N;j++) {
            if (!(i==j)) {sum+=mat[i][j];}
        }
        sum = (int)fabs(sum);
        if (diag<=sum) {break;}
    }
    val = (diag<=sum? 0 : 1);
    return val;
}