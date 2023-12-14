// Program to find if a string is subsequence of another string
#include <iostream>
using namespace std;

bool isSubseq(string a, string b, int len1, int len2)
{
    if (len2 == 0)
        return true;
    if (len1 == 0)
        return false;

    if (a[len1-1] == b[len2-1])
    {
        return isSubseq(a, b, len1-1, len2-1);
    }
    else
        return isSubseq(a, b, len1-1, len2);
}

bool isSubseqIter(string a, string b, int len1, int len2)
{
    int j = 0;
    for (int i = 0; i < len1 && j < len2; i++)
    {
        if (a[i] == b[j])
        {
            j++;
        }
    }
    return (j == len2);
}

int main()
{
    string a = "abc";
    string b = "ac";

    bool ret = isSubseqIter(a, b, a.length(), b.length());

    string res = "String " + b + " is subsequnce of string " +a+ ": ";

    cout << boolalpha << res << ret << endl;
}
