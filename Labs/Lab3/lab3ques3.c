//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_words(const char *input_filename, int *nPtr);
char **sort_words(char **list, int *nPtr);

int main(void)
{

    const char filename[] = "in.txt";
    int num;
    int *nPtr = &num;
    char **list;
    // printf("%d\n",(sizeof(char)));

    list = read_words(filename,nPtr);
    list = sort_words(list,nPtr);
    printf("%s\n",list[0]);
    // printf("%d",*nPtr);

    return 0;
}


char **read_words(const char *input_filename, int *nPtr)
{
    FILE *inputFile = fopen(input_filename,"r");
    char **list = NULL;
    // int num;
    fscanf(inputFile,"%d",nPtr);
    // printf("%ld\n",(num*sizeof(char *)));
    list = calloc(*nPtr,sizeof(char *));

    for (int i=0;i<*nPtr;i++) {
        char word[51];
        fscanf(inputFile,"%s",word);
        list[i] = malloc(strlen(word)*sizeof(char));
        for(int j=0;j<strlen(word);j++)
        list[i][j] = word[j];
        // nPtr = list[i];

    }
    fclose(inputFile);
    // printf("%s",list[1]);
    return list;
}

char **sort_words(char **list, int *nPtr)
{
    int i;
    char *temp;
    int j;
    int counter = 0;
    for (i = 1; i < *nPtr; i++) { 
        temp = list[i]; 
        j = i - 1; 
  
        while (j >= 0 && list[j][0] > *temp) { 
            list[j + 1] = list[j]; 
            j--; 
        } 
        list[j+1] = temp; 
    } 
    return list;
}