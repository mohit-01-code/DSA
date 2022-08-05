#include <stdio.h>
#include <stdlib.h>
//Linked list creation and deletion

struct node
{
    int data;
    struct node *next;
};

void linked_List_Traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", *head);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 34;
    head->next = first;

    first->data = 0;
    first->next = second;

    second->data = 21;
    second->next = third;

    third->data = 65;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = NULL;

    linked_List_Traverse(head);
    return 0;
}