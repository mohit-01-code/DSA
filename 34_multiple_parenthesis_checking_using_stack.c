#include <stdio.h>
#include <stdlib.h>
//Multiple Parenthesis cheking using stack
struct stack{
    int size;
    int top;
    char *arr;
};
void push(struct stack *s, char value){
    if (s->top == s->size)
        printf("Stack Overflow !!\n");
    else
        s->top++;
    s->arr[s->top] = value;
}
void pop(struct stack *s){
    s->top--;
}
int paranthesisMatch(struct stack *s, char *exp){
    for (int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(s, exp[i]);
        if (exp[i] == ')')
            if (s->top == -1)
                return 0;
            else if (s->arr[s->top] == '(')
                pop(s);
        if (exp[i] == '}')
            if (s->top == -1)
                return 0;
            else if (s->arr[s->top] == '{')
                pop(s);
        if (exp[i] == ']')
            if (s->top == -1)
                return 0;
            else if (s->arr[s->top] == '[')
                pop(s);
    }
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    char exp[s->size];
    printf("Enter an Expression : ");
    scanf("%s", &exp);

    if (paranthesisMatch(s, exp))
        printf("Balanced Expression ..Paranthesis are matching.\n");
    else
        printf("Unbalanced Expression ..Paranthesis are not matching.\n");
    return 0;
}