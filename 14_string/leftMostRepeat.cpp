// Program to find the left-most repeating character
#include <iostream>
using namespace std;

//approach 1, 2 traversals needed
int leftMostRepeat(string &str)
{
    int ret = -1;
    int hash[256] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        hash[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (hash[str[i]])
            return i;
    }
    return -1;
}

//approach 2
int leftMostRepeat2(string &str)
{
    int ret = INT_MAX;
    int findex[256];
    fill(findex, findex+256, -1);

    for (int i = 0; i < str.length(); i++)
    {
        if (findex[str[i]] == -1)
        {
            findex[str[i]] = i;
        }
        else
        {
            ret = min(ret, findex[str[i]]);
        }
    }
    return ret;
}

//approach 3
int leftMostRepeat3(string &str)
{
    int ret = -1;
    bool visited[256];
    fill(visited, visited+256, false);

    for (int i = str.length()-1; i>=0; i--)
    {
        if (visited[str[i]])
        {
            ret = i;
        }
        else
        {
            visited[str[i]] = true;
        }
    }
    return ret;
}

int main()
{
    string a = "abccda";
    int ret = leftMostRepeat(a);

    string res = "String " + a + " has the left-most repeating char as: " + a[ret];
    cout << res << endl;
}
