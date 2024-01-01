// Program to detect cycle using BFS
#include <iostream>
#include <queue>
using namespace std;

bool bfs(int src, vector<int>adjList[], int vis[])
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (q.empty() != true)
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adjList[node])
        {
            if (vis[adjacentNode] != 1)
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int>adjList[])
{
    int vis[10] = {0};

    for (int i = 1; i <= V; i++)
    {
        if (vis[i] != 1)
        {
            if (bfs(i, adjList, vis) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    vector <int> adj[10];

    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {1, 4, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};

    int numNodes = 7;

    bool ret = isCycle(numNodes, adj);

    cout << boolalpha << "Is there a cycle: " << ret << endl;
}
