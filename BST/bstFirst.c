#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
} Node;

Node *getnewNode(int);
void insert_recurrsive(Node **, int);
void insert_iterative(Node **, int);
int search_recurrsive(Node *, int);
int search_iterative(Node *, int);

int main()
{
    Node *root = NULL;
    // insert_recurrsive(&root, 25);
    // insert_recurrsive(&root, 23);
    // insert_recurrsive(&root, 27);
    // insert_recurrsive(&root, 13);
    // insert_recurrsive(&root, 28);
    // insert_recurrsive(&root, 45);
    // printf("%d\n", search_recurrsive(root, 45));

    insert_iterative(&root, 25);
    insert_iterative(&root, 23);
    insert_iterative(&root, 27);
    insert_iterative(&root, 13);
    insert_iterative(&root, 28);
    insert_iterative(&root, 45);
    printf("%d\n", search_iterative(root, 93));
    return 0;
}

Node *getnewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert_recurrsive(Node **rootptr, int x) // rootptr is a pointer to pointer so we have to derefrence it while using
{
    /* no need to create a temproary pointer for *rootptr i.e root coz it is a recurrsive approch and only address is gone
    in the function */
    if (*rootptr == NULL)
    {
        *rootptr = getnewNode(x); // if *rootptr i.e root is NULL just put the address of newNode in root
    }
    else if (x <= (*rootptr)->data) // goes in left subtree
    {
        insert_recurrsive(&(*rootptr)->left, x); // gives the address of the first left subtree to the function
    }
    else // goes into right subtree
    {
        insert_recurrsive(&(*rootptr)->right, x); // gives the address of the first right subtree to the function
    }
}

void insert_iterative(Node **rootptr, int x)
{
    Node *newNode = getnewNode(x); // making a new node
    if (*rootptr == NULL)          // if *rootptr i.e root is NULL then put the address of newNode in root
    {
        *rootptr = newNode;
        return;
    }
    Node *temp_root;         // tempoerory Node pointer
    temp_root = *rootptr;    // puting value of *rootptr i.e root in tempoerory pointer so we have no need to derefrence temp_root
    Node *parentNode = NULL; // we are using another pointer so that we don't have to use two while loops

    while (temp_root != NULL)
    {
        parentNode = temp_root; // stores value of temp_root before it becomes NULL and can be used in next if-else ledder
        temp_root = (x <= temp_root->data) ? temp_root->left : temp_root->right;
    }
    if (x <= parentNode->data) // using parentNode coz temp_root is NULL and is equal to parentNode->left
    {
        parentNode->left = newNode;
    }
    else
    {
        parentNode->right = newNode;
    }
}

int search_recurrsive(Node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (x == root->data)
    {
        return 1;
    }
    else if (x <= root->data)
    {
        search_recurrsive(root->left, x);
    }
    else
    {
        search_recurrsive(root->right, x);
    }
}

int search_iterative(Node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    Node *temp_root = root, *parentNode = NULL;
    if (temp_root->data == x)
    {
        return 1;
    }
    while (temp_root != NULL)
    {
        parentNode = temp_root;
        temp_root = (x <= temp_root->data) ? temp_root->left : temp_root->right;
    }
    if (parentNode->data == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}