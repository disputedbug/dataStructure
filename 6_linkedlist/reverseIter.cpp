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

void reverseIter(Node ** head)
{
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr!= NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void insertAtEnd(Node** head, int num)
{
    Node* temp = new Node(num);

    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;

    return;
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

    for (int i = 0; i < 10; i++)
    {
        insertAtEnd(&head, 10*(i+1));
    }

    printList(head);

    reverseIter(&head);

    printList(head);
}
