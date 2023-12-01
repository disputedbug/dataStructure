// find sum of digits of a number using recursion
#include <iostream>
using namespace std;

int getDigitSum(int num)
{
    if (num > 0 && num < 9)
    {
        return num;
    }
    int lastDigit = num%10;

    return lastDigit+ getDigitSum(num/10);


}
int main()
{
    int n = 1199291;
    int sum = getDigitSum(n);
    cout << "Sum of digits of the number " <<
            n << " is " << sum << endl;
}
