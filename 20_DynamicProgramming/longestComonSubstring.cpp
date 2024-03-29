// Program to find the length of the longest comon substring
#include <iostream>
using namespace std;

// Top-Down approach
int longestCommSubstring(string a, string b, int m, int n)
{
    int t[20][20];
    int lcsLen = 0;

    for (int i = 0; i < m+1; i++) t[i][0] = 0;
    for (int j = 0; j < n+1; j++) t[0][j] = 0;

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (a[i-1] == b[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
                lcsLen = max(lcsLen, t[i][j]);

            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return lcsLen;
}

int main()
{
    string a = "himanshu";
    string b = "sharma";

    int ret = longestCommSubstring(a, b, a.length(), b.length());

    cout << "Length of lcs for " << a << " and " << b << " is: " << ret << endl;
}
