#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};
void linked_list_traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element = %d \n",ptr->data);
        ptr = ptr->next;
    }
    
}

struct node * insertatfirst(struct node *head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;

}
struct node * deleteAtFirst(struct node * head) // deletes top most element from the list;
{
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node * deleteAtindex(struct node * head, int index) // deletes  element at the give index number  from the list;
{
    struct node * p = head;
    struct node *q = head->next;

    for(int i = 0; i<(index-1);i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct node * deleteAtLast(struct node * head) // deletes  element at the give index number  from the list;
{
    struct node * p = head;
    struct node *q = head->next;

    while (q->next!=NULL)
    {
        p = p->next;
        q=q->next;
    }
     
    p->next = NULL;
    free(q);
    return head;
}
struct node * deleteAtLast(struct node * head,int data) // deletes  element at the given value  from the list;
{
    struct node * p = head;
    struct node *q = head->next;

    while (q->data!=data && q->next!=NULL)
    {
        p = p->next;
        q=q->next;
    }
     
    //p->next = NULL;
    if(q->data == data)
    {
        p->next = q->next;
        free(q);
        
    }
    free(q);
    return head;
}

struct node * insertatindex(struct node *head,int data,int index)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i!=(index-1))    //traversing until it finds the index number 
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node * insertAtEnd(struct node *head,int data)   //inserts at the end
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL) //traversing until it finds the end pointer
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

}
int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    //Allocates the memory in the heap 
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
    //linking first and second nodes 
    head->data = 1;
    head->next = second;
    //linking second and third nodes 
    second->data = 2;
    second->next = third;
    //linking second and third nodes 
    third->data = 3;
    third->next = fourth;
    //linking fourth to null  
    fourth->data = 4;
    fourth->next = NULL;
 
    //linked_list_traversal(head);
    //head = insertatfirst(head,44);
    //head = insertatindex(head,21,3);
    //head = insertAtEnd(head,511);
    printf("\nList before delete : \n");

    linked_list_traversal(head);
    head  = deleteAtFirst(head);

    printf("\nList after delete: \n");

    linked_list_traversal(head);


}