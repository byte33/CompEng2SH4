//Matteo Tullo
//tullom
//400175089
#include <stdio.h>

int main(void) {

    int inputArray[20];
    int counter=0;

    for (int i=20;i>0;i--) {
        printf("Enter an integer: (%d left)\n",i);
        scanf("%d",&inputArray[counter]);
        counter++;
    }
    for (int x=0;x<20;x++) {
        if (inputArray[x]>inputArray[x+1]) {continue;}
        else {printf("The array is sorted in a non decreasing order.");break;}
    }
    return 0;
}