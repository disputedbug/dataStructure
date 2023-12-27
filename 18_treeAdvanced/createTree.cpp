// Program to convert a bin-tree from in-order and pre-order traversal
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

int preIndex = 0;
Node* createTree(int in[], int pre[], int is, int ie)
{
    if (is > ie) return NULL;

    Node* root = new Node(pre[preIndex++]);

    int inIndex = 0;
    for (int i = is; i <= ie; i++)
    {
        if (root->key == in[i])
        {
            inIndex = i;
            break;
        }
    }
    root->left = createTree(in, pre, is, inIndex-1);
    root->right = createTree(in, pre, inIndex+1, ie);

    return root;
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
    int in[] = {40, 20, 60, 50, 70, 10, 80, 100, 30};
    int pre[] = {10, 20, 40, 50, 60, 70, 30, 80, 100};
    int len = sizeof(in)/sizeof(in[0]);

    Node * root = createTree(in, pre, 0, len-1);

    cout << "The tree:" << endl;
    levelByLine(root);
    cout << endl;
}
