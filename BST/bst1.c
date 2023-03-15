// COMPLETE DELETE NODE FUNCTION // 
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node *root = NULL;

// creates a node
Node *getNewNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// prints tree in inorder
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d\t", root->data);
    inorderTraversal(root->right);
}

// inserts new node
void insertNode()
{
    Node *newNode = getNewNode();
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    Node *temp = root;
    Node *parentNode;

    while (temp != NULL)
    {
        parentNode = temp;
        temp = (newNode->data <= temp->data) ? (temp->left) : (temp->right);
    }
    if (newNode->data <= parentNode->data)
    {
        parentNode->left = newNode;
    }
    else
    {
        parentNode->right = newNode;
    }
}

// deletes the whole tree
void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    printf("<--Deleting Node-->\n");
    free(root);
}

// checks if a number is in tree or not
Node* isInTree(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x)
    {
        return root;
    }
    else if (x <= root->data)
    {
        isInTree(root->left, x);
    }
    else
    {
        isInTree(root->right, x);
    }
}

// finds height of the tree
int helper_for_getHeight(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
int getHeight(Node *root){
    if(root == NULL){
        return -1;
    }
    return 1 + helper_for_getHeight(getHeight(root->left), getHeight(root->right));
}

// finds minimum in a tree
int getMin(Node *root){
    if (root == NULL)
    {
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }

    return getMin(root->left);
}

// finds maximum in a tree
int getMax(Node *root){
    if (root == NULL)
    {
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    return getMax(root->right);
}

// checks if it is a BST or not
int isBST_helper(Node *root, int min, int max){
    if (root == NULL)
    {
        return 1;
    }
    if (root->data < min || root->data > max)
    {
        return 0;
    }
    return isBST_helper(root->left, min, root->data) && isBST_helper(root->right, root->data, max);
}
int isBST(Node *root){
    return isBST_helper(root, __WINT_MIN__, __INT_MAX__);
}


// inorder successor 
int inorderSuccessor(int x){
    Node *current = isInTree(root, x);
    if (current == NULL)
    {
        return -1;
    }
    if(current->right != NULL){
        return getMin(current->right);
    }
    else{
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor->data;
    }
}

// deleting a node
Node *findmax(Node *node)
{
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    else if (x < root->data) // finding x in left subtree
    {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data) // finding x in right subtree
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            Node *replacement = findmax(root->left);
            root->data = replacement->data;
            root->left = deleteNode(root->left, replacement->data);
        }
    }
    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        insertNode();
    }
    inorderTraversal(root);
    printf("\n");

    // deleteTree(root);
    // root = NULL;

    printf("Height of tree = %d\n", getHeight(root));
    printf("Minimum number in tree = %d\n", getMin(root));
    printf("Maximum number in tree = %d\n", getMax(root));
    printf("Tree is BST OR NOT = %d\n", isBST(root));

    printf("\n");

    int x;
    scanf("%d", &x);
    printf("Inorder successor of %d = %d\n", x, inorderSuccessor(x));
    
}