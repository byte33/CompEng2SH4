//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#define K 3

void efficient(const int source[], int val[], int pos[], int size);
void reconstruct( int source[], int m, const int val[], const int pos[], int n);

int main(void)
{
    int source[]={0,0,23,0,-7,0,0,48};
    int val[K]={23,-7,48};
    int pos[K]={2,4,7};
    int size=8;

    efficient(source,val,pos,size);
    reconstruct(source,size,val,pos,K);

    return 0;
}

void efficient(const int source[], int val[], int pos[], int size)
{
    int counter=0;
    for (int i=0;i<size;i++) {
        if (source[i] == 0) {continue;} //if the current value of the index is a zero, continue looping
        val[counter] = source[i];  //if it is non zero, record the value and the position
        pos[counter] = i;
        counter++; //go to the next index since the current index is populated now (for val[] and pos[] only)
    }
    printf("The val vector looks like: [ ");
    for (int j=0;j<counter;j++) {printf("%d ",val[j]);}
    printf("]\nThe pos vector looks like: [ ");
    for (int j=0;j<counter;j++) {printf("%d ",pos[j]);}
    printf("]\n");
}

void reconstruct( int source[], int m, const int val[], const int pos[], int n)
{
    int counter=0;
    for (int i=0;i<m;i++) {
        if (i == pos[counter]) {  //only do this if there is a non zero element, which can be compared to the pos value
            source[i] = val[counter];  //set the value to source at the current position.
            counter++; //go to the next element in pos[] and val[]
            continue; //continue the loop
        }
        source[i] = 0; //there is a zero at this position if this runs
    }
    printf("The source vector looks like: [ ");
    for (int j=0;j<m;j++) {printf("%d ",source[j]);}
    printf("]\n");
}