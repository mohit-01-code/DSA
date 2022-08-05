#include <stdio.h>
#include <stdlib.h>
//Stack using an array

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
void CreateStack(struct stack *ptr){
    for (int i = 0; i < ptr->size; i++){
        printf("Enter the element in stack at index %d : ", i);
        scanf("%d", &ptr->arr[i]);
        ptr->top++;
    }
    printf("\n");
}
void displayStack(struct stack *ptr){
    for (int i = 0; i < ptr->size; i++){
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before creating array\n");
    if (isEmpty(s)){
        printf("Stack is empty..!\n");
    }
    else{
        printf("Stack is not empty\n");
    }

    CreateStack(s);
    displayStack(s);

    printf("After creating array\n");
    if (isFull(s)){
        printf("Stack is full..!\n");
    }
    else{
        printf("Stack is not full\n");
    }

    return 0;
}