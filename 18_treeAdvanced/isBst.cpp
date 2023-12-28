// Program to find if a tree is a BST
#include <iostream>
#include <queue>
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

// Inorder traversal method
bool isBst(Node* root, int &previous)
{
    if (root == NULL)
        return true;

    if (isBst(root->left, previous) == false)
        return false;

    if (root->key < previous)
        return false;

    previous = root->key;

    return isBst(root->right, previous);
}

// Range check method
bool isBst2(Node* root, int min, int max)
{
    if (root == NULL)
        return true;

    return (root->key > min &&
            root->key < max &&
            isBst2(root->left, min, root->key) &&
            isBst2(root->right, root->key, max));
}

void levelByLine(Node* root)
{
    if (root == NULL)
        return;
    queue <Node*> q;
    q.push(root);

    while (q.empty() != true)
    {
        int num = q.size();

        for (int i = 0; i < num; i++)
        {
            Node* curr = q.front();
            q.pop();

            cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
    return;
}

int main()
{
    Node * root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(21);

    levelByLine(root);
    int previous = INT_MIN;
    //bool ret = isBst(root, previous);
    bool ret = isBst2(root, INT_MIN, INT_MAX);
    cout << boolalpha << "This tree is BST: " << ret << endl;
}
