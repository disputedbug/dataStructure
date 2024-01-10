// Program to find Minimum Number of Insertion and Deletion to convert String a to String b
#include <iostream>
using namespace std;

// Top-Down approach
void minInsertDelete(string a, string b, int m, int n)
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
    cout << "The number of letters to be deleted from " << a << " is "
         << m-t[m][n] << " and number of letters to be added is "
         << n-t[m][n] << " to make it " << b << endl;

    return;
}

int main()
{
    string a = "geek";
    string b = "eka";

    minInsertDelete(a, b, a.length(), b.length());
}
