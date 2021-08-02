#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

// #define INT_MAX 2147483647
using namespace std;

/*Using Adjacency List (Not Compelted)*/

// vector<int> dijsktra_algo(vector<vector<int>> edges, int s)
// {
//     vector<int> distance(edges.size(), INT_MAX);
//     vector<bool> visied(edges.size(), false);

//     distance[s] = 0;
//     priority_queue<int, vector<int>, greater<int>> min_heap;
//     min_heap.push(distance[s]);
//     int ele = min_heap.top();

//     auto it=find_if(edges.begin(),edges.end(),[ele](vector<int> v){
//         return v[2]==ele;
//     });

// }

// int main(int argc, char const *argv[])
// {
//     vector<vector<int>> edges = {
//         {1, 2, 24},
//         {1, 4, 20},
//         {3, 1, 3},
//         {4, 3, 12}};

//     return 0;
// }

int min_vertex(vector<int> distance, vector<bool> visited)
{

    int min = INT_MAX, min_index;
    for (int i = 0; i < distance.size(); i++)
    {
        if (!visited[i] && distance[i] <= min)
        {
            min_index = i;
            min = distance[i];
        }
    }
    return min_index;
}

vector<int> dijkstra_algo(vector<vector<int>> graph, int source)
{

    int size = graph.size();
    vector<int> distance(size, INT_MAX);
    vector<bool> visited(size, false);
    distance[source] = 0;
    priority_queue<int, vector<int>, greater<int>> heap;
    heap.push(distance[source]);
    while (!heap.empty())
    {
        // int u = min_vertex(distance, visited);
        int u;
        int uu = heap.top();
        auto it = std::find(distance.begin(), distance.end(), uu);
        if (it != distance.end())
        {
            u = it - distance.begin();
        }
        heap.pop();
        visited[u] = true;
        for (int v = 0; v < graph.size(); v++)
        {
            if (graph[u][v] && !visited[v] && (graph[u][v] + distance[u]) < distance[v])
            {
                distance[v] = graph[u][v] + distance[u];
                heap.push(distance[v]);
            }
        }
    }

    return distance;
}

int main(int argc, char const *argv[])
{
    // vector<vector<int>> graph ={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    // 					{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    // 					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    // 					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    // 					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    // 					{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    // 					{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    // 					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    // 					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    vector<vector<int>> graph = {
        {0, 7, 4, 1},
        {7, 0, 2, 0},
        {4, 2, 0, 1},
        {1, 0, 1, 0}};

    vector<int> distances = dijkstra_algo(graph, 0);

    for (int i = 0; i < distances.size(); i++)
    {
        cout << i << " : " << distances[i] << endl;
    }

    return 0;
}
