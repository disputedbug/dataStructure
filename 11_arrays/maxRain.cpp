// Maximum amount of rain collected in a set of blocks
#include <iostream>
using namespace std;

int maxRain(int arr[], int len)
{
    int lMax[len];
    int rMax[len];
    int cap = 0;

    lMax[0] = arr[0];
    for (int i = 1; i < len; i++)
    {
        lMax[i] = max(lMax[i-1], arr[i]);
    }
    rMax[len-1] = arr[len-1];
    for (int i = len-2; i >= 0; i--)
    {
        rMax[i] = max(rMax[i+1], arr[i]);
    }
    for (int i = 1; i < len-1; i++)
    {
        cap += min(lMax[i], rMax[i]) - arr[i];
    }
    return cap;
}

int main()
{
    int arr[] = {5, 0, 6, 2, 3};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = maxRain(arr, len);
    cout << "Water collected is: " << ret << endl;
}
