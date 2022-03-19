#include<stdio.h>
typedef struct Employee
{
    char name[20];
    int salary;
}Emp;

void ReadEmployee(Emp *E1[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter name of Employee:");
        scanf("%s",E1[i]->name);

        printf("Enter Salary of Employee:");
        scanf("%d",&E1[i]->salary);
    }
}
void DisplayEmployee(Emp *E1[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nName of Employee:%s",E1[i]->name);
        printf("\nSalary of Employee:%d",E1[i]->salary);
        printf("\n");
    }

}

void main()
{
    int n;
    Emp E[20];
    Emp *E1[20];

    printf("Enter number of Employees:");
    scanf("%d",&n);

    ReadEmployee(E1,n);
    DisplayEmployee(E1,n);

}
