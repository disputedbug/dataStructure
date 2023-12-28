// Program to find the vertical sum of the nodes in a bin tree
#include <iostream>
#include <map>
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

void vSumR(Node* root, int hd, map <int, int>& mp)
{
    if (root == NULL)
        return;

    vSumR(root->left, hd-1, mp);
    mp[hd] += root->key;
    vSumR(root->right, hd+1, mp);
}

void vSum(Node* root)
{
    map <int, int> mp;
    vSumR(root, 0, mp);

    for (auto item: mp)
        cout << item.second << " ";

    cout << endl;
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
    vSum(root);

}
