// Program for a DFS of a graph given its adjacency list
#include <iostream>
#include <queue>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector <int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);

    // traverse all the neighbours and call dfs on them
    for (auto item: adj[node])
    {
        if (vis[item] != 1)
        {
            dfs(item, adj, vis, ls);
        }
    }
}

vector <int> dfsGraph(int V, vector <int>adj[])
{
    // visited array
    int vis[10] = {0};
    // result vector with DFS traversal
    vector <int> ls;

    int start = 1;
    dfs(start, adj, vis, ls);

    return ls;
}

int main()
{
    vector <int> adj[10];

    adj[1].push_back(2);
    adj[1].push_back(6);

    adj[2].push_back(3);
    adj[2].push_back(4);

    adj[3].push_back(2);

    adj[4].push_back(5);

    adj[5].push_back(4);
    adj[5].push_back(7);

    adj[6].push_back(7);
    adj[6].push_back(8);

    adj[7].push_back(5);
    adj[7].push_back(6);

    adj[8].push_back(6);

    int V = 9;

    vector <int> ret;
    ret = dfsGraph(V, adj);

    for (auto item: ret)
    {
        cout << item << " ";
    }

    cout << endl;
}
