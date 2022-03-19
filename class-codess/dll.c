#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

NODE insert_front(NODE);
NODE insert_end(NODE);
NODE insert_specific(NODE);
NODE getNode();
void display(NODE);

void main()
{
    NODE head = NULL;
    int choice;
    while (1)
    {
        printf("\n1.Insert front\n2.Insert end\n3.Insert specific \n4.Display list\n5.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insert_front(head);
            break;
        case 2:
            head = insert_end(head);
            break;
        case 3:
            head = insert_specific(head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid");
        }
    }
}

NODE getnode()
{
    NODE newn = (NODE)malloc(sizeof(struct node));
    if (newn == NULL)
        printf("Memory allocation failed\n");
    return newn;
}
void read(NODE newn)
{
    printf("Enter Details:");
    scanf("%d", &newn->data);

    newn->prev = NULL;
    newn->next = NULL;
}

NODE insert_front(NODE head)
{
    NODE newn = getnode();
    read(newn);
    NODE ptr = newn;

    if (head == NULL)
    {
        return newn;
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        ptr->prev = NULL;
        head = ptr;

        return head;
    }
}

NODE insert_end(NODE head)
{
    NODE newn = getnode();
    read(newn);

    NODE cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    newn->prev = cur;
    newn->next = NULL;

    return head;
}

NODE insert_specific(NODE head)
{
    int pos;
    printf("Enter Position:");
    scanf("%d",&pos);
    NODE newn = getnode();
    read(newn);
    NODE temp = head;

    int i;
    if (head == NULL)
    {
        return newn;
    }
    else
    {
        for (i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
        temp->next->prev = newn;

        return head;
    }
    return head;
}

void display(NODE head)
{
    NODE temp = head;
    if (head == NULL)
    {
        printf("Empty List:");
        exit(0);
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }
}
