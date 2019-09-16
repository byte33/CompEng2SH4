//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    int sumFor = 0;
    int sumWhile = 0;
    int sumDoWhile = 0;
    int x = 30;
    int y = 30;

    for (int i=30; i<1000;i++) {

        if (!(i%4)){sumFor += i;}  //if i is a multiple of 4, increment sumFor
    }

    while (x < 1000) {

        if (!(x%4)){sumWhile += x;}  //if x is a multiple of 4, increment sumWhile
        x++;
    }

    do {
        if (!(y%4)){sumDoWhile += y;}  //if y is a multiple of 4, increment sumDoWhile
        y++;
    } while (y < 1000);

    printf("The sum of all numbers that are multiples of 4 is %d\n%d\n%d\n",sumFor,sumWhile,sumDoWhile);
    return 0;

}