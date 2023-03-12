#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

Node *getnewNode(int);
void enqueue(int);
int dequeue();
void displayQueue();


int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    int i = dequeue();
    i = dequeue();
    i = dequeue();
    return 0;
}


void displayQueue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


Node *getnewNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}


void enqueue(int x)
{
    Node *newnode = getnewNode(x);
    if (rear == NULL && front == NULL)
    {
        front = rear = newnode;
        displayQueue();
        return;
    }
    rear->next = newnode;
    rear = newnode;
    displayQueue();
}


int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        Node *temp = front->next;
        free(front);
        front = temp;
    }
    displayQueue();
}
