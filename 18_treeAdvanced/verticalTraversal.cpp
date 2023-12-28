// Program to find the vertical traversal of a binary tree
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

void vTraversal(Node* root)
{
    map <int, vector<int> > mp;
    queue <pair<Node*, int> > q;
    pair<Node*, int> p;

    q.push(make_pair(root, 0));
    while (q.empty() != true)
    {
        auto item = q.front();
        Node* curr = item.first;
        int hd = item.second;
        mp[hd].push_back(curr->key);
        q.pop();

        if (curr->left)
        {
            q.push(make_pair(curr->left, hd-1));
        }
        if (curr->right)
        {
            q.push(make_pair(curr->right, hd+1));
        }
    }

    for (auto item: mp)
    {
        for (int i = 0; i < item.second.size(); i++)
        {
            cout << item.second[i] << " ";
        }
        cout << endl;
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
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(4);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(1);
    root->left->left->left->left = new Node(1);

    cout << "The tree is: " << endl;
    levelByLine(root);
    cout << "The vertical travesal of tree is: " << endl;
    vTraversal(root);

}
