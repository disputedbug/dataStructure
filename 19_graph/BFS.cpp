// Program for a BFS of a graph
#include <iostream>
#include <queue>
using namespace std;

vector <int> bfsGraph(int V, vector <int>adj[])
{
    vector <int> bfs;
    queue <int> q;
    int vis[10] = {0};
    q.push(1);   // First node goes in the queue.. 1 based
    vis[1] = 1;

    while (q.empty() != true)
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        cout << node << " ";

        for (auto item: adj[node])
        {
            if (vis[item] != 1)
            {
                vis[item] = 1;
                q.push(item);
            }
        }
    }
    return bfs;
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

    bfsGraph(V, adj);

    cout << endl;
}
