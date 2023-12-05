// Level order traversal of a bin tree
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

void levelOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    queue <Node*> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node* curr = q.front();
        q.pop();

        cout << curr->key << " ";
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
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

    levelOrder(root);
    cout << endl;
}
