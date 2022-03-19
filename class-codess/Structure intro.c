#include<stdio.h>

struct student
{
    int roll_no;
    char name[15];
    int marks;
};

void main()
{
    struct student student;
    struct student *ptr=&student;

    printf("Roll number of student is %d\n",ptr->roll_no);
    printf("Name of Student is %s\n",ptr->name);
    printf("Marks of Student is %d\n",ptr->marks);
}
