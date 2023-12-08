// Program to find the last occurance of a num in a sorted array with repeats
#include <iostream>
using namespace std;

int lastOccurRec(int arr[], int len, int start, int end, int toFind)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start+end)/2;
    if (toFind < arr[mid])
    {
        return lastOccurRec(arr, len, start, mid-1, toFind);
    }
    else if (toFind > arr[mid])
    {
        return lastOccurRec(arr, len, mid+1, end, toFind);
    }
    else
    {
        if (mid == len-1 || arr[mid] != arr[mid+1])
        {
            return mid;
        }
        else
        {
            return lastOccurRec(arr, len, mid+1, end, toFind);
        }
    }
}

int lastOccur(int arr[], int len, int toFind)
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
            if (mid == len-1 || arr[mid] != arr[mid+1])
            {
                return mid;
            }
            else
            {
                start = mid+1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 10, 20, 20, 20, 20, 30, 30, 40};
    int len = sizeof(arr)/sizeof(arr[0]);
    int toFind = 20;

    int ret = lastOccur(arr, len, toFind);

    cout << "Last occurance of " << toFind << " is: " << ret << endl;


}
