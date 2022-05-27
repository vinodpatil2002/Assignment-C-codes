//Lucky draw bot randomly picks the winners. It posts an announcement message listing all the winners in the channel immediately after the activity is closed.
//Everyone in the channel can see all the people joined the draw. Tryle team is conducting lucky draw contest, N number of users registered to the contest
//and all users will be provided with unique user id. Tryle team makes use of Stack to store all the N user id�s. It�s very difficult for the team to select
//the lucky winners among N users. So the team come-up with a solution to select the lucky winners.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} *NODE;

NODE push(NODE top, int item)
{
    NODE tmp = (NODE)malloc(sizeof(struct stack));
    if(tmp==NULL)
    {
        printf("Memory error.\n");
        exit(0);
    }
    tmp->data = item;
    if(top==NULL)
        tmp->next = NULL;
    else
        tmp->next = top;
    return tmp;
}

NODE pop(NODE top)
{
    if(top==NULL)
    {
        printf("Shelf is empty.\n");
    }
    else
    {
        NODE tmp = top;
        top = top->next;
        //printf("%d\n", tmp->data);
        free(tmp);
    }
    return top;
}

void display(NODE top, int k)
{
    if(top==NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        NODE cur = top;
        int cw=0, cl=0;
        while(cur != NULL)
        {
            if(cur->data % k == 0)
            {
                printf("W ");
                cw++;
            }
            else
            {
                printf("L ");
                cl++;
            }
            cur = cur->next;
        }
        printf("\n%d\n%d", cw, cl);
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, d;
    NODE top = NULL;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        top = push(top, d);
    }
    display(top, k);
    return 0;
}


