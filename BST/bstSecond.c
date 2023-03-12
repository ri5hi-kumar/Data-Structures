// This is only the recurrsive approch, to find the iterative approches of insert and search functions look into bstFirst
// This programme will add functions like finding MIN, MAX and HEIGHT of the BST and surves the purpose of revision

#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
} Node;

Node *getnewNode(int);
Node *insertNode(Node *, int);
int search_data(Node *, int);
int findMin(Node *);
int findMax(Node *);
int height_of_tree(Node *);

int main()
{
    Node *root = NULL;

    // inserting
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 5);
    root = insertNode(root, 8);
    root = insertNode(root, 7);
    root = insertNode(root, 9);

    // searching
    if (search_data(root, 2))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }

    // finding max
    printf("Max = %d\n", findMax(root));

    // finding min
    printf("Min = %d\n", findMin(root));

    // finding height
    printf("Height of the tree is = %d\n", height_of_tree(root));

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

Node *insertNode(Node *root, int x)
{
    if (root == NULL)
    {
        root = getnewNode(x);
    }
    else if (x <= root->data)
    {
        root->left = insertNode(root->left, x);
    }
    else
    {
        root->right = insertNode(root->right, x);
    }
    return root;
}

int search_data(Node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    if (x == root->data)
    {
        return 1;
    }
    else if (x <= root->data)
    {
        return search_data(root->left, x);
    }
    else
    {
        return search_data(root->right, x);
    }
}

int findMin(Node *root)
{
    if (root == NULL)
    {
        return -1; // -1 is returned in this case coz we know that all elements in BST are positive
    }

    // RECURRSIVE
    else if (root->left == NULL) // this is the exiting condition and also the condition which will give us the answer
    {
        return root->data;
    }
    return findMin(root->left); // recurrsion - giving the address of the left subtree

    // ITERATIVE
    // while (root->left != NULL)
    // {
    //     root = root->left;
    // }
    // return root->data;
}

int findMax(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return findMax(root->right);
}

// Finding Height
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height_of_tree(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
}
