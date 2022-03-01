/*14)	Find equilibrium index in an array. An index is equilibrium
, where sum of right side elements is equal to sum of left side elements.
Ex: A={-7,1,5,2,-4,3,0}
Here '3' is equilibrium index since A[0]+A[1]+A[2] = A[4]+A[5]+A[6].


*/
#include <stdio.h>
#include <stdlib.h>

int find_index(int [], int );
int main()
{
        int a[100];
        int n,eqi;
        printf("\nEnter array size : ");
        scanf("%d",&n);

        printf("\nInput the array elements : ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        eqi = find_index(a,n);
        printf("\nEquilibrium Index : %d\n", eqi);
        return 0;
}


int find_index(int a[], int b)
{
int i, j;
int l_sum, r_sum;

for (i = 0; i < b; ++i)
    {

        l_sum = 0;
        for (j = 0; j < i; j++)
        l_sum += a[j];

        r_sum = 0;
        for (j = i + 1; j < b; j++)
        r_sum += a[j];

        if (l_sum == r_sum)
        return i;
    }

    return -1;
}
