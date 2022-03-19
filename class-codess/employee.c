#include <stdio.h>
#include <stdlib.h>
 struct employee
{
    int id;
    char name[50];
};
void readEmployee(struct employee *ptr, int n);
void displayEmployee(struct employee *ptr, int n);

int main()
{
    int n;
    struct employee *ptr;
    printf("Enter total number of employees :");
    scanf("%d", &n);
    ptr = (struct employee *)malloc(sizeof(struct employee) * n);
    readEmployee(ptr, n);
    displayEmployee(ptr, n);
    free(ptr);

    return 0;
}
void readEmployee(struct employee *ptr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter employee ID:", i + 1);
        scanf("%d", &(ptr + i)->id);
        printf("Enter employee name:", i+1);
        scanf("%s", (ptr+i)->name);
    }
}
void displayEmployee(struct employee *ptr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d Employee Id:%d\n\t Name :%s\n", i + 1, (ptr + i)->id, (ptr+i)->name);
    }
}
