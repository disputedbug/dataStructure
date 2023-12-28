// Programs to serialize and deserialize a binary tree
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

#define EMPTY -1
void serialize(Node* root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);

}

Node* deserialize(vector <int> &arr, int &preIndex)
{
    if (preIndex == arr.size())
        return NULL;

    int val = arr[preIndex];
    preIndex++;
    if (val == EMPTY)
        return NULL;

    Node* root = new Node(val);
    root->left = deserialize(arr, preIndex);
    root->right = deserialize(arr, preIndex);

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

    // Serialize this tree now
    vector <int> arr;
    serialize(root, arr);

    // Print the serialized tree array
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    // Deserialise the new tree .. and print
    int in = 0;
    Node * newTree = deserialize(arr, in);
    levelByLine(newTree);
}
