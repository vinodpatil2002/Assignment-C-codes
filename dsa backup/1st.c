// 1)	Read an array of numbers with size n and count frequency of positive/negative numbers
#include <stdio.h>
int main()
{
    int a[1000],i,n,c=0,p=0;

    printf("Enter size of the array : ");
    scanf("%d", &n);

    printf("Enter elements in array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

     for(i=0; i<n; i++)
    {

        if(a[i] < 0)
         c++;
    }
         printf("  count  of negative numbers  in array: %d",c);


        for(i=0; i<n; i++)
        {
        if(a[i]>0)
         p++;
        }
         printf(" count  of positive numbers  in array: %d",p);


    return 0;
}
