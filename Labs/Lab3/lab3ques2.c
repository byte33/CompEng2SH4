//Matteo Tullo
//tullom
//400175089

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char firstName[16];
    char lastName[16];
    int proj1Grade;
    int proj2Grade;
    float finalGrade;
}   Student;

Student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, Student **list, int size);
void input_grades(char *filename, Student **list, int size);
//void compute_final_course_grades();
//void output_final_course_grades();
void print_list(Student **list, int size);
void withdraw(int idNo, Student **list, int *sizePtr);
void destroy_list(Student **list, int *sizePtr);

Student now[3];

int main(void) 
{
    char filename[13] = "students.txt";
    int siz;
    char *filenameP = filename;
    int *size = &siz;
    Student **classList = create_class_list(filenameP,size); 
    printf("\n%d", classList[0]->id);
    printf("\n%s", classList[0]->firstName);
    printf("\n%s", classList[0]->lastName);
    // printf("%s", filenameP);

    return 0;
}


Student **create_class_list(char *filename, int *sizePtr)
{
    FILE *input_file = fopen(filename,"r");
    Student **classList = NULL;

    fscanf(input_file,"%d",sizePtr);
    // printf("%d",*sizePtr);
    // printf("%d",sizePtr);
    // printf("%d",(((int)sizePtr) * (sizeof(Student *))));
    classList = calloc((*sizePtr),(sizeof(Student *)));

    for (int i=0;i<(*sizePtr);i++) {
        fscanf(input_file,"%d",&now[i].id);
        fscanf(input_file,"%s",now[i].firstName);
        fscanf(input_file,"%s",now[i].lastName);
        // printf("%d %s %s",now[i].id,now[i].firstName,now[i].lastName);
        // now[i].id = idN;
        classList[i] = &now[i];
    }
        // printf("%d", classList[1]->id);

    fclose(input_file);
    return classList;
}