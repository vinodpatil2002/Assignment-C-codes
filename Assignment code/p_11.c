/*11) Godrej constructed a new Apartment with N flats, in Hubballi.
 At the end of each month the Secretary of the apartment, collects
 the total units of electricity consumed by each flat.  As per the
 table given below, help Secretary to calculate the total bill to
 be paid by each flat.

Units Consumed	Charges apply
0-100	1.5 Rs/Unit
101-250	2.3 Rs/Unit, for above 100 units
251-600	4.0 Rs/Unit, for above 250 units
Above 600	5.5 Rs/Unit, for above 600 units

*/
#include <stdio.h>
#include <stdlib.h>


struct apartment
{
    int flatno;
    int unit;
}ap[100];

void read_unit(struct apartment[],int );
void calc_bill(struct apartment[],int );

int main()
{
    int n ;
    printf("\nEnter the total number of flats in the apartment : \n");
    scanf("%d",&n);
    read_unit(ap,n);
    calc_bill(ap,n);
    return 0;
}
void read_unit(struct apartment ap[],int b)
{
    int i,j;
    for(i=0,j=1;i<b;i++,j++)
    {
        printf("\nEnter the units of flat %d ",j);
        scanf("%d",&ap[i].unit);
        ap[i].flatno = j;
    }
}
void calc_bill(struct apartment ap[],int b)
{
    int i;
    float total_flat;
    total_flat = 0;
    for(i=0;i<b;i++)
    {
        if(ap[i].unit >=0 && ap[i].unit <= 100)
        {
            total_flat = ap[i].unit * 1.5;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);

        }
        if(ap[i].unit >=101 && ap[i].unit <= 250)
        {
            total_flat = ap[i].unit * 2.3;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);
        }
        if(ap[i].unit >=251 && ap[i].unit <= 600)
        {
            total_flat = ap[i].unit * 4.0;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);
        }
        if(ap[i].unit >600)
        {
            total_flat = ap[i].unit * 5.5;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);
        }

    }

}
