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

void nthFromEnd(Node* head, int n)
{
    Node* first = head;
    Node* second = head;
    if (head == NULL)
    {
        return;
    }


    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    cout << n << "th element from end is: "
         << second->item <<endl;
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
    nthFromEnd(head, 2);
}
