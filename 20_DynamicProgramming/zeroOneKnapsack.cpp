// Program for Zero One Knapsack
#include <iostream>
using namespace std;

// Recursive solution
int zeroOneKnapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n-1] <= w)
    {
        return max(val[n-1] + zeroOneKnapsack(wt, val, w-wt[n-1], n-1) ,
                   zeroOneKnapsack(wt, val, w, n-1));
    }
    else
    {
        return (zeroOneKnapsack(wt, val, w, n-1));
    }
}

// Memoized solution
int ret[20][20];
int zeroOneKnapsackMem(int wt[], int val[], int w, int n)
{
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (ret[n][w] != -1)
    {
        return ret[n][w];
    }
    if (wt[n-1] <= w)
    {
        return ret[n][w] = max(val[n-1]+zeroOneKnapsackMem(wt, val, w-wt[n-1], n-1),
                   zeroOneKnapsackMem(wt, val, w, n-1)
        );
    }
    else
    {
        return ret[n][w] = zeroOneKnapsackMem(wt, val, w, n-1);
    }
}

// Top-down approach
int zeroOneKnapsackTopdown(int wt[], int val[], int w, int n)
{
    int t[20][20];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if (wt[i-1] <= j)
            {
                t[i][j] = max((val[i-1] + t[i-1][j-wt[i-1]]),
                                          t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    int n = sizeof(val)/sizeof(val[0]);
    memset(ret, -1, sizeof(ret));

    int res = zeroOneKnapsackTopdown(wt, val, w, n);

    cout << "Maximum profit is " << res << endl;
}
