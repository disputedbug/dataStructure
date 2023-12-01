// Print number 1 to n using recursion
#include <iostream>
using namespace std;

void printOneToN(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }
    printOneToN(n-1);
    cout << n << " ";
}

int main()
{
    int n = 10;
    cout << "Print numbers from 1 to " << n;
    printOneToN(n);
}
