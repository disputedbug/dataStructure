// Find if a pair with a given sum exists in an array
#include <iostream>
#include <unordered_set>
using namespace std;

bool isPair(int arr[], int n, int sum)
{
    unordered_set <int> hash;
    for (int i = 0; i < n; i++)
    {
        if (hash.find(sum-arr[i]) != hash.end())
        {
            return true;
        }
        else
        {
            hash.insert(arr[i]);
        }
    }
    return false;
}

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 10};
    int m = sizeof(a)/sizeof(a[0]);
    int sum = 7;

    bool ret = isPair(a, m, sum);

    cout << boolalpha << "Pair with sum " << sum << " found in the array: " << ret << endl;
}
