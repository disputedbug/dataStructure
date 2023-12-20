// Program to find the previous greater element in an array
#include <iostream>
#include <stack>
using namespace std;

void prevGreat(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "-1 ";

    for (int i = 1; i < n; i++)
    {
        while (s.empty() != true && arr[i] >= s.top())
        {
            s.pop();
        }
        if (s.empty() == true)
            cout << "-1 ";
        else
            cout << s.top() << " ";

        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {60, 10, 20, 15, 35, 50};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    prevGreat(arr, len);
    cout << endl;
}
