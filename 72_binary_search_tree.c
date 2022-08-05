#include <stdio.h>
#include <stdlib.h>
//Checking if tree is Binary Search Tree or Not!
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_tree(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    n->data = data;
    n->left = n->right = NULL;
}
void tree_traversal(struct node *root){
    if (root != NULL){
        tree_traversal(root->left);
        printf("%d ", root->data);
        tree_traversal(root->right);
    }
}
int chk_bst(struct node *root){
    static struct node *prev = NULL;
    if (root != NULL){
        if (!chk_bst(root->left))
            return 0;
        if (prev != NULL && prev->data >= root->data)
            return 0;
        prev = root;
        return chk_bst(root->right);
    }
    else
        return 1;
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

    tree_traversal(root);
    printf("\n%d\n", chk_bst(root));
    return 0;
}