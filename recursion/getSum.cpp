// find sum of numbers from 1 to n using recursion
#include <iostream>
using namespace std;

int getSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n + getSum(n-1));
}
int main()
{
    int n = 10;
    int sum = getSum(n);
    cout << "Sum of numbers from 1 to " <<
            n << " is " << sum << endl;
}
