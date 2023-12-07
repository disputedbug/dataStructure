// Program to find the majority element
#include <iostream>
using namespace std;

int majorityElement(int arr[], int n)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            count = 1;
            res = i;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            count++;
        }
    }
    if (count < n/2)
        return -1;

    return res;
}

int main()
{
    int arr[] = {6, 8, 4, 8, 8, 3, 3, 8};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = majorityElement(arr, len);
    cout << "Majority element is: " << arr[ret] << endl;
}
