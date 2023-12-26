// Program to print first n numbers with 2 given digits
#include <iostream>
#include <queue>
using namespace std;

void printFirstN(int firstNum, int secondNum, int count)
{
    queue <string> q;
    q.push(to_string(firstNum));
    q.push(to_string(secondNum));

    for (int i = 0; i < count; i++)
    {
        string curr = q.front();
        q.pop();
        cout << curr << " ";

        q.push(curr+to_string(firstNum));
        q.push(curr+to_string(secondNum));
    }
}

int main()
{
    printFirstN(4, 5, 11);
    cout << endl;
}
