#include <stdio.h>
#include <stdlib.h>
//Implementation of Queue using Linked list
struct node{
    int data;
    struct node *next;
};
struct Queue{
    int u_size;
    struct node *r;
    struct node *f;
};
void enqueue(struct Queue *q, int value){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        printf("Queue is full !");
    else
    {
        n->data = value;
        n->next = NULL;
        if (q->f == NULL)
            q->r = q->f = n;
        else{
            q->r->next = n;
            q->r = n;
        }
        printf("%d is Enqueued in Queue.\n", n->data);
        q->u_size++;
    }
}
void dequeue(struct Queue *q){
    if (q->f == NULL)
        printf("Queue is Empty !\n");
    else
    {
        struct node *temp = q->f;
        q->f = q->f->next;
        printf("The Dequeued element is %d\n", temp->data);
        q->u_size--;
    }
}
int peek(struct Queue *q, int pos){
    struct node *ptr = q->f;
    for (int i = 1; i != pos; i++)
        ptr = ptr->next;
    return ptr->data;
}
int main(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = q->r = NULL;
    q->u_size = 0;

    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);

    dequeue(q);
    dequeue(q);
    for (int i = 1; i <= q->u_size; i++)
        printf("The element at position %d is %d\n", i, peek(q, i));
    return 0;
}