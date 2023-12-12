// Program to find if the sorted array has a pair that adds to a number
#include <iostream>
using namespace std;

bool isPair(int arr[], int len, int num)
{
    int start = 0;
    int end = len-1;

    while (start < end)
    {
        if (arr[start]+arr[end] == num)
        {
            //cout << arr[start] << " " << arr[end] << endl;
            return true;
        }
        else if (arr[start]+arr[end] > num)
            end--;
        else
            start++;
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 6, 10, 15, 20, 22, 26, 30};
    int len = sizeof(arr)/sizeof(arr[0]);
    int toFind = 35;
    bool ret = isPair(arr, len, toFind);
    cout << boolalpha << "Array has a pair adding to the num " << toFind << ": " << ret << endl;
}
