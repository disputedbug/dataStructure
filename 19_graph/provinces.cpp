// Program to count the number of provinces using DFS/BFS given the adjacency matrix
#include <iostream>
#include <queue>
using namespace std;

void dfs(int node, vector<int> adjList[], int vis[])
{
    vis[node] = 1;
    for (auto item: adjList[node])
    {
        if (vis[item] != 1)
        {
            dfs(item, adjList, vis);
        }
    }
}

void bfs(int node, vector <int> adjList[], int vis[])
{
    queue<int> q;
    vis[node] = 1;
    q.push(node);

    while(q.empty() != true)
    {
        int node = q.front();
        q.pop();

        for (auto item: adjList[node])
        {
            if (vis[item] != 1)
            {
                vis[item] = 1;
                q.push(item);
            }
        }
    }
}

int provinces(vector <string> adj)
{
    int n = adj.size();
    vector<int> adjList[n];

    // change adjacency matrix to adjacency list
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == '1' && i != j)
            {
                adjList[i].push_back(j);
                //adjList[j].push_back(i);
            }
        }
    }

    // Now call DFS to count the provinces
    int vis[10] = {0};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            count++;
            dfs(i, adjList, vis);
        }
    }
    return count;
}

int main()
{
    vector <string> grid;

    grid.push_back("01000000");
    grid.push_back("10100000");
    grid.push_back("01000000");
    grid.push_back("00001000");
    grid.push_back("00100100");
    grid.push_back("00001000");
    grid.push_back("00000001");
    grid.push_back("00000010");

    int ret = provinces(grid);

    cout << "Number of provinces is: " << ret << endl;
}
