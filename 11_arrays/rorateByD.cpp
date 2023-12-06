#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return;
}

void rotateByD(int arr[], int len, int d)
{
    reverse(arr, 0, d-1);
    reverse(arr, d, len-1);
    reverse(arr, 0, len-1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    rotateByD(arr, len, 3);
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}
