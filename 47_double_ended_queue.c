#include <stdio.h>
#include <stdlib.h>
//Double Ended Queue and its operation using Array
struct Queue{
    int size;
    int r, f;
    int *arr;
};
int isFull(struct Queue *q){
    if (q->r == q->size - 1)
        return 1;
    return 0;
}
int isEmpty(struct Queue *q){
    if (q->r == q->f)
        return 1;
    return 0;
}
void enqueueR(struct Queue *q, int value){
    if (isFull(q))
        printf("Queue is Full !\n");
    else{
        q->r++;
        q->arr[q->r] = value;
        printf("%d is Enqueued at Rear\n", value);
    }
}
void enqueueF(struct Queue *q, int value){
    if (q->f == -1)
        printf("Queue is full at Front ! Insert at Rear.\n");
    else{
        q->arr[q->f] = value;
        q->f--;
        printf("%d is Enqueued at Front\n", value);
    }
}
void dequeueF(struct Queue *q){
    if (isEmpty(q))
        printf("Queue is Empty\n");
    else{
        q->f++;
        printf("The Dequeued element from Front is %d\n", q->arr[q->f]);
    }
}
void dequeueR(struct Queue *q){
    if (isEmpty(q))
        printf("Queue is empty\n");
    else{
        printf("The dequeued element from Rear is %d\n", q->arr[q->r]);
        q->r--;
    }
}
int peek(struct Queue *q, int pos){
    return q->arr[pos];
}
void display_arr(struct Queue *q){     
       for (int i = q->f + 1; i <= q->r; i++)
        printf("%d ", peek(q, i));
    printf("\n\n");
}
int main(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 50;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueR(q, 4);
    enqueueR(q, 5);
    enqueueR(q, 6);
    enqueueR(q, 7);
    enqueueR(q, 8);
    enqueueR(q, 9);
    display_arr(q);

    dequeueF(q);
    dequeueF(q);
    display_arr(q);

    enqueueF(q, 3);
    enqueueF(q, 2);
    display_arr(q);

    dequeueR(q);
    dequeueR(q);
    display_arr(q);

    for (int i = q->f + 1, j = 1; i <= q->r; i++, j++)
        printf("The element at position %d is %d\n", j, peek(q, i));
    return 0;
}