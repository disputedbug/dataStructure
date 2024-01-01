// Program to detect cycle using DFS
#include <iostream>
using namespace std;

bool dfs(int node, int parent, vector<int>adjList[], int vis[])
{
    vis[node] = 1;
    for (auto adjacentNode: adjList[node])
    {
        if(vis[adjacentNode] != 1)
        {
            if (dfs(adjacentNode, node, adjList, vis) == true)
                return true;
        }
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int>adjList[])
{
    int vis[10] = {0};

    for (int i = 1; i < V; i++)
    {
        if (dfs(i, -1, adjList, vis) == true)
            return true;
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
