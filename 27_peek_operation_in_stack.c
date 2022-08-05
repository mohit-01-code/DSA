#include <stdio.h>
#include <stdlib.h>
//Peek operation in stack using array
struct stack{
    int size;
    int u_size;
    int top;
    int *arr;
};

void push(struct stack *s, int value){
    if (s->top == s->size){
        printf("Stack Overflow!! Cannot push anymore..\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
        s->u_size++;
    }
}

void pop(struct stack *s){
    if (s->top == -1){
        printf("Stack Underflow!! Cannot pop anymore..\n");
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        s->u_size--;
        printf("%d is popped from stack\n", val);
    }
}

int peek(struct stack *s, int p){
    int arrInd = s->top - p + 1;
    if (arrInd < 0){
        printf("Invalid positon..!\n");
    }
    else{
        return s->arr[arrInd];
    }
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->u_size = 0;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);

    pop(s);
    pop(s);

    for (int i = 1; i <= s->u_size; i++){
        printf("Element at position %d is : %d\n", i, peek(s, i));
    }

    return 0;
}