// Program to find the number of nodes in a complete bin tree
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

int countNodes(Node* root)
{
    int lh = 0, rh = 0;

    Node* curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }

    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }

    if (lh == rh)
    {
        return pow(2, lh) -1;
    }
    else
    {
        return (1+countNodes(root->left)+
                  countNodes(root->right));
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
    root->left->left->right = new Node(2);

    cout << "Line by Line traversal of a Tree is:" << endl;
    levelByLine(root);

    int ret = countNodes(root);
    cout << "Num of the nodes is: " << ret << endl;
}
