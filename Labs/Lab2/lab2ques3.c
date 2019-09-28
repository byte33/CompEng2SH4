//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#define N 4

void diagScan(int mat[][N]);

int main(void)
{
    int x[][N] = {{1,12,13,49},{5,16,17,81},{9,10,11,20},{2,45,19,14}};
    diagScan(x);

    return 0;
}

void diagScan(int mat[][N])
{
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if ((i-j)>=0) {printf("%d ",mat[i-j][j]);}
        }
    }
    for (int x=0;x<N;x++) {
        for (int y=0;y<N;y++) {
            if((N-x)-(y+1)>0) {printf("%d ",mat[N-x-1][y+1]);}
        }
    }
    printf("\n\n%d",mat[3][1]);
}