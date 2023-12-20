// Program to merge two sorted linked lists in sorted order
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

Node* sortedMerge(Node* a, Node* b)
{
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* head = NULL, *tail = NULL;

    if (a->item < b->item)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    while (a != NULL && b != NULL)
    {
        if (a->item < b->item)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a == NULL) tail->next = b;
    else tail->next = a;

    return head;
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
    Node* a = NULL;
    for (int i = 1; i <= 20; i++)
    {
        a = insertAtEnd(a, i*10);
    }
    printList(a);

    Node* b = NULL;
    for (int i = 1; i <= 20; i++)
    {
        b = insertAtEnd(b, i*10+5);
    }
    printList(b);

    Node* head = sortedMerge(a, b);

    printList(head);

    cout << endl;
}
