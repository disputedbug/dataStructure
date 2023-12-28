// Program to find the least common ancestor of a tree
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

Node* lca(Node* root, int n1, int n2)
{
    if (root == NULL) return root;

    if (root->key == n1 || root->key == n2)
        return root;

    Node* l1 = lca(root->left, n1, n2);
    Node* l2 = lca(root->right, n1, n2);

    if (l1 != NULL && l2 != NULL)
        return root;

    if (l1 != NULL)
        return l1;
    else
        return l2;
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

    Node* res = lca(root, 1, 7);
    cout << "LCA of the nodes is: " << res->key << endl;
}
