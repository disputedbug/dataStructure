// Program to find the size of a tree
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

int sizeofTree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1+sizeofTree(root->left)+sizeofTree(root->right));
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

    int size = sizeofTree(root);
    cout << "Size of the tree is " << size << endl;
}
