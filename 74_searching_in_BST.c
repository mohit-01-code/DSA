#include <stdio.h>
#include <stdlib.h>
//Searching in Binary Search Tree
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_tree(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
void InOrder(struct node *root){
    if (root != NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
struct node *search_bst(struct node *root, int key){
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (key < root->data)
        return search_bst(root->left, key);
    else if (key > root->data)
        return search_bst(root->right, key);
}
int main(){
    struct node *root = create_tree(8);
    struct node *p1 = create_tree(6);
    struct node *p2 = create_tree(10);
    struct node *p3 = create_tree(5);
    struct node *p4 = create_tree(7);
    struct node *p5 = create_tree(9);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    InOrder(root);
    if (search_bst(root, 10) != NULL)
        printf("\nElement found : %d\n", search_bst(root, 10)->data);
    else
        printf("\nElement Not found !\n");
    return 0;
}