// Find intersection of two arrays
// Use g++ -std=c++17 -g intersection.cpp -o intersection to compile
#include <iostream>
#include <unordered_set>
using namespace std;

int intersection(int a[], int b[], int m, int n)
{
    unordered_set <int> hash;
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        hash.insert(a[i]);
    }
    for (int i = 0; i < n;i++)
    {
        if (hash.find(b[i]) != hash.end())
        {
            hash.erase(b[i]);
            ret++;
        }
    }
    for (auto key: hash)
        cout << key  << " ";

    cout << endl;
    return ret;
}

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 10};
    int m = sizeof(a)/sizeof(a[0]);
    int b[] = {2, 3, 7};
    int n = sizeof(b)/sizeof(b[0]);

    int ret = intersection(a, b, m, n);

    cout << ret << endl;
}
