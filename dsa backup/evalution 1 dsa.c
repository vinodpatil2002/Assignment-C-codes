#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data; //data is the height
    struct node *prev;
    struct node *next;
};

struct node *head;
void create()
{
    struct node *newn,*temp;
    newn=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newn->data);
    newn->next=0;
    newn->prev=0;

    if(head==0)
    {
        head=newn;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void display()
{
    struct node *temp;
    if(head==0)
        printf("\nThe list is empty");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }
}


void compare_dis()
{
    struct node* cur=head;
    int count=0;
    if(cur->data>150&&cur->data<cur->next->data)
    {
        count++;
        printf("\n%d  ",cur->data);
    }
    cur=cur->next;
    while(cur->next!=NULL)
    {
          if(cur->data>150&&cur->data<cur->next->data&&cur->data>cur->prev->data)
    {
        count++;
        printf("\n%d  ",cur->data);
    }
    cur=cur->next;
    }
     if(cur->data>150&&cur->data>cur->prev->data)
    {
        count++;
        printf("\n%d  ",cur->data);
    }
    printf("\n%d",count);

    }
int main()
{
    int n,i;
    printf("\nEnter the number of candidates:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        create();
    }
    display();
    compare_dis();

    return 0;
}
