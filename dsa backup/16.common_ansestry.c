#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};

struct node *lca(struct node *root, int node_1, int node_2)
{
    if (root != NULL)
    {
        if (root->data > node_1 && root->data > node_2)
        {
            return lca(root->left, node_1, node_2);
        }
        if (root->data < node_1 && root->data < node_2)
        {
            return lca(root->right, node_1, node_2);
        }
        return root;
    }
}
struct node *newNode(int data)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return(p);
}
int main()
{
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int node_1 = 10, node_2 = 14;
    struct node *t = lca(root, node_1, node_2);
    printf("LCA of %d and %d is %d \n", node_1, node_2, t->data);
    node_1 = 14, node_2 = 8;
    t = lca(root, node_1, node_2);
    printf("LCA of %d and %d is %d \n", node_1, node_2, t->data);
    node_1 = 10, node_2 = 22;
    t = lca(root, node_1, node_2);
    printf("LCA of %d and %d is %d \n", node_1, node_2, t->data);
    return 0;
}
