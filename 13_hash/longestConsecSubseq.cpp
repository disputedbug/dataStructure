// Program to find the length of the longest consecutive subsequence in an array
#include <iostream>
#include <unordered_set>
using namespace std;

int longestConseqSub(int arr[], int n)
{
    unordered_set <int> hash(arr, arr+n);
    int res = 1;
    for (auto x: hash)
    {
        if (hash.find(x-1) == hash.end())
        {
            int curr = 1;
            while (hash.find(x+curr) != hash.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 10};
    int len = sizeof(a)/sizeof(a[0]);

    int ret = longestConseqSub(a, len);

    cout << "Longest consecutive subsequence in array is of length: " << ret << endl;
}
