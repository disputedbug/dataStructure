// Code to move Zeros to the end of an array
#include <iostream>
using namespace std;

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int moveZeros(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {10, 20, 0, 0, 0, 30, 0, 40, 0, 50, 60, 70, 0};
    int len = sizeof(arr)/sizeof(arr[0]);

    displayArray(arr, len);
    int res = moveZeros(arr, len);
    displayArray(arr, res);

    cout << endl;
}
