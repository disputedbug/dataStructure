// Find union of two arrays
// Use g++ -std=c++17 -g union.cpp -o union to compile
#include <iostream>
#include <unordered_set>
using namespace std;

int findUnion(int a[], int b[], int m, int n)
{
    unordered_set <int> hash(a, a+m);
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        hash.insert(b[i]);
    }

    for (auto key: hash)
        cout << key  << " ";

    cout << endl;
    return hash.size();
}

int main()
{
    int a[] = {1, 2, 3, 4, 6, 7, 8, 10};
    int m = sizeof(a)/sizeof(a[0]);
    int b[] = {2, 3, 7, 12, 15};
    int n = sizeof(b)/sizeof(b[0]);

    int ret = findUnion(a, b, m, n);

    cout << ret << endl;
}
