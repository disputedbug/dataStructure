// Program to count the number of islands using BFS
#include <iostream>
#include <queue>
using namespace std;

//void bfs(int row, int col, vector <vector<int>> &vis, vector<vector<char>> &grid)
void bfs(int row, int col, vector <vector<int>> &vis, vector<string> &grid)
{
    queue<pair<int, int>> q;
    vis[row][col] = 1;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while (q.empty() != true)
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delCol = -1; delCol <= 1; delCol++)
            {
                int newRow = row+delRow;
                int newCol = col+delCol;
                // check validity of the new row and col
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                    && vis[newRow][newCol] != 1 && grid[newRow][newCol] == '1')
                    {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
            }
        }
    }
}

//int numIslands(vector <vector<char>>&grid)
int numIslands(vector <string>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (vis[row][col] != 1 && grid[row][col] == '1')
            {
                count++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return count;
}

int main()
{
    //vector <vector<char>> grid;
    vector <string> grid;
    /*vector<char> temp1;
    temp1.push_back('0');
    temp1.push_back('1');
    temp1.push_back('1');
    temp1.push_back('0');
    grid.push_back(temp1);

    vector<char> temp2;
    temp2.push_back('0');
    temp2.push_back('1');
    temp2.push_back('1');
    temp2.push_back('0');
    grid.push_back(temp2);

    vector<char> temp3;
    temp3.push_back('0');
    temp3.push_back('0');
    temp3.push_back('1');
    temp3.push_back('0');
    grid.push_back(temp3);

    vector<char> temp4;
    temp4.push_back('0');
    temp4.push_back('0');
    temp4.push_back('0');
    temp4.push_back('0');
    grid.push_back(temp4);

    vector<char> temp5;
    temp5.push_back('1');
    temp5.push_back('1');
    temp5.push_back('0');
    temp5.push_back('1');
    grid.push_back(temp5);*/



    grid.push_back("0110");
    grid.push_back("0110");
    grid.push_back("0010");
    grid.push_back("0000");
    grid.push_back("1101");

    int ret = numIslands(grid);

    cout << "Number of islands is: " << ret << endl;
}
