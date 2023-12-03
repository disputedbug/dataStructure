// find if a given string is palindrome or not
#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    return (s[start] == s[end] &&
        isPalindrome(s, start+1, end-1));
}
int main()
{
    string s = "malayalam";
    bool res = isPalindrome(s, 0, s.size()-1);
    cout << boolalpha << "String " << s <<
            " is a Palindrome: " << res << endl;
}
