#include <iostream>
using namespace std;
//Deletion of a node in a linked list
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

struct node *Deletion_1(struct node *head)
{ //Deletion at the beginning of linked list
    struct node *p = head;
    head = head->next;
    return head;
    delete (p);
}

struct node *Deletion_2(struct node *head, int NodeNum)
{ //Deletion in between of linked list
    struct node *p = head;
    struct node *p2 = head->next;
    int i = 0;
    while (i != (NodeNum - 2))
    {
        p = p->next;
        p2 = p2->next;
        i++;
    }
    p->next = p2->next;
    delete (p2);
    return head;
}

struct node *Deletion_3(struct node *head)
{ //Deletion at the end of the linked list
    struct node *ptr1 = head;
    struct node *ptr2 = head->next;

    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    delete (ptr2);
    return head;
}

struct node *Deletion_4(struct node *head, int value)
{ //Deletion of a node with a given specific value
    struct node *ptr1 = head;
    struct node *ptr2 = head->next;
    while (ptr2->data != (value))
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    delete (ptr2);
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = new (struct node);
    second = new (struct node);
    third = new (struct node);
    fourth = new (struct node);

    head->data = 34;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    linked_List_Traverse(head);
    // head = Deletion_1(head);//Deletion at the beginning of linked list
    // head = Deletion_2(head, 3);//Deletion in between of linked list
    head = Deletion_3(head);//Deletion at the end of the linked list
    // head = Deletion_4(head, 12); //Deletion of a node with a given specific value
    linked_List_Traverse(head);

    return 0;
}