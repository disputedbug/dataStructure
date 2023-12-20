// Program to find the stock span
#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "1 ";

    for (int i = 1; i < n; i++)
    {
        while (s.empty() != true && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        int span = s.empty() ? i+1 : (i-s.top());
        cout << span << " ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {60, 10, 20, 15, 35, 50};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    stockSpan(arr, len);
    cout << endl;
}
