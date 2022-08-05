#include <stdio.h>
#include <stdlib.h>
//Peek(), StackTop() and Other oprarions on stack using linked list
struct node{
    int data;
    struct node *next;
};
struct stack{
    struct node *top;
    int u_size;
};
void push(struct stack *s, int value){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        printf("Stack overflow ! cannot push anymore..\n");
    else{
        n->data = value;
        n->next = s->top;
        s->top = n;
        s->u_size++;
    }
}
void pop(struct stack *s){
    if (s->top == NULL)
        printf("Stack underflow ! Cannot pop anymore..\n");
    else{
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n = s->top;
        s->top = s->top->next;
        printf("%d is popped from stack\n", n->data);
        free(n);
        s->u_size--;
    }
}
int peek(struct stack *s, int pos){
    if (s->top == NULL){
        printf("Stack Underflow !\n");
        return -1;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = s->top;
    for (int i = 1; (i < pos && ptr != NULL); i++)
        ptr = ptr->next;
    return ptr->data;
}
int top(struct stack *s){
    return s->top->data;
}
int bottom(struct stack *s){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = s->top;
    for (int i = 0; ptr->next != NULL; i++)
        ptr = ptr->next;
    return ptr->data;
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->u_size = 0;
    s->top = NULL;

    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);

    for (int i = 1; i <= s->u_size; i++)
        printf("The value at position %d is : %d\n", i, peek(s, i));

    pop(s);
    pop(s);

    if (s->top != NULL){
        printf("The top most element in stack is : %d\n", top(s));
        printf("The bottom most element in stack is : %d\n", bottom(s));
    }
    return 0;
}