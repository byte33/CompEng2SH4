//Matteo Tullo
//tullom
//400175089
//side1<=side2
#include <stdio.h>

int main(void) {

    int counter = 0;
    for (int side1=1;side1<401;side1++) {
        for (int side2=1;side2<401;side2++) {
            for (int side3=1;side3<401;side3++) {
                float hypotenuse = (side1*side1)+(side2*side2); //c^2 = a^2+b^2
                if (hypotenuse==(float)side3*side3 && side1<=side2) {
                    printf("%d %d %d\n",side1,side2,side3);counter++; //cast side3 to float to compare
                }
            }
        }
    }
    printf("There were %d total triples.\n",counter);
    return 0;
}