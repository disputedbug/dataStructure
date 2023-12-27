// Program to find the diameter of a tree
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

int ret = 0;
int diameterTree(Node* root)
{
    if (root == NULL) return 0;
    int lHeight = diameterTree(root->left);
    int rHeight = diameterTree(root->right);

    ret = max (ret, 1+lHeight+rHeight);

    return (1+max(lHeight, rHeight));
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

    int res = diameterTree(root);
    cout << "Diameter of the Tree is: " << ret << endl;
}
