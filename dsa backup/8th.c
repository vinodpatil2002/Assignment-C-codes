/*8)	A middle class family would always like to spend the money wisely, because of their financial status.
 They can’t afford to purchase the luxurious items unlike the Rich Class family.
  Even if they do, they do it very occasionally.  In order to keep track of the expenditure of the entire year,
  the middle class family maintains a record of how much they spent every month of that year.
Assume that for the year 2020, the family maintains a record of expenditure for each month.
 At the end of the year, the family would like to know followings about their expenditure.
i)	Which month of the year they spent more (display month number)
ii)	Which month of the year they spent less(display month number)
iii)	Which are the months they spent more than 35000 rupees?(display month number)
iv)	Calculate the average expenditure of the family for the year.*/

#include <stdio.h>
#include <stdlib.h>

struct expend
{
    int months;
    int expenditure;
}exp[12];
void read_expenditure(struct expend []);
void spent_more(struct expend []);
void spent_less(struct expend []);
void spent_ab_35(struct expend []);
void average_expenditure(struct expend []);



int main()
{
    int n;
    read_expenditure(exp);
    spent_more(exp);
    spent_less(exp);
    spent_ab_35(exp);
    average_expenditure(exp);

    return 0;
}
void read_expenditure(struct expend exp[])
{
    int i,j;
    for(i=0,j=1;i<12;i++,j++)
    {
        printf("\nEnter the expenditure of month %d  \t",j);
        scanf("%d",&exp[i].expenditure);
        exp[i].months = j;
    }
}
void spent_more(struct expend exp[])
{
    int i,mno;
    int highest;
    highest = exp[0].expenditure;
    mno = 0;

    for(i=0;i<12;i++)
    {
        if(exp[i].expenditure > highest)
        {
            highest = exp[i].expenditure;
            mno = exp[i].months;
        }

    }
    printf("\n The highest spent month was:  %d \n The expenditure was : %d",mno,highest);


}

void spent_less(struct expend exp[])
{
    int i,mno;
    int lowest;
    lowest = exp[0].expenditure;
    mno = 0;

    for(i=0;i<12;i++)
    {
        if(exp[i].expenditure < lowest)
        {
            lowest = exp[i].expenditure;
            mno = exp[i].months;
        }

    }
    printf("\n The lowest spent month was:  %d \n The expenditure was : %d",mno,lowest);


}
void spent_ab_35(struct expend exp[])
{
    int i,mno;
    mno = 0;
    printf("\n The  months  where the expenditure was above 35000 were : \n ");
    for(i=0;i<12;i++)
    {
        if(exp[i].expenditure > 35000)
        {
            mno = exp[i].months;
            printf("%d\t ",mno);
        }

    }
}
void average_expenditure(struct expend exp[])
{
    int i,sum;
    sum = 0;
    float average = 0;
    for(i=0;i<12;i++)
    {
        sum = sum + exp[i].expenditure;
    }
    average = (float)sum/12;
    printf("\n The total expenditure was : %d ",sum);
    printf("\n The average expenditure was : %0.2f ",average);

}


