#include<stdio.h>
#include<string.h>

struct employee
{
int id;
char name[50];
}e1;

int main()
{
    e1.id=10;
    strcpy(e1.name,"XX");
    printf("employee id: %d\n",e1.id);
    printf("employee name:%s\n",e1.name);
}
