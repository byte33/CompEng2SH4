//Matteo Tullo
//tullom
//400175089

#include <stdio.h>

int main(void) {

    FILE *input_file;
    FILE *output_file;
    int n,bit=0,counter=0;

    input_file = fopen("inputfile2.txt","r");
    output_file = fopen("outputfile2.txt","w");
    while(!feof(input_file)) {  //while the file is not at the end
        fscanf(input_file,"%d",&n);
        counter+=n; //sum number of numbers
        n=0;
    }

    fprintf(output_file,"%d ",counter);
    rewind(input_file);  //rewind pointer

    while(!feof(input_file)) {  //while the file is not at the end
        fscanf(input_file,"%d",&n);//read number of times to loop
        //printf("%d\n",n);
        for (int i=0;i<n;i++) {
            fprintf(output_file,"%d ",bit); //output the number of 1s or 0s
        }
        bit = !bit; //invert bit
        n=0;
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}