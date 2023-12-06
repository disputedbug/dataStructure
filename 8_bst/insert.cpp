// Program to insert an element in a BST
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    else if (root->key < val)
    {
        root->right = insert(root->right, val);
    }
    else if (root->key > val)
    {
        root->left = insert(root->left, val);
    }
    return root;
}

Node* insertIter(Node* root, int val)
{
    Node* temp = new Node(val);

    Node* curr = root;
    Node* parent = NULL;

    while (curr!=NULL)
    {
        parent = curr;
        if (curr->key < val)
        {
            curr = curr->right;
        }
        else if (curr->key > val)
        {
            curr = curr->left;
        }
        else
        {
            return root;
        }
    }
    if (parent == NULL)
    {
        return temp;
    }
    if (parent->key > val)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }
    return root;
}

void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node * root = new Node(10);

    int arr[] = {10, 5, 15, 2, 7, 12, 17};
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        root = insertIter(root, arr[i]);
    }

    inOrder(root);

    cout << endl;
}
