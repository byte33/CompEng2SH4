//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

void stringCopy(const char source[], char destination[], int n);

int main(void)
{
    const char source[] = "Hello4hdfjsknkea";
    int n = 6;
    char destination[n];

    stringCopy(source,destination,n);

    return 0;
}

void stringCopy(const char source[], char destination[], int n)
{
    int counter = 0;
    while ((source[counter] != '\0')) { //get size of source string
       counter++;
    }
    if (counter>n){ //if the source string is bigger than the destination string
        for (int i=0;i<n;i++) {  //only loop the size of the destination string
            destination[i] = source[i];
            //printf("%c ",destination[i]);
        }
        destination[n] = '\0'; //add a null character to the end of the destination string
    } else {  //if the source string is same size or less than the destination string
        for (int i=0;i<counter;i++) { //only loop the size of the source string
            destination[i] = source[i];
            //printf("%c ",destination[i]);
        }
        destination[counter] = '\0'; //add a null character to the end of the destination string
    }

    printf("Source string: %s\nDestination String: %s",source,destination);
}