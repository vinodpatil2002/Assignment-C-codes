#include <stdio.h>
#define N 20
typedef struct employee
{
    char name[20];
    int salary;
}Emp;

void Employee(Emp E[20], int n)
{
    int i;
    printf("Employee Details:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter name of Employee:");
        scanf("%s", E[i].name);

        printf("Enter Salary of Employee:");
        scanf("%d", &E[i].salary);
    }
}

void DisplayEmployee(Emp E[20], int n)
{
    int i;
    printf("Employee Details:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nName of Employee:%s", E[i].name);
        printf("\nSalary of Employee:%d", E[i].salary);
        printf("\n");
    }
}

void main()
{
    int n;
    Emp E[100];
    printf("Enter the number of Employees:");
    scanf("%d", &n);
    Employee(E, n);
    DisplayEmployee(E, n);
}
