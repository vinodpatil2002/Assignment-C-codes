//On the release date of the movie Venom 2, there is a huge line at the ticket counter at INOX and price of each ticket is 300Rs. To manage the huge number
//of ticket buyers, the INOX staff named Vikram requests the people to form new line formed in such a way that maximum K number of people who have age
//between 18 to 25, are allowed. Display the content of new line. One of the person standing in new line wants to know his/her position and requests
//INOX staff to tell his/her position. After approving the request of the person, INOX staff displays the current position. Help INOX staff to display
//total amount collected in both lines. The people in line are recognized by Name and Age.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct queue
{
   char name[20];
   int age;
   struct queue *next;
};

typedef struct queue *NODE;

NODE getnode();
NODE enqueue(NODE);
void display(NODE,int);



NODE getnode()
{
    NODE NEWN;
    NEWN=malloc(sizeof(struct queue));
    if(NEWN==NULL)
    {
        printf("Memory is not allocated\n");
    }
    scanf("%s%d",NEWN->name,&NEWN->age);
    NEWN->next=NULL;
    return NEWN;
}

NODE enqueue(NODE head)
{
    NODE newnode=getnode();
    NODE cur=head;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newnode;
        return head;
    }
}

void display(NODE head, int n)
{
    NODE temp=head;
    char p[20];
    scanf("%s",p);
    int count=0,pos=0,c1,c2;
     while(temp!=NULL)
     {
         if(temp->age>=18 && temp->age<=25)
         {
             count++;
             printf("%s %d\n",temp->name,temp->age);
         }
         temp=temp->next;
     }
     NODE cur=head;
     while(cur!=NULL)
     {
         if(cur->age>=18 && cur->age<=25)
         {
             pos++;
             if(strcmp(cur->name,p)==0)
             {
                 printf("%d\n",pos);
             }
         }
         else
         {
            if(strcmp(cur->name,p)==0)
             {
                 printf("0\n");
             }
         }
         cur=cur->next;
     }
     c1=(n-count)*300;
     c2=count*300;
     printf("%d\n%d",c1,c2);
}

int main()
{
    NODE head=NULL;
    int n,i,k;
    scanf("%d",&n);
    scanf("%d",&k);
    if(k>=n)
    {
        printf("N should be greater than 0\n");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        head=enqueue(head);

    }
    display(head,n);
    return 0;
}
