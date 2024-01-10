// Program to print the longest of the longest comon subsequence
#include <iostream>
using namespace std;

// Top-Down approach
string longestCommSubseq(string a, string b, int m, int n)
{
    int t[100][100];

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

    int i = m, j = n;
    string s = "";
    while (i > 0 && j > 0)
    {
        if (a[i-1] == b[j-1])
        {
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else
        {
            if (t[i-1][j] > t[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());

    return s;
}

int main()
{
    string a = "acegikq";
    string b = "egikqq";

    string ret = longestCommSubseq(a, b, a.length(), b.length());

    cout << "lcs for " << a << " and " << b << " is: " << ret << endl;
}
