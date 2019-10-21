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
void compute_final_course_grades(Student **list, int size);
void output_final_course_grades(Student **list, int size);
void print_list(Student **list, int size);
void withdraw(int idNo, Student **list, int *sizePtr);
void destroy_list(Student **list, int *sizePtr);

Student now[3];

int main(void) 
{
    char filename[13] = "students.txt";
    char filename2 [11] = "grades.txt";
    int siz;
    char *filenameP = filename;
    char *filenameP2 = filename2;
    int *size = &siz;


    Student **classList = create_class_list(filenameP,size); 
    // printf("\n%d", classList[0]->id);
    // printf("\n%s", classList[0]->firstName);
    // printf("\n%s", classList[0]->lastName);
    // printf("%s", filenameP);

    int f = find(4001,classList,*size);
    // f < 0 ? printf("Number was not found") : printf("Number was found at index %d",f);

    input_grades(filenameP2, classList, *size);
    // printf("\n%d", classList[1]->proj2Grade);

    compute_final_course_grades(classList, *size);
    // printf("\n%f", classList[2]->finalGrade);

    output_final_course_grades(classList, *size);

    print_list(classList, *size);

    withdraw(4002, classList, size);

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

int find(int idNo, Student **list, int size)
{
    for (int i=0;i<size;i++) {
        if (idNo == list[i]->id) {return i;}
    }

    return -1;
}

void input_grades(char *filename, Student **list, int size)
{
    FILE *input_file = fopen(filename,"r");
    int num;
    
    for (int i=0;i<size;i++) {
        int counter = 0;
        fscanf(input_file,"%d",&num);
        while (num != list[counter]->id) {
            if (counter>1000) {printf("id not found");}
            counter++;
        }
        fscanf(input_file,"%d %d",&list[counter]->proj1Grade,&list[counter]->proj2Grade);
    }
    fclose(input_file);
}

void compute_final_course_grades(Student **list, int size)
{
    float av;
    for (int i=0;i<size;i++) {
        av = (list[i]->proj1Grade + list[i]->proj2Grade)/2.00;
        list[i]->finalGrade = av;
    }
}

void output_final_course_grades(Student **list, int size) 
{
    FILE *output_file = fopen("output.txt","w");
    fprintf(output_file,"%d\n",size);
    
    for (int i=0;i<size;i++) {
        fprintf(output_file,"%d %f\n",list[i]->id,list[i]->finalGrade);
    }

    fclose(output_file);
}

void print_list(Student **list, int size)
{
    for (int i=0;i<size;i++) {
    printf("ID: %d, Name: %s %s, Proj 1 Grade: %d, Proj 2 Grade: %d, Final Grade: %f\n",
            list[i]->id,list[i]->firstName,list[i]->lastName,list[i]->proj1Grade,list[i]->proj2Grade,list[i]->finalGrade);
    }
}

void withdraw(int idNo, Student **list, int *sizePtr) 
{

    int index = find(idNo,list,*sizePtr);

    for (int i=index; i<(*sizePtr-index);i++) {
        list[i] = list[i+1];
    }
    
    // free(list[2]);
    printf("%s",list[0]->firstName);
}