#include <stdio.h>
#include <stdlib.h>
//Insertion in a linked list

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

struct node *Insertion_1(struct node *head, int data)
{ //Insertion of a node at the beginning of a linked list
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *Insertion_2(struct node *head, int data, int index)
{ //Insertion of a node in between the linked list
    struct node *NewNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i = 0;
    while (i != (index - 1))
    {
        ptr = ptr->next;
        i++;
    }
    NewNode->data = data;
    NewNode->next = ptr->next;
    ptr->next = NewNode;
    return head;
}

struct node *Insertion_3(struct node *head, struct node *pNode, int data)
{ //Insertion of a node after a given specific node in linked list
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = pNode->next;
    pNode->next = ptr;
    return head;
}

struct node *Insertion_4(struct node *head, int data)
{ //Insertion of a node at the end of the linked list
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
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

    head->data = 14;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 16;
    fourth->next = NULL;

    printf("\nThe linked list is : ");
    linked_List_Traverse(head);

    printf("\nCASE 1 : The linked list after insertion at the beginning : ");
    head = Insertion_1(head, 12); //Insertion of a node at the beginning of a linked list
    linked_List_Traverse(head);

    printf("\nCASE 2 : The linked list afte insertion in between : ");
    head = Insertion_2(head, 43, 3); //Insertion of a node in between the linked list
    linked_List_Traverse(head);

    printf("\nCASE 3 : The linked list after insertion after a specific node : ");
    head = Insertion_3(head, second, 67); //Insertion of a node after a given specific node in linked list
    linked_List_Traverse(head);

    printf("\nCASE 4 : The linked list after insertion at the end : ");
    head = Insertion_4(head, 89); //Insertion of a node at the end of the linked list
    linked_List_Traverse(head);
    return 0;
}