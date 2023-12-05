// Program to insert in sorted order in a LL
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

void insertSorted(Node ** head, int num)
{
    Node* curr = *head;
    Node* temp = new Node(num);

    if (curr == NULL || num <= curr->item)
    {
        temp->next = curr;
        *head = temp;
        return;
    }
    while (curr->next && num > curr->next->item)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;

    return;
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

    insertSorted(&head, 5);
    insertSorted(&head, 55);

    printList(head);
}
