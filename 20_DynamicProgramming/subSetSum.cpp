// Program to find if Subset with a given Sum is in a given array
#include <iostream>
using namespace std;

// Top-down approach
bool subSetSum(int arr[], int n, int sum)
{
    bool t[100][100];

    for (int i = 0; i < n+1; i++)
        t[i][0] = true;

    for (int j = 1; j < sum+1; j++)
        t[0][j] = false;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
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
    return t[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};

    int sum = 11;
    int n = sizeof(arr)/sizeof(arr[0]);

    bool res = subSetSum(arr, n, sum);

    cout << boolalpha << "Subset with sum " << sum <<
          " is in the array: " << res << endl;
}
