//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {
    int input;
    do {
        printf("Please input an integer (0 to end): ");
        scanf("%d",&input);

        if ((input >= 10000 && input < 100000)||(input <= -10000 && input > -100000)) {
            printf("Your input is a 5 digit number: %d\n",input); //check if input is in range of 5 digit num
        }

    } while (input);  //continue to loop program until user inputs 0
    
    printf("Thanks for using me.");
    return 0;
}