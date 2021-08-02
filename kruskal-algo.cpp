
/*
    Using Adjacency matrix method
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_parent(int vertex, int *parent_arr)
{
    while (parent_arr[vertex] != vertex) //vertex = 6 ,parent_arr[vertex] =7
    {
        vertex = parent_arr[vertex];
    }

    // return parent_arr[vertex];
    return vertex;
}

void union_ele(int vertex1, int vertex2, int *parent_arr)
{

    int i = find_parent(vertex1, parent_arr);
    int j = find_parent(vertex2, parent_arr);
    parent_arr[j] = i;
}

int kruskal(vector<vector<int>> graph, int *parent_arr, int v)
{

    int total_min_weight = 0;
    int edge_count = 0;
    for (int i = 0; i < v; i++)
    {
        parent_arr[i] = i;
    }

    while (edge_count < v - 1)
    {

        int min_cost = INT_MAX, vertex1 = -1, vertex2 = -1;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (find_parent(i, parent_arr) != find_parent(j, parent_arr) && graph[i][j] < min_cost)
                {
                    min_cost = graph[i][j];
                    vertex1 = i;
                    vertex2 = j;
                }
            }
        }

        union_ele(vertex1, vertex2, parent_arr);
        total_min_weight += min_cost;

        cout << "Edge " << edge_count++ << " : " << vertex1 << " " << vertex2 << " Cost: " << min_cost << endl;
    }

    return total_min_weight;
}

int main()
{

    int v, e, starting_vertex;
    cout << "Enter no of vertices and edges " << endl;
    cin >> v >> e;

    vector<vector<int>> adj_matrix(v, vector<int>(v, INT_MAX));

    for (int i = 0; i < e; i++)
    {
        int first_vertex, second_vertex, weight;
        cin >> first_vertex >> second_vertex >> weight;
        if (i == 0)
            starting_vertex = first_vertex;

        adj_matrix[first_vertex][second_vertex] = weight;
        adj_matrix[second_vertex][first_vertex] = weight;
    }
    int parent_arr[v];

    int min_cost = kruskal(adj_matrix, parent_arr, v);
    cout << "Min cost :" << min_cost << endl;

    return 0;
}

/*
    Using Adjacency list method using pairs .  
*/

// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;
// const int MAX = 1e6 - 1;
// int root[MAX];
// const int nodes = 4, edges = 5;
// pair<long long, pair<int, int>> p[MAX];

// int parent(int a) //find the parent of the given node
// {
//     while (root[a] != a)
//     {
//         root[a] = root[root[a]];
//         a = root[a];
//     }
//     return a;
// }

// void union_find(int a, int b) //check if the given two vertices are in the same “union” or not
// {
//     int d = parent(a);
//     int e = parent(b);
//     root[d] = root[e];
// }

// long long kruskal()
// {
//     int a, b;
//     long long cost, minCost = 0;
//     for (int i = 0; i < edges; ++i)
//     {
//         a = p[i].second.first;
//         b = p[i].second.second;
//         cost = p[i].first;
//         if (parent(a) != parent(b)) //only select edge if it does not create a cycle (ie the two nodes forming it have different root nodes)
//         {
//             minCost += cost;
//             union_find(a, b);
//         }
//     }
//     return minCost;
// }

// int main()
// {
//     int x, y;
//     long long weight, cost, minCost;
//     for (int i = 0; i < MAX; ++i) //initialize the array groups
//     {
//         root[i] = i;
//     }
//     p[0] = make_pair(10, make_pair(0, 1));
//     p[1] = make_pair(18, make_pair(1, 2));
//     p[2] = make_pair(13, make_pair(2, 3));
//     p[3] = make_pair(21, make_pair(0, 2));
//     p[4] = make_pair(22, make_pair(1, 3));
//     sort(p, p + edges); //sort the array of edges
//     minCost = kruskal();
//     cout << "Minimum cost is: " << minCost << endl;
//     return 0;
// }