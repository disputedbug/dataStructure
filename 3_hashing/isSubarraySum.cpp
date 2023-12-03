#include <iostream>
#include <unordered_set>

using namespace std;

bool isSubarraySum(int arr[], int len, int sum)
{
    int pre_sum = 0;
    unordered_set <int> h;

    for (int i = 0; i < len; i++)
    {
        pre_sum += arr[i];
        if (h.find(pre_sum - sum) != h.end())
        {
            return true;
        }
        if (pre_sum == sum)
        {
            return true;
        }
        h.insert(pre_sum);
    }
    return false;
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
    int arr[] = {1, 4, 13, -3, -10, 5};
    int sum = 10;
    int len = sizeof(arr)/sizeof(arr[0]);

    bool ret = isSubarraySum(arr, len, sum);

    displayArray(arr, len);

    cout << boolalpha
         << "Subarray with sum "
         << sum << " exists in this array: "
         << ret << endl;
}
