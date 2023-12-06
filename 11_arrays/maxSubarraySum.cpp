// Program to maximum subarray sum
#include <iostream>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnding = max(arr[i], arr[i]+maxEnding);
        res = max(res, maxEnding);
    }
    return res;
}

int main()
{
    int arr[] = {-3, 8, -2, 4, -5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = maxSubarraySum(arr, len);
    cout << "Max sum for a subarray is: " << ret << endl;
}
