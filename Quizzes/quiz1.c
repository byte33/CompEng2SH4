//Matteo Tullo
//tullom
//400175089
#include <stdio.h>

int main(void) {

    int i=0, x=0, sum=0;
    
    for (i=0;i<10;i++) {
        printf("Please input an integer\n");
        scanf("%d",&x);
        
        if (x%2) {
            sum += x;
        }
    }
    printf("your sum is %d", sum);
    return 0;
}