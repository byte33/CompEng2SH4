//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {
    int input;
    do {
        printf("Please input an integer (0 to end): ");
        scanf("%d",&input);

        if (input >= 10000 && input < 100000) {printf("Your input is a 5 digit number: %d\n",input);}

    } while (input);
    
    printf("Thanks for using me.");
    return 0;
}