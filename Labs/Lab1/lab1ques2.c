//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    int input = 0;
    int smallestNum;
    int n;
    do {
        printf("How many times do you want to loop? ");
        scanf("%d",&n);
    } while(input < 0);

    for (int i=0;i<n;i++) {
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
