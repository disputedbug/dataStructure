// Code to left rotate an array by 1
#include <iostream>
using namespace std;


void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotateByD(int arr[], int n, int d)
{
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    displayArray(arr, len);
    leftRotateByD(arr, len, 2);
    displayArray(arr, len);

    cout << endl;
}
