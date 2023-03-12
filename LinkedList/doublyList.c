#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *pre;
} Node;

Node *head;

void displayList();
void displayReverse();
Node *getNewNode(int x);
void insertNode(int, int);
void deleteNode(int);
void reverseList();

int main()
{
    head = NULL;
    insertNode(1, 1);
    insertNode(45, 1);
    insertNode(3, 2);
    insertNode(56, 4);
    // // displayList();
    // // displayReverse();
    // deleteNode(1);
    // deleteNode(3);
    reverseList();
    displayList();
    displayReverse();
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


void displayReverse()
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Reverse list is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->pre;
    }
    printf("\n");
}


Node *getNewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}


void insertNode(int x, int n)
{
    Node *newNode = getNewNode(x);
    if (n == 1)
    {
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head->pre = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // temp and temp2 are pointers to nodes b/w which newNode is to be inserted
    else
    {
        Node *temp = head;
        for (int i = 1; i < n - 1; i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->pre = temp;
        }
        else
        {
            Node *temp2 = temp->next;
            temp->next = newNode;
            temp2->pre = newNode;
            newNode->pre = temp;
            newNode->next = temp2;
        }
    }
    displayList();
}


void deleteNode(int n)
{
    Node *temp = head, *temp2;
    if (n == 1)
    {
        if (head == NULL)
        {
            printf("List is empty\n");
        }
        else
        {
            temp2 = temp->next;
            temp2->pre = NULL;
            head = temp2;
            free(temp);
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->pre;
        if (temp->next == NULL)
        {
            temp2->next = NULL;
            free(temp);
            // temp = NULL;
        }
        else
        {
            temp2->next = temp->next;
            temp->next->pre = temp2;
            free(temp);
            // temp = NULL;
        }
    }
    displayList();
}


void reverseList()
{
    Node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->pre = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->pre = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->pre;
    }
    head = ptr1;
}
