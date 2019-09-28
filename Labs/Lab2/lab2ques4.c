//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

void letterFreq(const char word[],int freq[]);

int main(void)
{
    int freq[25];
    const char word[] = "abcdefghijklmnopqrstuvwxyz";

    letterFreq(word,freq);

    return 0;
}

void letterFreq(const char word[],int freq[])
{
    int counter = 0;
    while ((word[counter] != '\0')) {
       counter++;
    }

    for (int x=0;x<26;x++) {
        freq[x]=0;
    }

    //printf("%d",counter);
    
    for (int i=0;i<counter;i++) {
        int ascii = (int)word[i];
        //printf("%d\n",ascii);
        if (ascii>=97 && ascii<=122) {
            ascii -= 97;
            //printf("%d\n",ascii);
        } else if (ascii>=65 && ascii<=90) {
            ascii -= 65;
            //printf("%d\n",ascii);
        }
        freq[ascii]++;
    }

    for (int j=0;j<26;j++) {
        int letter = 97+j;
        int upperLetter = 65+j;
        printf("The frequency of the letter '%c' or '%c' is %d\n",(char)(letter),(char)upperLetter,freq[j]);
        }
}