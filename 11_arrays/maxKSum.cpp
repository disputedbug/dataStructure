// Program to find the maximum sum of a k sized subarray
#include <iostream>
using namespace std;

int maxKSum(int arr[], int n, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum+arr[i];
    }
    int res = sum;
    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i-k];
        res = max(res, sum);
    }
    return res;
}

int main()
{
    int k = 4;
    int arr[] = {1, 8 , 30, -5, 20, 7};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = maxKSum(arr, len, k);
    cout << "Maximum sum of a " <<  k
         << " sized subarray: " << ret << endl;
}
