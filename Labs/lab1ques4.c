//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    float average = 0.0;
    int intAverage = 0;
    
    printf("Input your intAverage: ");
    scanf("%f",&average);
    intAverage = average;
    if (intAverage < 100.0 && intAverage > 89.0) {printf("4");}
    else if (intAverage < 90 && intAverage > 79) {printf("3");}
    else if (intAverage < 80 && intAverage > 69) {printf("2");}
    else if (intAverage <  70 && intAverage > 59) {printf("1");}
    else if (intAverage <  60 && intAverage >= 0) {printf("0");}
    else {printf("Invalid input, please try again.\n");}

    return 0;
}