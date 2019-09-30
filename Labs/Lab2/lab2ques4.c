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
    while ((word[counter] != '\0')) {  //count the size of the word
       counter++;
    }

    for (int x=0;x<26;x++) { //make sure that all the indicies of freq[] are zeroed.
        freq[x]=0;
    }

    //printf("%d",counter);
    
    for (int i=0;i<counter;i++) {
        int ascii = (int)word[i];  //get ascii value of letter
        //printf("%d\n",ascii);
        if (ascii>=97 && ascii<=122) {  //if it is a lowercase num, subtract 97 to bring the first letter to zero
            ascii -= 97;
            //printf("%d\n",ascii);
        } else if (ascii>=65 && ascii<=90) {  //if it is a uppercase num, subtract 65 to bring the first letter to zero
            ascii -= 65;
            //printf("%d\n",ascii);
        }
        freq[ascii]++; //add the letter to the freq array
    }

    for (int j=0;j<26;j++) {
        int letter = 97+j;
        int upperLetter = 65+j;
        printf("The frequency of the letter '%c' or '%c' is %d\n",(char)(letter),(char)upperLetter,freq[j]);  //print freq of each letter of alphabet
        }
}