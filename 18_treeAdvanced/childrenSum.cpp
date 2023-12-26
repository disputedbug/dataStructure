// Program to find if a tree has childrem sum property
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

bool childSumProp(Node* root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;
    if (root->left)
        sum += root->left->key;

    if (root->right)
    sum += root->right->key;

    return (sum == root->key &&
            childSumProp(root->left) &&
            childSumProp(root->right));
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
    bool ret = childSumProp(root);
    cout << boolalpha << "This tree has children sum property: " << ret << endl;
}
