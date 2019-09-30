//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#define K 3

void efficient(const int source[], int val[], int pos[], int size);
void reconstruct( int source[], int m, const int val[], const int pos[], int n);
void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2);

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
        if (source[i] == 0) {continue;}
        val[counter] = source[i];
        pos[counter] = i;
        counter++;
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
        if (i == pos[counter]) {
            source[i] = val[counter];
            counter++;
            continue;
        }
        source[i] = 0;
    }
    printf("The source vector looks like: [ ");
    for (int j=0;j<m;j++) {printf("%d ",source[j]);}
    printf("]\n");
}

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2)
{
    
}