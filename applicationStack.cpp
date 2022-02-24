#include<iostream>
#include<stack>
using namespace std;

// Using c++ coz in c++ we don't have to implement (write code for) stack but can directly use it through "#include<stack>"

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *head;

void displayList()                  // prints the Linked List
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    printf("Linked List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void insert(int x, int n)           // This function inserts node in nth position of a linked list
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


void reverse(){                 //  This function reverses the linked list using stack
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    stack<Node *> S;
    // The above line is to make a stack which stores addreses of structure Node defined above(line 7)

    Node *temp = head;
    while (temp != NULL)
    {
        S.push(temp);           // pushes address of head first in the stack then till the last node
        temp = temp->link;
    }
    temp = S.top();             // This point temp = NULL and we fill it with the address of the last node
    head = temp;                // Make head to point at the last node
    S.pop();                    // removes address of last node(now first "head") from the stack
    while (!S.empty())
    {
        temp->link = S.top();   // assign link part of the new head the address of the second last node in first go
        S.pop();                // removes the address of the second last node from the stack
        temp = temp->link;      //  moves ahead
    }
    temp->link = NULL;          // points link part of the new last node to NULL
}

int main(){
    head == NULL;
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    reverse();
    displayList();
    return 0;
}
