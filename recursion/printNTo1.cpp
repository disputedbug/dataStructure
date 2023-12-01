// Print number n to 1 using recursion
#include <iostream>
using namespace std;

void printNums(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    }

    cout << n << " ";
    printNums(n-1);
}

int main()
{
    int n = 10;
    cout << "Print numbers from " << n << " to 1" << endl;
    printNums(n);
}
