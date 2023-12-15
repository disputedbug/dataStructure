// Program to reverse a string but w/o reversing the words 
#include <iostream>
using namespace std;

void reverse(char str[], int start, int end)
{
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    return;
}

void reverseWords(char str[], int len)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            end = i;
            reverse(str, start, end-1);
            start = i+1;
        }
    }
    reverse(str, end+1, len-1);
    reverse(str, 0, len-1);
}

int main()
{
    char a[] = "I am a good boy";
    int len = sizeof(a)/sizeof(a[0]) - 1;
    cout << a << endl;
    reverseWords(a, len);
    cout << a << endl;
}
