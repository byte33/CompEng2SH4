//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    FILE *input_file;
    FILE *output_file;
    int n,bit=0;

    input_file = fopen("inputfile2.txt","r");
    output_file = fopen("outputfile2.txt","w");
    while(!feof(input_file)) {
        fscanf(input_file,"%d",&n);
        printf("%d\n",n);
        //if n is empty, break
        for (int i=0;i<n;i++) {
            fprintf(output_file,"%d ",bit);
        }
        bit = !bit;
        n=0;
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}