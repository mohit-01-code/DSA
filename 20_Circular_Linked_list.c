#include <stdio.h>
#include <stdlib.h>
//Circular linked list
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head);
struct node *insertion_1(struct node *head, int data);            //Insertion at first
struct node *insertion_2(struct node *head, int data);            //Insertion at end
struct node *insertion_3(struct node *head, int data, int index); //Insertion in between
struct node *deletion_1(struct node *head);                       //Deletion at first
struct node *deletion_2(struct node *head);                       //Deletion at end
struct node *deletion_3(struct node *head, int index);            //Deletion in between

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

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = head;

    traverse(head);
    head = insertion_1(head, 10); //Insertion at first in Circular ll
    traverse(head);
    head = insertion_2(head, 16); //Insertion at end in Circular ll
    traverse(head);
    head = insertion_3(head, 13, 3); //Insertion at end in Circular ll
    traverse(head);
    head = deletion_1(head); //Deletion at first in Circular ll
    traverse(head);
    head = deletion_2(head); //Deletion at end in Circular ll
    traverse(head);
    head = deletion_3(head, 3); //Deletion at end in Circular ll
    traverse(head);
    return 0;
}
void traverse(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d ", *ptr);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
struct node *insertion_1(struct node *head, int data)
{ //Insertion at first in Circular ll
    struct node *ptr = head->next;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}
struct node *insertion_2(struct node *head, int data)
{ //Insertion at end in Circular ll
    struct node *ptr = head->next;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return head;
}
struct node *insertion_3(struct node *head, int data, int index)
{ //Insertion of s node in between circular ll
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *ptr1 = head;
    struct node *ptr2 = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    newNode->next = ptr1->next;
    ptr1->next = newNode;
    return head;
}
struct node *deletion_1(struct node *head)
{ //Deletion at first in circular ll
    struct node *ptr1 = head;
    struct node *ptr2 = head->next;
    while (ptr2->next != head)
    {
        ptr2 = ptr2->next;
    }
    head = head->next;
    free(ptr1);
    ptr2->next = head;
    return head;
}
struct node *deletion_2(struct node *head)
{ //Deletion at end in circular ll
    struct node *ptr1 = head;
    struct node *ptr2 = head->next;
    while (ptr2->next != head)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
    return head;
}
struct node *deletion_3(struct node *head, int index)
{ //Deletion of a node in between circular ll
    struct node *ptr = head;
    struct node *ptr2 = head->next;
    for (int i = 0; i < index - 2; i++)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next;
    free(ptr2);
    return head;
}