#include <stdio.h>
#include <stdlib.h>

typedef struct dll
{
    int n;
    struct dll *next;
    struct dll *prev;
}  *node;
 node insert(node head);
node getnode ();
 void select(node head);


int main()
{
    node head=NULL;
    int N, i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        head=insert(head);
    }

    select(head);

    return 0;
}

node getnode ()
 {
     node new1;
     new1=(node) malloc(sizeof (struct dll));
     new1->next=NULL;
     new1->prev=NULL;
     scanf("%d",&new1->n);
     return new1;
 }
  node insert(node head)
 {
     node cur=head;
     node new1=getnode();
     if(head==NULL)
     return new1;
     while(cur->next!=NULL)
     {
         cur=cur->next;
     }
     cur->next=new1;
     new1->prev=cur;
     new1->next=NULL;
     return head;
 }

 void select(node head)
{
    node cur=head;
    int count=0;
    if(cur->n>150&&cur->n<cur->next->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    cur=cur->next;
    while(cur->next!=NULL)
    {
          if(cur->n>150&&cur->n<cur->next->n&&cur->n>cur->prev->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    cur=cur->next;
    }
     if(cur->n>150&&cur->n>cur->prev->n)
    {
        count++;
        printf("%d  ",cur->n);
    }
    printf("\n%d",count);

    }
