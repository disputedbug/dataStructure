// Program to traverse a tree in zig-zag order
#include <iostream>
#include <stack>
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

void zigzagOrder(Node* root)
{
    if (root == NULL) return;
    stack <Node*> s1;
    stack <Node*> s2;
    s1.push(root);

    while (s1.empty() != true || s2.empty() != true)
    {
        while (s1.empty() != true)
        {
            Node* curr = s1.top();
            s1.pop();
            cout << curr->key << " ";
            if (curr->left) s2.push(curr->left);
            if (curr->right) s2.push(curr->right);
        }
        while (s2.empty() != true)
        {
            Node* curr = s2.top();
            s2.pop();
            cout << curr->key << " ";
            if (curr->right) s1.push(curr->right);
            if (curr->left) s1.push(curr->left);
        }
    }
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
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);
    root->left->left->left = new Node(1);

    cout << "Line by Line traversal of a Tree is:" << endl;
    levelByLine(root);

    cout << "Zigzag traversal of a Tree is:" << endl;
    zigzagOrder(root);
    cout << endl;
}
