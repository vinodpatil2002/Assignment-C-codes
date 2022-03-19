#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node * NODE;

NODE getnode();
NODE delete_front(NODE);
NODE delete_end(NODE);
NODE swap(NODE);
NODE insert_front(NODE);
void read(NODE);
NODE insert_end(NODE);
void display(NODE);

void main()
{
    NODE head=NULL;
    int choice;
    while(1)
    {
        printf("\n1.Insert front\n2.Insert end\n3.Delete front\n4.delete end\n5.display list\n6.Swap\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert_front(head);
                    break;
            case 2:head=insert_end(head);
                    break;
            case 3:head=delete_front(head);
                    break;
            case 4:head=delete_end(head);
                    break;
            case 5:printf("Display list\n");
                   display(head);
                   break;
            case 6: head=swap(head);
                    break;
            case 7: exit(0);
                    break;
            default:printf("Invalid\n");
        }
    }
}

NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct node));
    if(newn==NULL)
        printf("Memory allocation failed\n");
    return newn;
}
void read(NODE newn)
{
    printf("Enter details\n");
    scanf("%d",&newn->data);
    newn->next=NULL;
}
NODE insert_front(NODE head)
{
    NODE newn=getnode();
    read(newn);
    if(head==NULL)
        return newn;
    newn->next=head;
    head=newn;
    return head;
}
NODE insert_end(NODE head)
{
    NODE newn=getnode();
    if(newn==NULL)
        return head;
    read(newn);
    if(head==NULL)
        return newn;
    else
    {
        NODE cur=head;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=newn;
        return head;
    }
}
NODE delete_front(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        NODE cur=head;
        head=head->next;
        free(cur);
        return head;
    }
}
NODE delete_end(NODE head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return head;
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        NODE prev=NULL;
        NODE cur=head;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        free(cur);
        prev->next=NULL;
        return head;
    }
}
void display(NODE head)
{
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        NODE cur=head;
        while(cur!=NULL)
        {
            printf("%d-->",cur->data);
            cur=cur->next;
        }
    }
}
NODE swap(NODE head)
{
    NODE cur=head;
    NODE temp=NULL;
    while(cur!=NULL && cur->next!=NULL)
    {
        temp= cur->data;
        cur->data= cur->next->data;
        cur->next->data= temp;
        cur= cur->next->next;
    }
    return head;
}
