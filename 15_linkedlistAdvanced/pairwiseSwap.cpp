// Program to swap a LL nodes in pairs
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

Node* pairwiseSwapRecur(Node* head)
{
    Node* curr = head;
    Node* prev = NULL, *next = NULL;
    int count = 0;
    int k = 2;

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
        Node* restHead = pairwiseSwapRecur(next);
        head->next = restHead;
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

    head = pairwiseSwapRecur(head);

    printList(head);

    cout << endl;
}
