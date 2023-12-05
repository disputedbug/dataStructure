// Program to find the maximum in a tree
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

int maxInTree(Node* root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->key, max(maxInTree(root->left), maxInTree(root->right)));
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

    int size = maxInTree(root);
    cout << "Max element of the tree is " << size << endl;
}
