// Program to find first a num in a sorted rotated array
#include <iostream>
using namespace std;

int searchRotated(int arr[], int len, int toFind)
{
    int start = 0;
    int end = len-1;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if (arr[mid] == toFind)
        {
            return mid;
        }
        else if (arr[start] < arr[mid])
        {
            if (toFind >= arr[start] && toFind < arr[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        else
        {
            if (toFind > arr[mid] && toFind <= arr[end])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {30, 35, 40, 50, 60, 70, 80, 10, 15, 20, 25};
    int len = sizeof(arr)/sizeof(arr[0]);
    int toFind = 15;

    int ret = searchRotated(arr, len, toFind);

    cout << toFind << " in rotated array is at index: " << ret << endl;


}
