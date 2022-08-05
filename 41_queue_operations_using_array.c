#include <stdio.h>
#include <stdlib.h>
//Queue Operstions using Array
struct queue{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct queue *q){
    if (q->r == q->f)
        return 1;
    return 0;
}
int isFull(struct queue *q){
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int value){
    if (isFull(q))
        printf("Queue overlfow !!\n");
    else{
        q->r++;
        q->arr[q->r] = value;
        printf("%d is enqueued in Queue\n", value);
    }
}

void dequeue(struct queue *q){
    if (isEmpty(q))
        printf("Queue is empty..!\n");
    else{
        q->f++;
        int temp = q->arr[q->f];
        printf("The dequeued element is %d\n", temp);
    }
}

int peek(struct queue *q, int pos){
    return q->arr[pos];
}

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 50;
    q->r = q->f = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);

    dequeue(q);
    dequeue(q);
    for (int i = q->f + 1, j = 1; i <= q->r; i++, j++)
        printf("Element at position %d is : %d\n", j, peek(q, i));

    return 0;
}