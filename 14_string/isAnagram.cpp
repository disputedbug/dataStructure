// Program to find if two strings are Anagrams
#include <iostream>
using namespace std;

bool isAnagram(string a, string b, int len1, int len2)
{
    int hash[256] = {0};
    int i = 0;

    if (len1 != len2) return false;

    while (i < len1)
    {
        hash[a[i]]++;
        hash[b[i]]--;
        i++;
    }
    i = 0;
    while (i < 256)
    {
        if (hash[i] != 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    string a = "aabbccdez";
    string b = "zeccdaabb";

    bool ret = isAnagram(a, b, a.length(), b.length());

    string res = "String " + a + " and " + b + " are anagrams: ";

    cout << boolalpha << res << ret << endl;
}
