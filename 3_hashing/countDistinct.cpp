// Program to count the disctinct elements in an array
#include <iostream>
#include <unordered_set>

using namespace std;

int countDistinct(int arr[], int len)
{
    unordered_set <int> h;
    for (int i = 0; i < len; i++)
    {
        h.insert(arr[i]);
    }
    return h.size();
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 4, 13, -3, -10, 5, 5, 1, -3, 6};
    int sum = 10;
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = countDistinct(arr, len);

    displayArray(arr, len);

    cout << "Number of disctinct elements in the array are: "
         << ret << endl;
}
