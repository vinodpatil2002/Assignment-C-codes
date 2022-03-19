#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n, rem, rev=0, temp;
    printf("Enter the value of n= \t");
    scanf("%d", &n);
    temp=n;
    while(n>0)
    {
        rem= n%10;
        rev= (rem*10) + rev;
        n= n/10;
    }
    if(temp==rev)
    {
        printf("PALINDROME");
    }
    else
    {
        printf("NOT PALINDROME");
    }
}
