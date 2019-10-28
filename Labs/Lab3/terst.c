#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int studentID;
    char firstName[16];
    char lastName[16];
    int proj1Grade;
    int proj2Grade;
    float totalGrade;
} student;


student **create_class_list(char *filename, int *sizePtr);

int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);

void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);

void destroy_list(student **list, int *sizePtr);

int main()
{
    char fileName[12] = "students.txt";
    char *fileNamep = fileName;
    int size;
    int *sizep = &size;
    student **ptrA;

    printf("Part 1\n");
    ptrA = create_class_list(fileNamep,sizep);

    return 0;


}

student **create_class_list(char *filename, int *sizePtr)

{
    FILE *input_file=fopen(filename,"r");

    fscanf(input_file,"%d",sizePtr);
    student** classList=calloc((*sizePtr), sizeof(student*));

    int i;
    for (i=0;i<*sizePtr;i++)
    {
        classList[i] = calloc(1,sizeof(student));
    }
    for (i=0;i<*sizePtr;i++)
    {
        printf("hi");
        //initializing each student structure, calloc ensures grades initialized to 0
        fscanf(input_file,"%d",&classList[i]->studentID);
        fscanf(input_file,"%s",classList[i]->firstName);
        fscanf(input_file,"%s",classList[i]->lastName);
    }
    fclose(input_file);
    return classList;
}

int find(int idNo, student **list, int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        if (list[i]->studentID == idNo)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

void input_grades(char *filename, student **list, int size)
{
    FILE *input_file=fopen(filename,"r");

    int i,idNum,position;
    for (i=0;i<size;i++)
    {
        fscanf(filename,"%d",&idNum);
        position = find(idNum,filename,size);

        fscanf(filename,"%d%d",&(list[position]->proj1Grade),&(list[position]->proj2Grade));
    }
}

void compute_final_course_grades(student **list, int size)
{
    int i,grade;
    for (i=0;i<size;i++)
    {
        grade = (list[i]->proj1Grade) + (list[i]->proj2Grade)/2;
        list[i]->totalGrade = grade;
    }
}

void output_final_course_grades(char *filename, student **list, int size)
{
    FILE *output_file=fopen(filename,"w");
    fprintf(output_file,"%d\n",size);

    int i;
    for (i=0;i<size;i++)
    {
        fprintf(output_file,"%d %f\n",list[i]->studentID,list[i]->totalGrade);
    }
}

void print_list(student **list,int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        printf("ID: %d, name: %s %s, proj1 grade: %d, proj2 grade: %d, final grade: %f",list[i]->studentID,
               list[i]->firstName,list[i]->lastName,list[i]->proj1Grade,list[i]->proj2Grade,list[i]->totalGrade);
    }
}

void withdraw(int idNo, student **list, int *sizePtr)
{
    int i,location = 0;
    for (i=0;i<*sizePtr;i++)
    {
        if (list[i]->studentID == idNo)
        {
            location = i+1;
            free(list[i]);
        }
    }
    for (location+1;location<*sizePtr;location++)
    {
        list[location] = list[location+1];
    }
}

void destroy_list(student **list, int *sizePtr)
{
    int i;
    for (i=0;i<*sizePtr;i++)
    {
        free(list[i]);
    }
}
