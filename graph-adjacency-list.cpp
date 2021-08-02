#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // unordered_map<int, unordered_set<int>> adj_list = {

    //     {0, {1, 2}},
    //     {1, {0, 2, 3, 4}},
    //     {2, {0, 1, 3}},
    //     {3, {1, 2, 4}}

    // };


    unordered_map<int, unordered_set<int>> adj_list;

    int no_vertex, no_adj_vertex, vertex, adj_vertex;
    unordered_set<int> adj_vertices;
    cin >> no_vertex;
    for (int i = 0; i < no_vertex; i++)
    {
        cin >> vertex >> no_adj_vertex;
        for (int j = 0; j < no_adj_vertex; j++)
        {
            cin >> adj_vertex;
            adj_vertices.insert(adj_vertex);
        }

        adj_list.insert(make_pair(vertex, adj_vertices));
    }

    return 0;
}
