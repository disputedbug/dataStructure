// Program to find maximum length subarray
// of alternating odd even elements
#include <iostream>
using namespace std;

int maxOddEvenSubarray(int arr[], int n)
{
    int res = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i]%2 == 0 && arr[i-1]%2 == 1) ||
            (arr[i]%2 == 1 && arr[i-1]%2 == 0))
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 1;
        }
    }
    return res;
}

int main()
{
    int arr[] = {5, 10, 20, 6, 3, 8, 13};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = maxOddEvenSubarray(arr, len);
    cout << "Max Odd Even subarray size is: " << ret << endl;
}
