// Program to Search an element in an infinitely sized array
#include <iostream>
using namespace std;

int binSearch(int arr[], int low, int high, int toFind)
{
    if (low > high) return -1;
    int mid = (low + high)/2;
    if (toFind == arr[mid])
    {
        return mid;
    }
    else if (toFind < arr[mid])
    {
        return binSearch(arr, low, mid-1, toFind);
    }
    else
    {
        return binSearch(arr, mid+1, high, toFind);
    }
}
int infiniteSearch(int arr[], int toFind)
{
    int i = 1;
    if (arr[0] == toFind)
    {
        return 0;
    }
    while (arr[i] < toFind)
    {
        i = i*2;
    }
    if (arr[i] == toFind)
    {
        return i;
    }
    return binSearch(arr, i/2+1, i, toFind);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 11, 18, 21, 29, 31, 37, 41, 45, 49, 55, 61, 66, 77, 80, 90};
    int toFind = 49;
    int ret = infiniteSearch(arr, toFind);
    cout << "In the big array of " << toFind << " is at index: " << ret << endl;
}
