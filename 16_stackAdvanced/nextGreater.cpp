// Program to find the next greater element in an array
#include <iostream>
#include <stack>
using namespace std;

void nextGreat(int arr[], int n)
{
    vector <int> v;
    stack <int> s;
    s.push(arr[n-1]);
    v.push_back(-1);

    for (int i = n-2; i >=0; i--)
    {
        while (s.empty() != true && arr[i] >= s.top())
        {
            s.pop();
        }
        if (s.empty()) v.push_back(-1);
        else v.push_back(s.top());
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}

int main()
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    nextGreat(arr, len);
    cout << endl;
}
