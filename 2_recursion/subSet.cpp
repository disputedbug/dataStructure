// Program to print all the subset or subsequence of a String
// A total of 2^n such subsets exist, where n is the length of the string
#include <iostream>

using namespace std;

void subSet(string &s, string curr = "", int index = 0)
{
    if (s.size() == index)
    {
        cout << "{" << curr << "}" << endl;
        return;
    }
    subSet(s, curr, index+1);
    subSet(s, curr+s[index], index+1);
}

int main()
{
    string s = "XYZ";

    subSet(s, "", 0);
}
