// Program to find first occurance of a num in a sorted array with repeats
#include <iostream>
using namespace std;

int firstOccurRec(int arr[], int len, int start, int end, int toFind)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start+end)/2;
    if (toFind < arr[mid])
    {
        return firstOccurRec(arr, len, start, mid-1, toFind);
    }
    else if (toFind > arr[mid])
    {
        return firstOccurRec(arr, len, mid+1, end, toFind);
    }
    else
    {
        if (mid == 0 || arr[mid-1] != arr[mid])
        {
            return mid;
        }
        else
        {
            return firstOccurRec(arr, len, start, mid-1, toFind);
        }
    }
}

int firstOccur(int arr[], int len, int toFind)
{
    int start = 0;
    int end = len-1;

    while (start <= end)
    {
        int mid = (start+end)/2;
        if (toFind < arr[mid])
        {
            end = mid-1;
        }
        else if (toFind > arr[mid])
        {
            start = mid+1;
        }
        else
        {
            if (mid == 0 || arr[mid-1] != arr[mid])
            {
                return mid;
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
    int arr[] = {10, 10, 20, 20, 20, 20, 30, 30, 40};
    int len = sizeof(arr)/sizeof(arr[0]);
    int toFind = 30;

    int ret = firstOccurRec(arr, len, 0, len-1, toFind);

    cout << "First occurance of " << toFind << " is: " << ret << endl;


}
