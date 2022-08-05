#include <stdio.h>
#include <stdlib.h>
//Stack Operations using Linked list
struct node{
    int data;
    struct node *next;
};

struct stack{
    struct node *top;
};

int isEmpty(struct stack *s){
    if (s->top == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct stack *s){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL){
        return 1;
    }
    return 0;
}

void push(struct stack *s, int value){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL){
        printf("Stack Overflow ! Cannot push anymore..\n");
    }
    else{
        n->data = value;
        n->next = s->top;
        s->top = n;
        printf("%d is pushed in stack\n", s->top->data);
    }
}

void pop(struct stack *s){
    if (s->top == NULL){
        printf("Stack Underflow ! Cannot pop anymore..\n");
    }
    else{
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n = s->top;
        s->top = s->top->next;
        printf("%d is popped from stack\n", n->data);
        free(n);
    }
}

void linked_List_Traverse(struct stack *s){
    struct node *temp = s->top;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = NULL;

    if (isEmpty(s))
        printf("Stack Underflow\n");
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);

    pop(s);
    pop(s);
    linked_List_Traverse(s);
    return 0;
}