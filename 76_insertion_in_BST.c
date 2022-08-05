#include <stdio.h>
#include <stdlib.h>
//Insertion in Binary Search Tree
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
void insertion_bst(struct node *root, int key){
    struct node *ptr = root;
    struct node *prev = NULL;
    struct node *new_node = create_tree(key);

    while (ptr != NULL){
        prev = ptr;
        if (key == ptr->data){
            printf("%d is a duplicate !\n", key);
            return;
        }

        if (key < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (key < prev->data)
        prev->left = new_node;
    else
        prev->right = new_node;
}
int main(){
    struct node *root = create_tree(15);
    struct node *p1 = create_tree(6);
    struct node *p2 = create_tree(20);
    struct node *p3 = create_tree(2);
    struct node *p4 = create_tree(9);
    struct node *p5 = create_tree(16);

    /* 
            15
           /  \
          6    16
         / \   /
        2   9 20
    */

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    InOrder(root);
    printf("\n");
    insertion_bst(root, 19);
    InOrder(root);
    printf("\n");
    return 0;
}