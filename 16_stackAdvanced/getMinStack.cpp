// Program to implement the min-stack with two stacks
#include <iostream>
#include <stack>
using namespace std;

class minStack
{
  private:
    stack <int> ms;
    stack <int> as;

  public:
    minStack()
    {
        cout << "Min-Stack init" << endl;

    }
    int getMin()
    {
        return as.top();
    }
    void push(int x)
    {
        cout << "Min-Stack PUSH called with val: " << x << endl;
        if (ms.empty())
        {
            ms.push(x);
            as.push(x);
            return;
        }
        if (x <= as.top())
        {
            as.push(x);
        }
        ms.push(x);
    }
    void pop()
    {
        cout << "Min-Stack POP called" << endl;
        if (!ms.empty() && (ms.top() == as.top()))
        {
            as.pop();
        }
        if (!ms.empty())
        {
            ms.pop();
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
