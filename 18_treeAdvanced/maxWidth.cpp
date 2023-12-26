// Program to find the maximum width of a Binary tree
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

int maxWidth(Node* root)
{
    if (root == NULL)
        return 0;

    queue <Node*> q;
    q.push(root);
    int ret = 0;

    while (q.empty() != true)
    {
        int num = q.size();
        ret = max(ret, num);

        for (int i = 0; i < num; i++)
        {
            Node* curr = q.front();
            q.pop();

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return ret;
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
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(4);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(1);

    levelByLine(root);
    int ret = maxWidth(root);
    cout << "The max width of the tree is: " << ret << endl;
}
