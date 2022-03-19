#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data[2][2];
    struct Node *next;
};
typedef struct Node *NODE;
NODE getnode()
{
    NODE newn;
    int i,j,a[2][2];
    newn=(NODE *)malloc(sizeof(struct Node));
    if(newn==NULL)
    {
        printf("memory is not allocated\n");
        exit(0);
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {

    printf("enter numbers to be inserted\n");
    scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
    newn->data[i][j]=a[i][j];
        }
    }

    newn->next=NULL;
    return newn;
}
NODE insert_front(NODE head)

{

  NODE newn;

  newn=getnode();
  newn->next=NULL;
    if(head==NULL)
        return newn;
    newn->next=head;
        return newn;

}
NODE display(NODE head)
{
    int i,j;
    NODE newn;
    newn=head;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    printf("The elements in the list are\n");

  while(newn!=NULL)

  {
      for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {

    printf("%d\t",newn->data[i][j]);


        }
        printf("\n");
    }
    newn=newn->next;
    printf("\n");

  }
  printf("\n");

}

int main()

{
    int choose;

    NODE head=NULL;
   while(1)
   {

   printf(" 1-Insert at front\n 2-display\n ");

   scanf("%d",&choose);

        switch(choose)

         {

            case 1 : head=insert_front(head);

                        break;
            case 2: head=display(head);
         }
   }
         return 0;
}
