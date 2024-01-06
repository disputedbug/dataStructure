// Program to find the min Subset difference in a given array
#include <iostream>
using namespace std;

// Top-down approach
int minSubSetSumDiff(int arr[], int n)
{
    bool t[100][100];
    int range = 0;

    for (int i = 0; i < n; i++)
        range += arr[i];

    for (int i = 0; i < n+1; i++)
        t[i][0] = true;

    for (int j = 1; j < range+1; j++)
        t[0][j] = false;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < range+1; j++)
        {
            if (arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]]
                       || t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }

    for (int i = range/2; i >= 0; i--)
    {
        //cout << i << " " << t[n][i] << " " << (range - 2*i) << endl;
        if (t[n][i] == true)
        {
            return (range - 2*i);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 3, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = minSubSetSumDiff(arr, n);
    cout << "Min diff for two Subsets is " << res << endl;
}
