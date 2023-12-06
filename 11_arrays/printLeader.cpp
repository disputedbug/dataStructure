#include <iostream>
using namespace std;

void printLeader(int arr[], int len)
{
    int curr_lead = arr[len-1];
    cout << curr_lead << " ";

    for (int i = len-2; i >=0; i--)
    {
        if (arr[i] > curr_lead)
        {
            curr_lead = arr[i];
            cout << curr_lead << " ";
        }
    }
    return;
}

int main()
{
    int arr[] = {7, 20, 4, 10, 6, 5, 2};
    int len = sizeof(arr)/sizeof(arr[0]);

    printLeader(arr, len);
    cout << endl;
}
