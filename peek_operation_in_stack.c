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
    if (s->top == s->size - 1){
        printf("Stack Overflow !! Cannot push anymore..\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
        s->u_size++;
    }
}

void pop(struct stack *s){
    if (s->top == -1){
        printf("Stack Underflow!! cannnot pop anymore..\n");
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        printf("%d is popped from stack\n", val);
        s->u_size--;
    }
}

int get_index(struct stack *s, int value){
    for (int i = 0; i < s->u_size; i++){
        if (s->arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void peek(struct stack *s, int value){
    int index = get_index(s, value);
    if (index == -1){
        printf("%d Element not found in stack\n", value);
    }
    else{
        printf("%d is at index : %d\n", value, index);
    }
}

void display(struct stack *s){
    if (s->top == -1){
        printf("Stack Underflow!! cannnot display elements..\n");
    }
    else{
        printf("Elements in stack are : \n");
        for (int i = 0; i < s->u_size; i++){
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->u_size = 0;
    s->arr = (int *)malloc(s->size * sizeof(int));

    for (int i = 0; i <= 10; i = i + 2){
        push(s, i);
    }
    display(s);

    // push(s, 4);
    // push(s, 7);
    // push(s, 6);
    // push(s, 5);
    peek(s, 10);
    pop(s);
    display(s);

    peek(s, 10);

    return 0;
}