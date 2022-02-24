//  insert, display, delete, reverse_iterative, reverse_recurrsive, Display_reverse_recurrsive

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *head;

void displayList();
void insert(int, int);
void delete (int);
void reverse_iterative();
void display_reverse(Node *);
void reverse_recurrsive(Node *);
void deleteList();

int main()
{
    head = NULL;
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(45, 2);
    delete (4);
    insert(43, 1);
    reverse_iterative();
    reverse_recurrsive(head);
    displayList();
    void deleteList();
    displayList();
    return 0;
}

void displayList()
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void insert(int x, int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->link = NULL;
    if (n == 1) // n = poistion
    {
        newNode->link = head;
        head = newNode;
        displayList();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < n - 1; i++)
    {
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    displayList();
}

void delete(int n)
{
    Node *current = head;
    if (n == 1)
    {
        head = current->link;
        free(current);
        displayList();
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        current = current->link;
    }
    Node *temp = current->link;
    current->link = temp->link;
    free(temp);
    displayList();
}

void reverse_iterative()
{
    Node *current, *next, *pre;
    current = head;
    pre = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = pre;
        pre = current;
        current = next;
    }
    head = pre;
    displayList();
}

void display_reverse(Node *head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        display_reverse(temp->link);
        printf(" %d", temp->data);
    }
    else
    {
        printf("\n");
        return;
    }
}

void reverse_recurrsive(Node *p)
{
    if (p->link == NULL)
    {
        head = p;
        return;
    }
    reverse_recurrsive(p->link);
    Node *q = p->link;
    q->link = p;
    p->link = NULL;
}

void deleteList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
}
