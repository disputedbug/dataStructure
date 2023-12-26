// Program to print the left side view of the tree
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

void leftView(Node* root)
{
    if (root == NULL) return;
    queue <Node*> q;
    q.push(root);

    while (q.empty() != true)
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node* curr = q.front();
            q.pop();

            if (i == 0)   cout << curr->key << endl;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

        }
    }
    return;
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

    cout << "Left view of the Binary-Tree is:" << endl;
    leftView(root);
    cout << endl;
}
