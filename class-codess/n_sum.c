#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, n, sum=0;
    printf("Enter value of n= \n");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        sum= sum+i;
    }
    printf("Sum= %d", sum);
}
