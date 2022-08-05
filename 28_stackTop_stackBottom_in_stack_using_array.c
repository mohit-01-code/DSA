#include <stdio.h>
#include <stdlib.h>
//stackTop and stackBottom operations in stack using array
struct stack{
    int size;
    int u_size;
    int top;
    int *arr;
};

void push(struct stack *s, int value){
    if (s->top == s->size){
        printf("Stack Overflow! Cannot push anymore..\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
        s->u_size++;
    }
}

void pop(struct stack *s){
    if (s->top == -1){
        printf("Stack Underflow! Cannot pop anymore..\n");
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        s->u_size--;
        printf("%d is popped from stack\n", val);
    }
}

int top(struct stack *s){
    return s->arr[s->top];
}

int bottom(struct stack *s){
    return s->arr[0];
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->u_size = 0;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));

    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);

    printf("The Top element in stack is : %d\n", top(s));
    printf("The Bottom element in stack is : %d\n", bottom(s));
   
    pop(s);
    return 0;
}