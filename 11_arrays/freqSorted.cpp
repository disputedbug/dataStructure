// Program to find the frequency of elements in a sorted array
#include <iostream>
using namespace std;

void printFreq(int arr[], int n)
{
    int freq = 1;
    int i = 1;
    while (i<n)
    {
        while (i < n && arr[i] == arr[i-1])
        {
            freq++;
            i++;
        }
        cout << "Freq of " << arr[i-1] << " is " << freq << endl;
        i++;
        freq = 1;
    }
    if (n == 1 || arr[n-1] != arr[n-2])
    {
        cout << "Freq of " << arr[n-1] << " is 1" << endl;
    }
}

int main()
{
    int arr[] = {10, 10, 10, 30, 30, 40, 40};
    int len = sizeof(arr)/sizeof(arr[0]);

    printFreq(arr, len);
}
