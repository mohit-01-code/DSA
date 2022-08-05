#include <stdio.h>
#include <stdlib.h>
//Linked representation of a binary tree
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_node(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
int main(){
    struct node *root = create_node(2);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(1);
    struct node *p3 = create_node(7);

    root->left = p1;
    root->right = p2;
    p1->left = p3;

    return 0;
}