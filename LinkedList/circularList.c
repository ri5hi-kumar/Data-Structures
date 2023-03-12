// insertion, deletion, display
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *tail;
int count;

Node *getNewNode(int);
void displayList();
void insertEmpty(int);
void insertStart(int);
void insertEnd(int);
void insertNth(int, int);
int counting(Node *);
void deleteNode(int);
int findElement(int);

int main()
{
    tail = NULL;
    insertEmpty(1);
    insertStart(45);
    insertStart(78);
    insertEnd(67);
    insertEnd(69);
    insertNth(2, 2);
    insertNth(3, 3);
    // count = counting(tail);
    // printf("Number of elements in List is = %d\n", count);
    // deleteNode(7);
    int index = findElement(67);
    printf("element is on the index = %d\n", index);
    return 0;
}

Node *getNewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->link = NULL;
    return newNode;
}

void displayList()
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *p = tail->link;
    printf("List is: ");
    do
    {
        printf(" %d", p->data);
        p = p->link;
    } while (p != tail->link);
    printf("\n");
}

void insertEmpty(int x)
{
    Node *newNode = getNewNode(x);
    tail = newNode;
    newNode->link = newNode;
    displayList();
}

void insertStart(int x)
{
    Node *newNode = getNewNode(x);
    newNode->link = tail->link;
    tail->link = newNode;
    displayList();
}

void insertEnd(int x)
{
    Node *newNode = getNewNode(x);
    newNode->link = tail->link;
    tail->link = newNode;
    tail = newNode;
    displayList();
}

void insertNth(int x, int n)
{
    Node *newNode = getNewNode(x);
    Node *p = tail->link;
    for (int i = 1; i < n - 1; i++)
    {
        p = p->link;
    }
    newNode->link = p->link;
    p->link = newNode;
    displayList();
}

int counting(Node *tail)
{
    Node *p = tail->link;
    do
    {
        count++;
        p = p->link;
    } while (p != tail->link);
    return count;
}

void deleteNode(int n)
{
    Node *p = tail->link;
    if (n == 1)
    {
        if (tail == NULL)
        {
            printf("List is empty\n");
        }
        else
        {
            Node *temp = p->link;
            tail->link = temp;
            free(p);
        }
    }
    else
    {
        for (int i = 1; i < n - 1; i++)
        {
            p = p->link;
        }
        if (p->link == tail)
        {
            p->link = tail->link;
            free(tail);
            tail = p;
        }
        else
        {
            Node *temp = p->link;
            p->link = temp->link;
            free(temp);
        }
    }
    displayList();
}

int findElement(int x)
{
    int index = 0;
    Node *temp = tail->link;
    do
    {
        if (x == temp->data)
        {
            return index;
        }
        temp = temp->link;
        index++;
    } while (temp != tail->link);
    return -1;
}