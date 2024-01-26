// Program to find the shortest distance between two points in a binary grid
#include <iostream>
#include <queue>
using namespace std;

int shortestPath(vector <vector<int> > grid, pair<int, int> source, pair<int, int> dest)
{
    queue<pair <int, pair<int, int> > > q;
    int m = grid.size();
    int n = grid[0].size();
    vector < vector<int> > dist(m, vector<int>(n, 1e9));
    dist[source.first][source.second] = 0;
    q.push(make_pair(0, make_pair(source.first, source.second)));

    int delRow[] = {0, -1, 0, 1};
    int delCol[] = {-1, 0, 1, 0};

    while (q.empty() != true)
    {
        auto it = q.front();
        q.pop();

        int d = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
                && grid[nrow][ncol] == 1 && d + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = d + 1;
                    if (nrow == dest.first && ncol == dest.second)
                    {
                        return d + 1;
                    }
                    q.push(make_pair(d+1, make_pair(nrow, ncol)));
                }
        }
    }
    return -1;
}

int main()
{
    vector <vector<int> > grid;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(1);
    grid.push_back(v1);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(0);
    grid.push_back(v2);

    vector<int> v3;
    v3.push_back(1);
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(1);
    grid.push_back(v3);

    vector<int> v4;
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    grid.push_back(v4);

    pair<int, int> t1;
    t1 = make_pair(1, 1);
    pair<int, int> t2;
    t2 = make_pair(2, 3);

    int ret = shortestPath(grid, t1, t2);

    cout << "Shortest distance between 2 points is "<< ret << endl;
}
