// Code to find out the second largest element in the array
#include <iostream>
using namespace std;

int secondLargest(int arr[], int n)
{
    int largest = 0;
    int res = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else
        {
            if (res == -1 || arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 61, 40, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    int res = secondLargest(arr, len);

    cout << "Second largest element in the array is : " << arr[res] <<
            " with index " << res << endl;
}
