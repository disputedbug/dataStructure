// Program to find if an expression has balanced brackets
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr)
{
    stack <char> s;
    for (auto ch: expr)
    {
        if (s.empty())
        {
            s.push(ch);
        }
        else if ((ch == ']' && s.top() == '[') ||
            (ch == '}' && s.top() == '{') ||
            (ch == ')' && s.top() == '('))
        {
          s.pop();
        }
        else
        {
            s.push(ch);
        }
    }
    if (s.empty()) return true;
    else return false;
}

int main()
{
    string expression = "[{()()}()]";
    cout << boolalpha << "Expression " << expression << " is balanced: " << isBalanced(expression) << endl;
}
