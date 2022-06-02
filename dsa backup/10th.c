/*10)	Ashish is studying in 3RD standard in KENDRIYA VIDYALA, Hubballi.
He is writing the Mathematics Test in the school.
 One of the questions was to find the PRIME NUMBERS among a set of N numbers.
  Help Ashish to find the PRIME numbers*/

 #include <stdio.h>
#include <stdlib.h>

void find_prime(int [],int );
void read_num(int[] , int);

int main()
{
    int ar[100];
    int n;
    printf("\n Enter number of elements : \n");
    scanf("%d",&n);
    read_num(ar,n);
    find_prime(ar,n);
    return 0;
}
void read_num(int a[],int b)
{
    int i;
    printf("\nEnter %d elements into the array : \n",b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Entered successfully ..\n");

}
void find_prime(int a[] ,int b)
{
    int i,j,flag;
    printf("\nThe prime numbers in the array are : \n ");
    for(i=0;i<b;i++)
    {
       j = 2;
       flag = 1;
       while (j < a[i]) {
           if (a[i] % j == 0) {
               flag  = 0;
               break;
           }
           j++;
       }
       if (flag == 1) {
           printf("%d \t", a[i]);
       }
    }

}
