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

void deleteDupFromSortedLl(Node* head)
{
    Node* curr = head;

    while (curr && curr->next != NULL)
    {
        if (curr->item == curr->next->item)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else
        {
            curr = curr->next;
        }
    }
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

void insertAtPos(Node ** head, int pos, int num)
{
    Node* curr = *head;
    Node* temp = new Node(num);

    if (pos == 1)
    {
        temp->next = curr;
        *head = temp;
        return;
    }
    for (int i = 1; i <= pos-2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return; // no changes in the list
    }

    temp->next = curr->next;
    curr->next = temp;

    return;
}

int main()
{
    Node* head = NULL;

    for (int i = 0; i < 10; i++)
    {
        insertAtEnd(&head, 10*(i+1));
    }

printList(head);
    insertAtPos(&head, 1, 10);
    insertAtPos(&head, 1, 10);
    insertAtPos(&head, 5, 20);
    insertAtPos(&head, 6, 30);

    printList(head);

    deleteDupFromSortedLl(head);

    printList(head);

}
