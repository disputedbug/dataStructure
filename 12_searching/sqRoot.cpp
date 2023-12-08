// Program to find floor value of the squareroot of a num
#include <iostream>
using namespace std;

int sqRoot(int num)
{
    int res = -1;
    int start = 1;
    int end = num;

    while (start <= end)
    {
        int mid = (start+end)/2;
        int mSq = mid*mid;

        if (mSq == num)
        {
            return mid;
        }
        else if (mSq < num)
        {
            res = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return res;
}

int main()
{

    int toFind = 49;

    int ret = sqRoot(toFind);

    cout << "Square-root of " << toFind << " is: " << ret << endl;


}
