/*12)	Write a modular c program to perform the following:
 a) Read 1D array
 b) Display 1D array
 c) To find the maximum digit in every element of an array and
 find sum of all maximum digits.
Write a suitable main function to call the above user defined
functions
Example:
Input: arr[3] = {132,458,732}
Output: Maximum digit in a[0]=3
Maximum digit in a[1]=8
Maximum digit in a[2]=7
Sum=3+8+7=18
*/
#include <stdio.h>
#include <stdlib.h>
void read_array(int [],int );
void find_max_dig(int[],int);
void print_array(int [] ,int);

int main()
{
    int a[100];
    int n;
    printf("\n Enter the size of array : ");
    scanf("%d",&n);
    read_array(a,n);
    print_array(a,n);
    find_max_dig(a,n);

    return 0;
}
void read_array(int a[],int b)
{
    int i;
    printf("\nEnter %d array elements: \n ",b);

    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[],int b)
{
    int i;
    printf("{");
    for(i=0;i<b;i++)
    {
        printf(" %d \t ",a[i]);

    }
    printf("}");
}
void find_max_dig(int a[],int b)
{
    int i,s;
    int first,middle,last,sum,largest;
    sum = 0;

    for(i=0;i<b;i++)
    {
        first = a[i]/100;
        s  = a[i]%100;
        last = s % 10;
        middle = s/10;
        if(first > middle && first > last)
            largest = first;
        if(middle > first && middle > last)
            largest = middle;
        if(last > first && last > middle)
            largest = last;

        printf("\n Maximum digit in a[%d] is %d ",i,largest);
        sum = sum + largest;

    }
    printf("\nSum of largest is : %d ",sum);



}
