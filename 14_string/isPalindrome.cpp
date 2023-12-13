// Program to find if a string is palidrome or not
#include <iostream>
using namespace std;

bool isPalindrome(string &s)
{
    int len = s.length();
    int start = 0;
    int end = len-1;

    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    string s = "abbdedbba";
    bool ret = isPalindrome(s);

    cout << boolalpha << "String " << s << " is a palindrome: " << ret << endl;
}
