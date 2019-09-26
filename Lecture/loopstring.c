#include <stdio.h>

int main(void)
{
    char text[] = "Programming at McMaster is fun!";
    int i=0;
    int counter=0;
    char a[20];
    puts("Five chars plz");
    gets(a);
    printf("%c, its integer value is %d\n",a[4],a[4]);
    printf("%c, its integer value is %d\n",a[5],a[5]);
    puts(a);
    // while(text[i]!='\0') {
    //     if (text[i]=='m'||text[i]=='M') {
    //         counter++;
    //     }
    //     i++;
    // }
    //printf("The # is %d\n",counter);
    printf("%p",&counter);
    return 0;
}