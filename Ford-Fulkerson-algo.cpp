#include <iostream>
#include <climits>
#include <queue>
#define size 6
using namespace std;

bool bfs_algo(int residual_graph[][size], int s, int t, int parent[])
{
    bool visited[size]{};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < size; v++)
        {
            if (visited[v] == false && residual_graph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int ford_fulkerson_algo(vector<vector<int>> graph, int s, int t)
{
    int u, v;
    int residual_graph[size][size];
    for (u = 0; u < size; u++)
    {
        for (v = 0; v < size; v++)
        {
            residual_graph[u][v] = graph[u][v];
        }
    }
    int parent[size];
    int max_flow = 0;
    while (bfs_algo(residual_graph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main(int argc, char const *argv[])
{
    // vector<vector<int>> adj_matrix = {{0, 16, 13, 0, 0, 0},
    //                                   {0, 0, 10, 12, 0, 0},
    //                                   {0, 4, 0, 0, 14, 0},
    //                                   {0, 0, 9, 0, 0, 20},
    //                                   {0, 0, 0, 7, 0, 4},
    //                                   {0, 0, 0, 0, 0, 0}};

    // vector<vector<int>> adj_matrix = {{0, 10, 15, 0, 5, 0, 0, 0},
    //                                   {0, 0, 0, 9, 4, 15, 0, 0},
    //                                   {0, 0, 0, 0, 0, 0, 0, 16},
    //                                   {0, 0, 0, 0, 0, 15, 10, 0},
    //                                   {0, 0, 0, 0, 0, 8, 0, 0},
    //                                   {0, 0, 0, 0, 0, 0, 10, 15},
    //                                   {0, 0, 0, 0, 0, 0, 0, 0},
    //                                   {0, 0, 0, 0, 4, 0, 0, 10}};
    vector<vector<int>> adj_matrix = {{0, 10, 0, 10, 0, 0},
                                      {0, 0, 4, 2, 8, 0},
                                      {0, 0, 0, 0, 0, 10},
                                      {0, 0, 0, 0, 9, 0},
                                      {0, 0, 6, 0, 0, 10},
                                      {0, 0, 0, 0, 0, 0}};
    int source = 0, sink = 5;
    cout << "The maximum possible flow through this network is " << ford_fulkerson_algo(adj_matrix, source, sink);
    return 0;
}
