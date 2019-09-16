//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    double approxPi = 0;
    unsigned long input;

    printf("Enter number of terms: ");
    scanf("%d",&input);

    if (input > 0) {

        for (unsigned long int i=0;i<(input*2);i+=2) {
            double term = 4.0/(i+1); //each term has the numerator constant at 4 and the denominator incrementsby 2i+1

            if ((i/2)%2) {approxPi = approxPi - term;} //every odd increment is a subtract
            else {approxPi = approxPi + term;} //every even increment is an add
        }
        printf("Pi is approximately %.10f",approxPi);
    }
    else {printf("Invalid input!");}
    return 0;
}
    