// Code to find out the index of the largest element in an array
#include <iostream>

using namespace std;

int getLargest(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] < arr[i])
        {
            res = i;
        }
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 5, 61, 23, 88, 9, 20};
    int len = sizeof(arr)/sizeof(arr[0]);

    int res = getLargest(arr, len);

    cout << "largest element is " << arr[res] << " with index " << res << endl;

}
