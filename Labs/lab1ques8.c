//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    unsigned long int input;
    unsigned long int i=1,n=1,numOfZeroes=0,newNum=0,single=0,secondN=1;

    printf("Please enter an integer: ");
    scanf("%ld",&input);

    while (i!=0) {
        i = input/n;
        numOfZeroes++;
        n*=10;
    }
    numOfZeroes--;
    n/=100;
    //printf("%d\n%d",numOfZeroes,n);

    for (int x=1;x<numOfZeroes+1;x++) {
        single = input/n;
        //printf("%d\n",single);
        newNum += (single*secondN);
        input %= n;
        secondN *= 10;
        n /= 10;
    }
    printf("%ld",newNum);

    return 0;
}