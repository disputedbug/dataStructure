#include <iostream>
using namespace std;

int stockBuy(int arr[], int len)
{
    int profit;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > arr[i-1])
        {
            profit += arr[i]-arr[i-1]
        }
    }
    return profit;
}

int main()
{
    int arr[] = {7, 20, 4, 10, 6, 5, 2};
    int len = sizeof(arr)/sizeof(arr[0]);

    printLeader(arr, len);
    cout << endl;
}
