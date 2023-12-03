#include <iostream>
#include <unordered_map>

using namespace std;

int maxLenSubarraySum(int arr[], int len, int sum)
{
    unordered_map <int, int> m;
    int pre_sum = 0;
    int res = 0;

    for (int i = 0; i < len; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
        {
            res = i+1;
        }
        if (m.find(pre_sum) == m.end())
        {
            //m.insert(pre_sum, i);
            m.insert({ 20, 130 });
        }
        if (m.find(pre_sum-sum) != m.end())
        {
            res = max(res, i-m[pre_sum-sum]);
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
    int arr[] = {1, 4, 13, -3, -10, 5, 15};
    int sum = 10;
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = maxLenSubarraySum(arr, len, sum);

    displayArray(arr, len);

    cout << "Max Length Subarray with sum "
         << sum << " exists in this array with size: "
         << ret << endl;
}
