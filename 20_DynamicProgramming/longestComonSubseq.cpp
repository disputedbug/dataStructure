// Program to find the length of the longest comon subsequence
#include <iostream>
using namespace std;

// Recursive approach
int lcsRec(string a, string b, int m, int n)
{
    if (m == 0 || n == 0) return 0;

    if (a[m-1] == b[n-1])
    {
        return 1+ lcsRec(a, b, m-1, n-1);
    }
    else
    {
        return max(lcsRec(a, b, m-1, n), lcsRec(a, b, m, n-1));
    }
}

// Memoization approach
int t[20][20];
int lcsMem(string a, string b, int m, int n)
{
    if (m == 0 || n == 0) return 0;

    if (t[m][n] != -1)  return t[m][n];

    if (a[m-1] == b[n-1])
    {
        return t[m][n] = 1 + lcsMem(a, b, m-1, n-1);
    }
    else
    {
        return t[m][n] = max(lcsMem(a, b, m-1, n), lcsMem(a, b, m, n-1));
    }
}

// Top-Down approach
int lcsIter(string a, string b, int m, int n)
{
    int t[20][20];

    for (int i = 0; i < m+1; i++) t[i][0] = 0;
    for (int j = 0; j < n+1; j++) t[0][j] = 0;

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (a[i-1] == b[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[m][n];
}

int main()
{
    string a = "abcasdf";
    string b = "acad";

    memset(t, -1, sizeof(t));
    int ret = lcsIter(a, b, a.length(), b.length());

    cout << "Length of lcs for " << a << " and " << b << " is: " << ret << endl;
}
