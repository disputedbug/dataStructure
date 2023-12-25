// Program to find the next greater element in an array
#include <iostream>
#include <stack>
using namespace std;

vector <int> prevSmall(int arr[], int n)
{
    vector <int>v;
    stack<int> s;
    s.push(arr[0]);
    v.push_back(-1);

    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[i] <= s.top())
        {
            s.pop();
        }
        if (s.empty()) v.push_back(-1);
        else v.push_back(s.top());
        s.push(arr[i]);
    }
    return v;
}


vector <int> nextSmall(int arr[], int n)
{
    vector <int>v;
    stack<int> s;
    s.push(n-1);
    v.push_back(-1);

    for (int i = n-2; i >= 0; i--)
    {
        while (s.empty() != true && arr[i] <= s.top())
        {
            s.pop();
        }
        if (s.empty() == true)  v.push_back(-1);
        else  v.push_back(s.top());

        s.push(arr[i]);
    }
    return v;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector <int> ps = prevSmall(arr, len);

    for (int i = 0; i < len; i++)
        cout << ps[i] << " ";
    cout << endl;

    cout << endl;
}
