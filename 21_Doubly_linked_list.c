#include <stdio.h>
#include <stdlib.h>
//Doubly linked list
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void traverse(struct node *head)
{
    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        printf("%d ", *ptr);
        ptr = ptr->next;
    }
    printf("%d ", *ptr);

    while (ptr->prev != NULL)
    {
        printf("%d ", *ptr);
        ptr = ptr->prev;
    }
    printf("%d \n", *ptr);
}

struct node *insertion_1(struct node *head, int data)
{ //Insertion of node at head in doubly linked list
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    newNode->prev = NULL;
    return head;
}
struct node *insertion_2(struct node *head, int data)
{ //Insertion of node at end in doubly linked list
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL;
    return head;
}
struct node *insertion_3(struct node *head, float data, int index)
{ //Inserion of a node in between doubly linked list
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *ptr = head;
    struct node *ptr1 = head->next;
    for (int i = 0; i != index - 2; i++)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;

    newNode->next = ptr1;
    ptr1->prev = newNode;

    return head;
}
struct node *deletion_1(struct node *head)
{ //Deletion of a node at first in doubly linked list
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}
struct node *deletion_2(struct node *head)
{ //Deletion of a node at end in doubly linked list
    struct node *ptr = head;
    struct node *ptr1 = head->next;

    while (ptr1->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    ptr->next = NULL;
    free(ptr1);
    return head;
}
struct node *deletion_3(struct node *head, int index)
{ //Deletion of a node in between doubly linked list
    struct node *ptr = head;
    struct node *ptr1 = head->next;
    struct node *ptr2 = ptr1->next;
    for (int i = 0; i != index - 2; i++)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2;
    ptr2->prev = ptr;
    free(ptr1);
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 12;
    head->prev = NULL;
    head->next = second;

    second->data = 14;
    second->prev = head;
    second->next = third;

    third->data = 15;
    third->prev = second;
    third->next = fourth;

    fourth->data = 16;
    fourth->prev = third;
    fourth->next = NULL;

    traverse(head);
    head = insertion_1(head, 11); //Insertion at head
    traverse(head);
    head = insertion_2(head, 17); //Insertion at end
    traverse(head);
    head = insertion_3(head, 13, 3); //Insertion in between
    traverse(head);
    head = deletion_1(head); //Deletion at first
    traverse(head);
    head = deletion_2(head); //Deletion at end
    traverse(head);
    head = deletion_3(head, 2); //Deletion in between
    traverse(head);
    return 0;
}