#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    char data[25];
    struct node *prev;
    struct node *next;
}*NODE;

NODE getNode(char d[25])
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    //scanf("%d", &n->data);
    strcpy(n->data, d);
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE insert_end(NODE head, char d[25])
{
    NODE temp = getNode(d);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE delete(NODE head, char key[25])
{
    if(head==NULL)
        return head;
    NODE cur = head;
    while(cur!=NULL)
    {
        if(!(strcmp(cur->data,key)))
            break;
        cur = cur->next;
    }
    if(cur->next==NULL)
        cur->prev->next = NULL;
    else
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    free(cur);
    return head;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        //printf("Elements in the linked list : ");
        while(cur!=NULL)
        {
            printf("%s ", cur->data);
            cur = cur->next;
        }
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head = NULL;
    int n, q;
    char d[25];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", d);
        head = insert_end(head,d);
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        scanf("%s", d);
        head = delete(head, d);
    }
    display(head);
    return 0;
}
