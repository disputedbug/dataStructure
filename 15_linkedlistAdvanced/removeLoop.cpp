// Program to remove the loop in the LL
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

bool removeLoop(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        return false;
    }

    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;

    return true;
}

Node* endNode;
Node* midNode;
Node* insertAtEnd(Node* head, int num)
{
    Node* temp = new Node(num);
    Node* curr = head;

    if (head == NULL)
    {
        endNode = temp;
        return temp;
    }

    if (num == 110)
    {
        midNode = temp;
    }

    if (num == 200)
    {
        temp->next = midNode;// comment this line to remove the loop
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

    bool ret = removeLoop(head);

    if (ret)
    {
        cout << boolalpha << "Loop in the LL found and removed: " << ret << endl;
        printList(head);
    }
    else
    {
        cout << "No loop in the LL found" << endl;
        printList(head);
    }

}
