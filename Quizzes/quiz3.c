#include <stdio.h>
#define N 10

void transpose(double mat[][N])
{
    int num[N][N];

    for (int i=0;i<N;i++) {
        for (int x=0;x<N;x++) {
            num[x][i] = mat[i][x];
        }
    }

        for (int y=0;y<N;y++) {
            for (int z=0;z<N;z++) {
                mat[y][z] = num[y][z];
        }
    }
}

int main(void)
{
    int d [N][N] = {{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9},{0,1,2,3,4,5,6,7,8,9}};
    for (int i=0;i<N;i++) {
        for (int x=0;x<N;x++) {
            printf("%d\t",d[i][x]);
        }
        printf("\n");
    }
}


