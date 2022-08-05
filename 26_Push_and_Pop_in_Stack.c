#include <stdio.h>
#include <stdlib.h>
//Push and Pop operation on stack using array
struct stack{
    int size;
    int u_size;
    int top;
    int *arr;
};

int is_empty(struct stack *s){
    if (s->top == -1){
        return 1;
    }
    return 0;
}

int is_full(struct stack *s){
    if (s->top >= s->size - 1){
        return 1;
    }
    return 0;
}

void create_stack(struct stack *s){
    s->u_size = 6;
    printf("Enter the element in stack : \n");
    for (int i = 0; i < s->u_size; i++){
        scanf("%d", &s->arr[i]);
        s->top++;
    }
}

void push(struct stack *s, int value){
    if (is_full(s)){
        printf("Stack Overflow !! Cannot push anymore\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
        s->u_size++;
    }
}

void pop(struct stack *s){
    if (is_empty(s)){
        printf("Stack Underflow !! Cannot pop anymore...\n");
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        s->u_size--;
        printf("%d is popped from stack.\n", val);
    }
}

void display_stack(struct stack *s){
    if (is_empty(s)){
        printf("Stack Underflow\n");
    }
    else{
        printf("Elements in stack is : \n");
        for (int i = 0; i < s->u_size; i++)
        {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->u_size = 0;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    create_stack(s);
    display_stack(s);

    push(s, 12);
    push(s, 13);
    display_stack(s);
    
    pop(s);
    pop(s);
    
    display_stack(s);
    return 0;
}