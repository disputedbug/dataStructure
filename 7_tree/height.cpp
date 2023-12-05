// Program to find the height of a binary Tree
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

void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int height(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return 1+ max(lHeight, rHeight);
}

int main()
{
    Node * root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);
    root->left->left->left = new Node(1);

    int h = height(root);
    cout << "Height of the tree is: " << h << endl;
}
