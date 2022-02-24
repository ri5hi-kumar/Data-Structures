// This is for DELEATING a node from the tree

#include <iostream>
using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};


bstNode *getNewNode(int x)
{
    bstNode *newNode = new bstNode;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


bstNode *insertNode(bstNode *root, int x)
{
    if (root == NULL)
    {
        root = getNewNode(x);
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


void inOrderTrans(bstNode *root)    // to check if the node is deleted or not
{ 
    if (root == NULL)
    {
        return;
    }
    inOrderTrans(root->left);
    cout << root->data << " ";
    inOrderTrans(root->right);
}






bstNode *findmax(bstNode *node)
{                               // fuction finding max in the left subtree, we can implement a similar function to find
    while (node->right != NULL) // min in right subtree
    {
        node = node->right;
    }
    return node;
}
// function for deleting a node form the BST
bstNode *deleteNode(bstNode *root, int x)
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
    else // found the node of x
    {
        // case 1: x is data of a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // case 2: if x is data of a node which have only left or right child
        else if (root->left == NULL)
        {
            bstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            bstNode *temp = root;
            root = root->left;
            delete temp;
        }

        // case 3: if x is the data of a node which have both left and right childeren
        /* In this case we will either find max in the left subtree or min in the right tree and then put it equal to root->data
        and then case can be reduced to deleting the max and min element that we put in the deleted node's place */
        else
        {
            bstNode *replacement = findmax(root->left); // findmax will find min in left subtree of node to be deleted
            root->data = replacement->data;
            root->left = deleteNode(root->left, replacement->data);
        } 
    }
    return root;
}





int main()
{
    bstNode *root = NULL;
    root = insertNode(root, 21);
    root = insertNode(root, 17);
    root = insertNode(root, 25);
    root = insertNode(root, 16);
    root = insertNode(root, 18);
    root = insertNode(root, 23);
    root = insertNode(root, 31);
    inOrderTrans(root);
    cout << "\n";

    root = deleteNode(root, 25);

    inOrderTrans(root);
    cout << "\n";
    return 0;
}