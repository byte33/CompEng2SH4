//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    FILE *input_file;
    FILE *output_file;
    int n,numOfNum,firstNum,counter=1;

    input_file = fopen("inputfile1.txt","r");
    output_file = fopen("outputfile1.txt","w");
    fscanf(input_file,"%d",&numOfNum);
    fscanf(input_file,"%d",&firstNum);
    for(int i=0;i<numOfNum-1;i++) {
        fscanf(input_file,"%d",&n);
        if (n==firstNum) {counter++;}
        else {
            fprintf(output_file,"%d ",counter);
            counter=1;
            firstNum = n;
        }
        if (i==numOfNum-2) {fprintf(output_file,"%d ",counter);}

    }
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}