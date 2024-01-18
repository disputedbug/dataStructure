// Program for a BFS of a graph
#include <iostream>
#include <queue>
using namespace std;

// This function will find all the possible location of the water-tower for a given town
vector <vector<int> > findPossibleLocations(vector <vector<int> > grid, pair<int, int> t1)
{
    int m = grid.size();
    int n = grid[0].size();
    int r = t1.first;
    int c = t1.second;

    vector <vector<int> > pos(m, vector<int>(n, 0));

    pair <int, int> parent = t1;
    queue <pair<pair <int, int>, pair <int, int> > > q;

    // Push the town (r, c) in Queue and mark it as visited
    q.push(make_pair(t1, make_pair(-1, -1)));
    pos[r][c] = grid[r][c];

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (q.empty() != true)
    {
        pair <int, int> curr = q.front().first;
        pair <int, int> par = q.front().second;

        int rcurr = curr.first;
        int ccurr = curr.second;

        int rpar = par.first;
        int cpar = par.second;

        q.pop();

        // Find all the immediate neighbours of the town with greater height
        for (int i = 0; i < 4; i++)
        {
            int nrow = rcurr + delRow[i];
            int ncol = ccurr + delCol[i];

            if (nrow >= 0 && nrow < m
                && ncol >= 0 && ncol < n
                && !(nrow == rpar && ncol == cpar)
                && pos[nrow][ncol] == 0
                && grid[nrow][ncol] >= grid[rcurr][ccurr])
            {
                q.push(make_pair(make_pair(nrow, ncol),
                        make_pair(rcurr, ccurr)));
                pos[nrow][ncol] = grid[nrow][ncol];
            }
        }
    }
    return pos;
}

// find the possible locations of the watertowers for both the town
// and find the intersection of both and find max among the intersection
int findBestLoc(vector <vector<int> > grid, pair<int, int> t1, pair<int, int> t2)
{
    int m = grid.size();
    int n = grid[0].size();
    vector <vector<int> > pos1;
    vector <vector<int> > pos2;

    pos1 = findPossibleLocations(grid, t1);
    pos2 = findPossibleLocations(grid, t2);

    // For debug: start
    cout << "The given grid is:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Possible locations of water-tower for Town-1(" << t1.first << "," << t1.second << ")" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cout << pos1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Possible locations of water-tower for Town-2(" << t2.first << "," << t2.second << ")" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cout << pos2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int maxHeight = 0;
    // find the intersection of the possible location for both the towns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (pos1[i][j] != 0 && pos2[i][j] != 0)
            {
                cout << "A possible solution (" << i << "," << j << ")" << " height: " << pos1[i][j] << endl;
                maxHeight = max(maxHeight, pos1[i][j]);
            }
        }
    }

    cout << "Maximum height is " << maxHeight << endl;
    // For debug: end

    return maxHeight;
}

int main()
{
    vector <vector<int> > grid;

    vector<int> v1;
    v1.push_back(5);
    v1.push_back(9);
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(2);
    grid.push_back(v1);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(7);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(1);
    grid.push_back(v2);

    vector<int> v3;
    v3.push_back(7);
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(5);
    v3.push_back(3);
    grid.push_back(v3);

    vector<int> v4;
    v4.push_back(8);
    v4.push_back(2);
    v4.push_back(1);
    v4.push_back(6);
    v4.push_back(7);
    grid.push_back(v4);

    pair<int, int> t1;
    t1 = make_pair(1, 4);
    pair<int, int> t2;
    t2 = make_pair(3, 1);

    int ret = findBestLoc(grid, t1, t2);

    cout << "Height of water tower should be "<< ret << endl;
}
