#include<stdio.h>
void readarray(int [], int);
void printarray(int [], int);
void insert(int [], int);
void main()
{
    int a[10], n, k;
    scanf("%d", &n);
    readarray(a, n);
    printarray(a, n);
    insert(a,n);
}
void readarray(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void printarray(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\n", a[i]);
    }
}
void insert(int a[], int n)
{
    int num, pos, i;
    printf("Enter the element = \t");
    scanf("%d", &num);
    printf("Enter the position= \t");
    scanf("%d", &pos);
    if(pos>11)
    {
        printf("INVALID");
    }
    else
    {
        for(i=10; i>=pos; i--)
        {
            a[i]=a[i-1];
        }
        a[pos-1]=num;
        printf("Array elements after insertion= \n");
        for(i=0; i<n+1; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}
