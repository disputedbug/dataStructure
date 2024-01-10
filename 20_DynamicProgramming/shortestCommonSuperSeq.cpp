// Program to find the length of the shortest common super-sequence
#include <iostream>
using namespace std;

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
    return (m + n - t[m][n]);
}

int main()
{
    string a = "geek";
    string b = "eka";

    int ret = lcsIter(a, b, a.length(), b.length());

    cout << "Length of shortest common super-sequence for " << a << " and " << b << " is: " << ret << endl;
}
