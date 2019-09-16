//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    int i=0;
    while (i<10) {
        i++;
        if (i%3 == 0) break;
        printf("%d\n",i);
    }
    printf("\n\n");
    i=0;
    while (i<10) {
        i++;
        if (i%3 == 0) continue;
        printf("%d\n",i);
    }
    return 0;
}