#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue*next;
} * NODE;
NODE getnode();
NODE insert(NODE head,int k);
NODE delete(NODE head);
NODE enqueue(NODE head,int k);
NODE dequeue(NODE head);
void display(NODE head);
int isempty(NODE head);
int main()
{
    NODE head=NULL;
    int k,n,c;
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            scanf("%d",&k);
            head=enqueue(head,k);
            break;
        case 2:
            head=dequeue(head);
            break;
        case 3:
            display(head);
            break;
        default:
            break;
        }
    }
    return 0;
}
NODE getnode()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct queue));
    if(newnode==NULL)
    {
        printf("Node not created\n");
        exit(0);
    }
    newnode->next=NULL;
    return newnode;
}
NODE insert(NODE head,int k)
{
    NODE newnode=getnode();
    newnode->data=k;
    if(head==NULL)
        return newnode;
    else
    {
        NODE temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return head;
    }
}
NODE delete(NODE head)
{
    if(isempty(head)==-1)
    {
        printf("Empty\n");
        return NULL;
    }
    else
    {
        NODE cur=head;
        head=head->next;
        free(cur);
        return head;
    }
}
NODE enqueue(NODE head,int k)
{
    head=insert(head,k);
    return head;
}
NODE dequeue(NODE head)
{
    if (isempty(head) == -1)
    {
        printf("EMPTY\n");
        return NULL;
    }
    else
    {
        head = delete (head);
        return head;
    }
}
void display(NODE head)
{
   printf("%d\n",head->data);
}
int isempty(NODE head)
{
    if(head==NULL)
        return -1;
    else
        return 0;
}
