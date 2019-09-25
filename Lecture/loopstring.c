#include <stdio.h>

int main(void)
{
    char text[] = "Programming at McMaster is fun!";
    int i=0;
    int counter=0;
    
    while(text[i]!='\0') {
        if (text[i]=='m'||text[i]=='M') {
            counter++;
        }
        i++;
    }
    printf("The # is %d\n",counter);
    printf("%p",&counter);
    return 0;
}