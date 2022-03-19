#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct Node {
int data;
struct Node* next;
};


void swap(int* a, int* b);


void pairWiseSwap(struct Node* head)
{
struct Node* temp = head;


while (temp != NULL && temp->next != NULL) {

swap(&temp->data, &temp->next->data);


temp = temp->next->next;
}
}



void swap(int* a, int* b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}


void push(struct Node** head_ref, int new_data)
{

struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));


new_node->data = new_data;


new_node->next = (*head_ref);


(*head_ref) = new_node;
}


void printList(struct Node* node)
{
while (node != NULL) {
printf("%d ", node->data);
node = node->next;
}
}


int main()
{
struct Node* head = NULL;


;
push(&head, 5);
push(&head, 4);
push(&head, 3);
push(&head, 2);
push(&head, 1);

printf("Linked list before calling pairWiseSwap()\n");
printList(head);

pairWiseSwap(head);

printf("\nLinked list after calling pairWiseSwap()\n");
printList(head);

return 0;
}

