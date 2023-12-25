// Program to implement the min-stack with only one stacks
#include <iostream>
#include <stack>
using namespace std;

class minStack
{
  private:
    stack <int> s;
    int min;

  public:
    minStack()
    {
        cout << "Min-Stack init" << endl;
    }
    int getMin()
    {
        return min;
    }
    int top(int x)
    {
        int n = s.top();
        if (n <= 0) return min;
        else  return n;
    }
    void push(int x)
    {
        cout << "Min-Stack PUSH called with val: " << x << endl;
        if (s.empty())
        {
            min = x;
            s.push(x);
        }
        else if (x <= min)
        {
          s.push(x-min);
          min = x;
        }
        else
        {
            s.push(x);
        }
    }
    int pop()
    {
        cout << "Min-Stack POP called" << endl;
        int x = s.top();
        s.pop();
        if (x <= 0)
        {
            int res = min;
            min = min - x;
            return res;
        }
        else
        {
            return x;
        }
    }
};

int main()
{
    minStack minS;
    minS.push(5);
    cout << "Min val is: " << minS.getMin() << endl;
    minS.push(10);
    cout << "Min val is: " << minS.getMin() << endl;
    minS.push(20);
    cout << "Min val is: " << minS.getMin() << endl;
    minS.push(2);
    cout << "Min val is: " << minS.getMin() << endl;
    minS.push(6);
    cout << "Min val is: " << minS.getMin() << endl;
    minS.push(4);
    cout << "Min val is: " << minS.getMin() << endl;

    minS.pop();
    cout << "Min val is: " << minS.getMin() << endl;

    minS.pop();
    cout << "Min val is: " << minS.getMin() << endl;

    minS.push(2);
    cout << "Min val is: " << minS.getMin() << endl;

    minS.pop();
    cout << "Min val is: " << minS.getMin() << endl;

    minS.push(1);
    cout << "Min val is: " << minS.getMin() << endl;

    minS.pop();
    cout << "Min val is: " << minS.getMin() << endl;

    minS.pop();
    cout << "Min val is: " << minS.getMin() << endl;


    cout << endl;
}
