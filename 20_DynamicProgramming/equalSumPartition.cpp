// Program to find if 2 Subsets with equal Sum exist is in the given array
#include <iostream>
using namespace std;

// Recursive approach
bool subSetSumRec(int arr[], int n, int sum)
{
    if (sum == 0) return true;

    if (n == 0) return false;

    if (arr[n-1] <= sum)
    {
        return subSetSumRec(arr, n-1, sum-arr[n-1]) || subSetSumRec(arr, n-1, sum);
    }
    else
    {
        return subSetSumRec(arr, n-1, sum);
    }
}

// Top-down approach
bool subSetSum(int arr[], int n, int sum)
{

    bool t[100][100];

    for (int i = 0; i < n+1; i++)
    {
        t[i][0] = true;
    }
    for (int j = 1; j < sum+1; j++)
    {
        t[0][j] = false;
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

bool equalSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum%2 != 0)  return false;

    return subSetSum(arr, n, sum/2);
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    bool res = equalSum(arr, n);

    cout << boolalpha << "Subsets with equal sum exist " <<
            "in the array: " << res << endl;
}
