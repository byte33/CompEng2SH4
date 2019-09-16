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
    fscanf(input_file,"%d",&firstNum); //identify if the first num is a 1 or 0
    for(int i=0;i<numOfNum-1;i++) {
        fscanf(input_file,"%d",&n);
        if (n==firstNum) {counter++;} //if the next num is equal to the first num, increment
        else {
            fprintf(output_file,"%d ",counter);
            counter=1;
            firstNum = n;  //if not, reset counter and flip
        }
        if (i==numOfNum-2) {fprintf(output_file,"%d ",counter);} //make sure to print the last numbers

    }
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}