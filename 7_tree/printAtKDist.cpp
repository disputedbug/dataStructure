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

void printKDist(Node* root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->key << " ";
        return;
    }
    printKDist(root->left, k-1);
    printKDist(root->right, k-1);
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

    printKDist(root, 2);

    cout << endl;
}
