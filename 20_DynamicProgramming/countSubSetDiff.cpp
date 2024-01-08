// Program to find the num of Subsets with a given Sum in a given array
#include <iostream>
using namespace std;

// Recursive approach
int countSubSetSumRec(int arr[], int n, int sum)
{
    if (sum == 0) return 1;
    if (n == 0) return 0;

    if (arr[n-1] <= sum)
    {
        return countSubSetSumRec(arr, n-1, sum - arr[n-1])
              + countSubSetSumRec(arr, n-1, sum);
    }
    else
    {
        return countSubSetSumRec(arr, n-1, sum);
    }
}

// Top-Down approach
int countSubSetSum(int arr[], int n, int sum)
{
    int t[100][100];

    for (int i = 0; i < n+1; i++) t[i][0] = 1;
    for (int i = 1; i< sum+1; i++) t[0][i] = 0;

    for (int i = 1; i < n+1 ; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if (arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int countSubSetDiff(int arr[], int n, int diff)
{
    int range = 0;
    for (int i = 0; i < n; i++) range += arr[i];

    int sum = (range+diff)/2;

    return countSubSetSum(arr, n, diff);
}

int main()
{
    int arr[] = {1, 1, 2, 3};

    int diff = 1;
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = countSubSetDiff(arr, n, diff);

    cout << "Num of Subsets with diff " << diff <<
          " in the array is: " << res << endl;
}
