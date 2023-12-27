// Program to convert a bin-tree to a doubly linked list
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

Node* previous = NULL;
Node* binTreeToDll(Node* root, Node*& head)
{
    if (root == NULL)
        return NULL;

    binTreeToDll(root->left, head);

    if (previous == NULL)
    {
        head = root;
    }
    else
    {
        root->left = previous;
        previous->right = root;
    }
    previous = root;

    binTreeToDll(root->right, head);

    return head;
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

    cout << "The tree:" << endl;
    levelByLine(root);

    // convert the tree to DLL
    Node* head = NULL;
    binTreeToDll(root, head);

    //traverse the DLL now
    cout << "\nThe DLL:" << endl;
    while (head)
    {
        cout << head->key << " ";
        head = head->right;
    }
    cout << endl;
}
