#include <iostream>
using namespace std;

int binSearch(int arr[], int low, int high, int item)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low+high)/2;
    if (arr[mid] == item)
    {
        return mid;
    }
    else if (item < arr[mid])
    {
        return binSearch(arr, low, mid-1, item);
    }
    else
    {
        return binSearch(arr, mid+1, high, item);
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int item = 41;
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = binSearch(arr, 0, len-1, item);
    if (ret != -1) cout << "Item " << item << " found at index: " << ret << endl;
    else cout << "Item " << item << " not found in the array" << endl;
}
