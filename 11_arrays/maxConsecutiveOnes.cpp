// Maximum consecutive 1s in a binary array
#include <iostream>
using namespace std;

int maxConseqOnes(int arr[], int len)
{
    int res = 0;
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            res = max(res, count);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = maxConseqOnes(arr, len);
    cout << "Maximum consecutive 1s in the bin array are: " << ret << endl;
}
