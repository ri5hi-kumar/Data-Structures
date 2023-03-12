#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node
{
    int data;
    struct stack_node *next;
} Node;

Node *head;

void push(int);
void pop();
int top();
int isEmpty(Node *);

int main()
{
    head = NULL;
    pop();
    push(3);
    push(2);
    push(1);
    printf("Top of the stack is %d\n", top());
    pop();
    pop();
    pop();
    printf("%d\n", isEmpty(head));
    return 0;
}

void displayNode()
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    displayNode();
}

void pop()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    displayNode();
}

int top()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        return head->data;
    }
}

int isEmpty(Node *head)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}