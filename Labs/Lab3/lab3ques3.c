//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_words(const char *input_filename, int *nPtr);
char **sort_words(char **list, int *nPtr);
void output_words(char **list,int *nPtr);
char **sort_words2(char **list, int *nPtr);

int main(void)
{

    const char filename[] = "in.txt";
    int num;
    int *nPtr = &num;
    char **list;
    // printf("%d\n",(sizeof(char)));

    list = read_words(filename,nPtr);
    list = sort_words2(list,nPtr);
    // printf("%s\n",list[0]);
    // printf("%d",*nPtr);
    output_words(list,nPtr);

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

void output_words(char **list,int *nPtr)
{
    for (int i=0;i<*nPtr;i++) {
        printf("%s\n",list[i]);
    }
}

char **sort_words2(char **list, int *nPtr)
{
    int count = 0;
    char *temp;
    do{
        count = 0;
        for(int i=0;i<(*nPtr)-1;i++) {
            if (list[i][0] > list[i+1][0]) {
                count++;
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
            }
        }

    } while(count != 0);
    return list;
}