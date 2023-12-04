#include <iostream>
using namespace std;

int binSearch(int arr[], int len, int item)
{
    int start = 0;
    int end = len-1;
    int mid = 0;

    while (start <= end)
    {
        mid = (start+end)/2;

        if (arr[mid] == item)
        {
            return mid;
        }
        else if (arr[mid] > item)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int item = 40;
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = binSearch(arr, len, item);    
    if (ret != -1) cout << "Item " << item << " found at index: " << ret << endl;
    else cout << "Item " << item << " not found in the array" << endl;

}
