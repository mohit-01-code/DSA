#include <stdio.h>
#include <stdlib.h>
//Preorder Traversal in Binary Tree
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_array(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
void tree_traversal(struct node *root){
    if (root != NULL){
        printf("%d ", root->data);
        tree_traversal(root->left);
        tree_traversal(root->right);
    }
}
int main(){
    struct node *root = create_array(0);
    struct node *p1 = create_array(1);
    struct node *p2 = create_array(2);
    struct node *p3 = create_array(3);
    struct node *p4 = create_array(4);
    struct node *p5 = create_array(5);

    root->left = p1;
    root->right = p5;
    p1->left = p2;
    p1->right = p4;
    p2->right = p3;

    tree_traversal(root);
    printf("\n");
    return 0;
}