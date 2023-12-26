// Program to find if a tree is balanced (min-max height diff of 1)
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

int isBalanced(Node* root)
{
    if (root == NULL)
        return 0;

    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);

    int ret = 0;

    if (lh == -1 || rh == -1 || abs(lh-rh) > 1)
        ret = -1;
    else
        ret = 1+ max(lh, rh);

    return ret;
}

bool isBalancedTop(Node* root)
{
    if (isBalanced(root) < 0)
        return false;
    return true;
}

bool isBalancedNaive(Node* root)
{
    if (isBalanced(root) < 0)
        return false;
    return true;
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
    root->left->left->left->left = new Node(1);

    levelByLine(root);
    bool ret = isBalancedTop(root);
    cout << boolalpha << "This tree is balanced: " << ret << endl;
}
