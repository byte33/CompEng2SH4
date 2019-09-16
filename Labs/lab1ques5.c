//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    double approxPi = 0;
    int input;

    printf("Enter number of terms: ");
    scanf("%d",&input);

    if (input > 0) {

        for (int i=0;i<(input*2);i+=2) {
            double term = 4.0/(i+1);
            
            if ((i/2)%2) {approxPi = approxPi - term;}
            else {approxPi = approxPi + term;}
        }
        printf("%f",approxPi);
    }
    else {printf("Invalid input!");}
    return 0;
}
    