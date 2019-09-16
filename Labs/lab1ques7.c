//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    int input;
    printf("Please enter an integer m (m>1): ");
    scanf("%d",&input);

    for (int i=input;i>1;i--) {
        //printf("%d\n",i);
        int sum=0;
        for (int x=i-1;x>0;x--) {
            //printf("%d\n",i%x);
            if (i%x == 0) {sum+=x;}
        }
        if (i==sum) {printf("wow %d is a perfect number\n",i);}
    }

    return 0;
}