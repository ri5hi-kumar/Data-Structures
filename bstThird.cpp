/* In this programme we are traversing a BST through "Level Order Traversal" and "Pre Post and In order Traversal". For Level Order Traversal
we use QUEUE so we are writting code in C++ as queues are already implemented in it but we need to implement a BST */

#include <iostream>
#include <queue>
using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *getnewNode(int);
bstNode *insertNode(bstNode *, int);
void levelOrderTreversal(bstNode *);
void preOrderTreversal(bstNode *);
void inOrderTreversal(bstNode *);
void postOrderTreversal(bstNode *);
bool isBST(bstNode *);

int main()
{
    bstNode *root = NULL;
    root = insertNode(root, 25);
    root = insertNode(root, 21);
    root = insertNode(root, 26);
    root = insertNode(root, 29);
    root = insertNode(root, 20);
    root = insertNode(root, 24);
    // levelOrderTreversal(root);
    // preOrderTreversal(root);
    inOrderTreversal(root);
    cout << "\n";
    cout<<isBST(root);
    cout << "\n";
    return 0;
}

bstNode *getnewNode(int x)
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

// this is the fuction for the level order treversal
void levelOrderTreversal(bstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    queue<bstNode *> Q; // creating a QUEUE with datatype of pointer to bstNode
    Q.push(root);       // pusing the address of root node
    while (!Q.empty())
    {
        bstNode *current = Q.front(); // getting address of root node in "current" from front of the queue
        cout << current->data << " "; // printing data of current node
        if (current->left != NULL)
        {
            Q.push(current->left); // pushing address of left node at last
        }
        if (current->right != NULL)
        {
            Q.push(current->right); // pushing address of right node at last
        }
        Q.pop(); /* poping the address which went first in that means root for the first run and now queue contains address of
                 root.left and root.right from which the root.left which is first in queue becomes current and we checks if for
                 the left and right root of the new current if any pushed cycle goes on.......... */
    }
    cout << "\n";
}

/* these functions do have space complexity and it is dependent on the height of the tree so the tree must be balanced tree to get
faster results. The space complexity is due to the reason that the function is a recurrsive function and fill up the "stack" during
succesive calls */
void preOrderTreversal(bstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTreversal(root->left);
    preOrderTreversal(root->right);
}

void inOrderTreversal(bstNode *root) // inorder traversal prints the binary search tree in a sorted order
{
    if (root == NULL)
    {
        return;
    }
    inOrderTreversal(root->left);
    cout << root->data << " ";
    inOrderTreversal(root->right);
}

void postOrderTreversal(bstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTreversal(root->left);
    cout << root->data << " ";
    postOrderTreversal(root->right);
}

/* These functions return true if the tree is a BST and false if not */
bool isBSTUTIL(bstNode *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    return isBSTUTIL(root->left, min, root->data) && isBSTUTIL(root->right, root->data, max);
}
bool isBST(bstNode *root){
    return isBSTUTIL(root, INT16_MIN, INT16_MAX);
}