// Program to check if an Equilibrium point exists
#include <iostream>
using namespace std;

bool isEquilibrium(int arr[], int n)
{
    int rsum = 0;
    for (int i = 0; i < n; i++)
    {
        rsum = rsum + arr[i];
    }
    int lsum = 0;
    for (int i = 0; i < n; i++)
    {
        rsum = rsum - arr[i];
        if (lsum == rsum)
            return true;
        lsum = lsum + arr[i];
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 9, 7};
    int len = sizeof(arr)/sizeof(arr[0]);

    bool ret = isEquilibrium(arr, len);
    cout <<  boolalpha << "Equilibrium point exists: " << ret << endl;
}
