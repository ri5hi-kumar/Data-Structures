#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head;

void displayList();
Node *getNewNode(int);
void insertSorted(int);

int main()
{
    head == NULL;
    insertSorted(45);
    insertSorted(2);
    insertSorted(54);
    insertSorted(2);
    insertSorted(47);
    insertSorted(1);
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
        temp = temp->next;
    }
    printf("\n");
}

Node *getNewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(int x)
{
    Node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        displayList();
        return;
    }
    Node *temp = head;
    if (x <= temp->data)
    {
        newNode->next = temp;
        head = newNode;
        displayList();
        return;
    }
    while (temp->next != NULL && temp->next->data < x)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    displayList();
}