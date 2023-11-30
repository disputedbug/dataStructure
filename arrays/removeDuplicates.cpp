// Code to remove duplicates from a sorted array
#include <iostream>
using namespace std;

int remDups(int arr[], int n)
{
    int res = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[res-1] != arr[i])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
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
    int arr[] = {10, 10, 20, 30, 40, 40, 40, 50, 60, 60, 70, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    displayArray(arr, len);
    int res = remDups(arr, len);
    displayArray(arr, res);

    cout << endl;
}
