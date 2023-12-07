// Program to check if a subaaray with a given sum exists
#include <iostream>
using namespace std;

bool isSubSum(int arr[], int n, int sum)
{
    int curr_sum = 0;
    int si = 0;
    for (int ei = 0; ei < n; ei++)
    {
        curr_sum = curr_sum + arr[ei];
        while (curr_sum > sum)
        {
            curr_sum = curr_sum - arr[si];
            si++;
        }
        if (sum == curr_sum)
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {7, 20, 4, 10, 6, 5, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int sum = 14;

    bool ret = isSubSum(arr, len, sum);
    cout <<  boolalpha << "Subarray with sum " << sum <<
            " exists: " << ret << endl;
}
