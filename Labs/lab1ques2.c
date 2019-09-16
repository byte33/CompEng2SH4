//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    int input = 0;
    int smallestNum;
    for (int i=0;i<5;i++) {
        do {
            printf("Input an integer: ");
            scanf("%d",&input);
        } while (input < 0);

        if (i==0) {smallestNum = input;}
        if (input < smallestNum) {
            smallestNum = input;
        }
    }
    
    printf("%d",smallestNum);
    return 0;
}
