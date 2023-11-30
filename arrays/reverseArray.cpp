// Code to reverse an array
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

void reverseArray(int arr[], int n)
{
    int low = 0;
    int high = n-1;

    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    displayArray(arr, len);
    reverseArray(arr, len);
    displayArray(arr, len);

    cout << endl;
}
