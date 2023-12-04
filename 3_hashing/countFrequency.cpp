// Program to count the disctinct elements in an array
#include <iostream>
#include <unordered_map>

using namespace std;

void countFrequency(int arr[], int len)
{
    unordered_map <int, int> h;
    for (int i = 0; i < len ; i++)
    {
        h[arr[i]]++;
    }
    for (auto e:h)
    {
        cout << e.first << " " << e.second << endl;
    }
    return;
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
    int arr[] = {1, 4, 13, 3, 10, 5, 13, 5, 1, 3, 6};
    int sum = 10;
    int len = sizeof(arr)/sizeof(arr[0]);

    displayArray(arr, len);
    countFrequency(arr, len);
}
