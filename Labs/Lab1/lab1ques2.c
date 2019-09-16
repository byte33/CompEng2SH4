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
        } while (input < 0);  //make sure that the input is greater than 0

        if (i==0) {smallestNum = input;}  //on first iteration, set smallestNum = input
        if (input < smallestNum) {
            smallestNum = input; //if input is less than the smallestNum, set smallestNum as input
        }
    }
    
    printf("The smallest number is %d",smallestNum);
    return 0;
}
