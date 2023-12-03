// Code to find out if the array is sorted
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int len = sizeof(arr)/sizeof(arr[0]);

    bool res = isSorted(arr, len);

    cout << boolalpha << "Given array is sorted: " << res << endl;
}
