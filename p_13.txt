/*13)	Write a modular C program to read a list of n random numbers
 and check whether each element of an array is perfect number or not.
*/

#include <stdio.h>
#include <stdlib.h>
void find_perfect(int [],int );
void read_array(int [],int );

int main()
{
    int a[100];
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    read_array(a,n);
    find_perfect(a,n);

    return 0;
}
void read_array(int a[],int b)
{
    int i;
    printf("\nEnter %d elements : \n",b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
}
void find_perfect(int a[],int b)
{
    int i,j,sum,temp;



    sum = 0;
    j=1;
    for(i=0;i<b;i++)
    {


        temp = a[i];
        while(j <= (a[i])/2)
        {

            if(a[i] % j == 0)
            {
                sum = sum + j;
            }
            j++;
        }

        if(sum == temp)
            printf("\n %d is a perfect number ",temp);
        else
            printf("\n %d is not a perfect number ",temp);

    }
}
