#include<stdio.h>
int main()
{
    int a=20;
    int p=&a;
    int z;
    z=sizeof(p);
    printf("%d",z);
}
