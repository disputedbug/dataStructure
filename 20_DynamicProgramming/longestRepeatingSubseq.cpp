// Program to find the length of the longest repeating subsequence
#include <iostream>
using namespace std;

// Top-Down approach
int longReapSubSeq(string a, int n)
{
    int t[20][20];

    for (int i = 0; i < n+1; i++) t[i][0] = 0;
    for (int j = 0; j < n+1; j++) t[0][j] = 0;

    string b = a;

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (a[i-1] == b[j-1] && i != j)
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[n][n];
}

int main()
{
    string a = "aabebcdcd";

    int ret = longReapSubSeq(a, a.length());

    cout << "Length of longest repeating subsequence for " << a << " is: " << ret << endl;
}
