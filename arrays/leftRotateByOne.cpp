// Code to left rotate an array by 1
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

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1 ; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    displayArray(arr, len);
    leftRotateByOne(arr, len);
    displayArray(arr, len);

    cout << endl;
}
