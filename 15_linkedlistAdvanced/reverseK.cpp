// Program to reverse a LL in a group of k nodes
#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node* next;

    Node(int x)
    {
        item = x;
        next = NULL;
    }
};

Node* reverseK(Node* head, int k)
{
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        Node* rest_head = reverseK(next, k);
        head->next = rest_head;
    }
    return prev;
}

Node* endNode;
Node* insertAtEnd(Node* head, int num)
{
    Node* temp = new Node(num);
    Node* curr = head;

    if (head == NULL)
    {
        endNode = temp;
        return temp;
    }

    endNode->next = temp;
    endNode = temp;

    return head;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->item << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    for (int i = 1; i <= 20; i++)
    {
        head = insertAtEnd(head, i*10);
    }
    printList(head);

    head = reverseK(head, 3);

    printList(head);

    cout << endl;
}
