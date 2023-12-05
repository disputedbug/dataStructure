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

void deleteFirst(Node ** head)
{
    if (*head == NULL)
    {
        return;
    }

    Node* temp = (*head)->next;
    delete(*head);

    *head = temp;

    return;
}

void deleteLast(Node ** head)
{
    Node* curr = *head;
    if (curr == NULL)
    {
        return;
    }
    if (curr->next == NULL)
    {
        delete(curr);
        *head = NULL;

        return;
    }

    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete(curr->next);
    curr->next = NULL;

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

    deleteFirst(&head);

    printList(head);

    deleteLast(&head);

    printList(head);
}
