#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
   char name[20];
   int age;
   struct node *next;
};

typedef struct node *NODE;

NODE getnode();
NODE enqueue(NODE);
void display(NODE,int);

int main()
{
    NODE head=NULL;
    int n,i=0,k;
    scanf("%d",&n);
    scanf("%d",&k);
    if(n<1 || n>100)
    {
        printf("N should be greater than 0\n");
        exit(0);
    }
    while(i<n)
    {
        head=enqueue(head);
        i++;
    }
    display(head,n);
    return 0;
}

NODE getnode()
{
    NODE NEWNODE;
    NEWNODE=malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated\n");
    }
    scanf("%s%d",NEWNODE->name,&NEWNODE->age);
    NEWNODE->next=NULL;
    return NEWNODE;
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
    char person[20];
    scanf("%s",person);
    int count=0,position=0,cost1,cost2;
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
             position++;
             if(strcmp(cur->name,person)==0)
             {
                 printf("%d\n",position);
             }
         }
         else
         {
            if(strcmp(cur->name,person)==0)
             {
                 printf("0\n");
             }
         }
         cur=cur->next;
     }
     cost1=(n-count)*300;
     cost2=count*300;
     printf("%d\n",cost1);
     printf("%d",cost2);
}
