#include <stdio.h>
#include <stdlib.h>
//Circular Queue and Operations on circular using Array
struct Queue{
    int size;
    int r;
    int f;
    int *arr;
};
void enqueue(struct Queue *q, int value){
    if ((q->r + 1) % q->size == q->f)
        printf("Queue is full !\n");
    else{
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
        printf("%d is Enqueued in Circular queue.\n", value);
    }
}
void dequeue(struct Queue *q){
    if (q->r == q->f)
        printf("Queue is empty !\n");
    else{
        q->f = (q->f + 1) % q->size;
        printf("The dequeued element is %d\n", q->arr[q->f]);
    }
}
int peek(struct Queue *q, int pos){
    return q->arr[pos];
}
int main(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 5;
    q->r = q->f = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 15);
    enqueue(q, 16);

    dequeue(q);
    dequeue(q);
    enqueue(q, 16);
    enqueue(q, 17);
    enqueue(q, 18);

    for (int i = (q->f + 1) % q->size, j = 1; i != (q->r + 1) % q->size; i = (i + 1) % q->size, j++)
        printf("Element at position %d is : %d\n", j, peek(q, i));

    return 0;
}