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

void insertAtBegin(Node** head, int num)
{
    Node* temp = new Node(num);
    temp->next = *head;

    *head = temp;

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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printList(head);

    insertAtBegin(&head, 5);
    insertAtEnd(&head, 55);

    printList(head);
}
