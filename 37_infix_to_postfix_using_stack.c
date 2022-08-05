#include <stdio.h>
#include <stdlib.h>
//Infix to Postfix conversion using stack
struct stack{
    int size;
    int top;
    char arr[];
};

void push(struct stack *s, char value){
    if (s->top == s->size)
        printf("Stack Overflow ! Cannot push anymore..\n");
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop(struct stack *s){
    char temp = s->arr[s->top];
    s->top--;
    return temp;
}

int precedence(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

char *conversion(struct stack *s, char *infix){
    char *postfix = (char *)malloc(s->size * sizeof(char));
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            if (precedence(infix[i]) > precedence(s->arr[s->top]))
                push(s, infix[i]);
            else{
                postfix[j] = pop(s);
                j++;
                push(s, infix[i]);
            }
        }
        else{
            postfix[j] = infix[i];
            j++;
        }
    }
    while (s->top != -1){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    char *arr = (char *)malloc(s->size * sizeof(char));

    char infix[50];
    printf("Enter an Infix expression : ");
    scanf("%s", &infix);
    printf("The Postfix expression is : %s\n", conversion(s, infix));
    return 0;
}