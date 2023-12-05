// Program to print the middle element of a LL
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

void printMiddle(Node * head)
{
    if (head == NULL)
    {
        cout << "Empty linked list" << endl;
        return;
    }
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element is " << slow->item << endl;

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

    for (int i = 0; i < 9; i++)
    {
        insertAtEnd(&head, 10*(i+1));
    }

    printList(head);

    printMiddle(head);
}
