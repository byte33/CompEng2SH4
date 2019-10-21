//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(const char * const str1, const char * const str2);

int main(void)
{
    char string1[100] = "Hello";
    char string2[100] = "World";

    printf("%s\n", my_strcat(string1, string2));

    return 0;
}

char *my_strcat(const char * const str1, const char * const str2)
{

    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    int finalLen = str1Len + str2Len + 1;
    char *p = malloc(finalLen * sizeof(char));
    int counter = 0;

    // printf("%c ", *str1);
    for (int i=0;i<str1Len;i++) {
        p[counter] = str1[i];
        counter++;
    }

    for (int i=0;i<str2Len;i++) {
        p[counter] = str2[i];
        counter++;
    }

    p[finalLen-1] = '\0';

    return p;
}