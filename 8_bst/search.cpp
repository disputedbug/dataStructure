// Program to find an element is a BST
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

bool search(Node* root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == val)
    {
        return true;
    }
    else if (root->key > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
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

    int num = 17;
    bool ret = search(root, num);

    cout << boolalpha << "Element " << num <<
            " found in tree: " << ret << endl;
}
