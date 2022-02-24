// Checking for balanced paranthess

/* all this shit could have been done in c++ pretty easily
and yet I decided to fuck myself by writting all this stack
code and fuctions */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_node
{
    char data;
    struct stack_node *next;
} Node;

Node *head;

void push(char);
char pop();
int top();
int isEmpty(Node *);
int checkBalancedParanthess(char *);        // This much part is important

int main()
{
    char string[10];
    int i;
    fgets(string, sizeof(string), stdin);
    if (checkBalancedParanthess(string))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }
    return 0;
}

void displayStack()
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
        printf(" %c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(char x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

char pop()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        Node *temp = head;
        head = head->next;
        return temp->data;
    }
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
        return 1;
    }
    else
    {
        return 0;
    }
}

// This function checks for the balanced paranthess in a string
// This much part is important

int matching(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int checkBalancedParanthess(char *s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i]);
        }
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (isEmpty(head))
            {
                return 0;
            }
            else if (!matching(pop(), s[i]))
            {
                return 0;
            }
            
        }
    }
    return isEmpty(head);
}
