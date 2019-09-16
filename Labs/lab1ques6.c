//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#include <math.h>

int main(void) {

    int hi,counter = 0;
    for (int side1=1;side1<401;side1++) {
        for (int side2=1;side2<401;side2++) {
            for (int side3=1;side3<401;side3++) {
                float hypotenuse = sqrt(pow(side1,2)+pow(side2,2));
                if (hypotenuse==(float)side3) {printf("%d %d %d\n",side1,side2,side3);counter++;}
            }
        }
    }
    printf("There were %d total triples.\n",counter);
    return 0;
}