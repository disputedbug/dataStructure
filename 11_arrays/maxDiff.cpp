// Program to find the maximum difference between arr[i] and arr[j]
// such that j > i
#include <iostream>
using namespace std;

int maxDiff(int arr[], int n)
{
    int min_elem = arr[0];
    int res = arr[1]-arr[0];

    for (int i=0; i<n; i++)
    {
        res = max(res, arr[i]-min_elem);
        min_elem = min(min_elem, arr[i]);
    }

    return res;
}

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int len = sizeof(arr)/sizeof(arr[0]);

    int res = maxDiff(arr, len);
    cout << "The maximum diff is: " << res << endl;
}
