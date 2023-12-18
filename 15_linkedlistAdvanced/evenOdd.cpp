// Program to segregate a list based on even and odd keys
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

Node* segregate(Node* head)
{
    Node* curr = head;
    Node* eS = NULL, *eE = NULL;
    Node* oS = NULL, *oE = NULL;
    int key = 0;

    while (curr != NULL)
    {
        key = curr->item;
        if (key % 2 == 0)
        {
            if (eS == NULL)
            {
                eS = curr;
                eE = curr;
            }
            else
            {
                eE->next = curr;
                eE = eE->next;
            }
        }
        else
        {
          if (oS == NULL)
          {
              oS = curr;
              oE = curr;
          }
          else
          {
              oE->next = curr;
              oE = oE->next;
          }
        }
        curr = curr->next;
    }
    if (eE == NULL || oE == NULL)
    {
        return head;
    }
    eE->next = oS;
    oE->next = NULL;

    return eS;
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
        head = insertAtEnd(head, i);
    }
    printList(head);

    head = segregate(head);

    printList(head);

    cout << endl;
}
