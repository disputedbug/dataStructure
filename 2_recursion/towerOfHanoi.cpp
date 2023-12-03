// Program to solve tower of Hanoi problem
#include <iostream>
using namespace std;

void tower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move 1 from " << a << " to " << c << endl;
        return;
    }
    tower(n-1, a, c, b);
    cout << "Move " << n << " from " << a << " to " << c << endl;
    tower(n-1, b, a, c);
}

int main()
{
    tower(3, 'A', 'B', 'C');
}
