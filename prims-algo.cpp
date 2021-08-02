#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INT_MAX 2147483647
using namespace std;

//Using Adjacency list method. Not complete.
// using type = std::pair<int, std::pair<int, int>>;

// struct weighted_edge
// {
//     int weight;
//     int v1, v2;
// };

// bool operator < (weighted_edge a, weighted_edge b)
// {
//     return a.weight < b.weight;
// }
// bool operator > (weighted_edge a, weighted_edge b)
// {
//     return a.weight > b.weight;
// }

// // std::priority_queue<type, std::vector<type>, compare> min_heap;

// int prims_algo(vector<weighted_edge> list, int src_vertex)
// {

//     priority_queue<weighted_edge, vector<weighted_edge>, greater<weighted_edge>> min_heap;

//     //  for (int i = 0; i < list.size(); i++)
//     // {
//     //     min_heap.push(list[i]);
//     // }
//     // while (!min_heap.empty())
//     // {
//     //     weighted_edge p = min_heap.top();
//     //     cout<<p.weight<<endl;
//     //     min_heap.pop();
//     // }

//     vector<int> parents(list.size(), -1);
//     vector<int> weights(list.size(), INT_MAX);
//     vector<bool> visited(list.size(), false);
//     int min_cost = 0;
//     weights[src_vertex] = 0;

//     for (int i = 0; i < list.size(); i++)
//     {
//         min_heap.push(list[i]);
//     }
//     // sort(list.begin(),list.end(),less<weighted_edge>());
//     // for (auto &&val : list)
//     // {
//     //     cout<<val.weight<<endl;
//     // }

//     while (!min_heap.empty())
//     {
//         weighted_edge p = min_heap.top();
//         visited[p.v1] = true;
//         min_heap.pop();

//         for (int v = 0; v < list.size(); v++)
//         {
//             auto it = find_if(list.begin(), list.end(), [visited,&p](weighted_edge e){

//                 return (p.v1=e.v1) && e.weight>=0 && !visited[e.v2];

//             });

//             if (it->weight >= 0 && !visited[it->v2])
//             {
//                 if (weights[it->v2] > it->weight)
//                 {
//                     weights[it->v2] = it->weight;
//                     parents[it->v2] = p.v1;
//                     min_cost += it->weight;
//                 }
//             }
//         }
//     }
//     // for (auto &&weight : weights)
//     // {
//     //     cout<<weight<<endl;
//     // }

//     return min_cost;
// }

// int main(int argc, char const *argv[])
// {
//     // vector<pair<int, pair<int, int>>> list(7, make_pair(-1, make_pair(-1, -1)));
//     // list.push_back(make_pair(2, make_pair(0, 1)));
//     // list.push_back(make_pair(6, make_pair(0, 3)));
//     // list.push_back(make_pair(8, make_pair(3, 1)));
//     // list.push_back(make_pair(9, make_pair(3, 4)));
//     // list.push_back(make_pair(5, make_pair(4, 1)));
//     // list.push_back(make_pair(7, make_pair(4, 2)));
//     // list.push_back(make_pair(3, make_pair(2, 1)));

//     vector<weighted_edge> list{
//         {2, 0, 1},
//         {6, 0, 3},
//         {8, 3, 1},
//         {9, 3, 4},
//         {5, 4, 1},
//         {7, 4, 2},
//         {3, 2, 1}};

//     int min_cost = prims_algo(list, 0);
//     cout << min_cost << endl;
//     return 0;
// }

// Using adjacenecy matrix method.

int min_vertex(const vector<int> &weights, const vector<bool> &visited)
{

    int min = INT_MAX, min_index = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (!visited[i] && weights[i] < min)
        {
            min_index = i;
            min = weights[i];
        }
    }
    return min_index;
}

int prims_algo(vector<vector<int>> list, int s)
{
    int size = list.size();
    vector<int> parents(list.size(), -1);
    vector<int> weights(list.size(), INT_MAX);
    vector<bool> visited(list.size(), false);
    int cost = 0;
    weights[s] = 0;
    int xxx= size-1;
    while (size--)
    {
        int u = min_vertex(weights, visited);
        visited[u] = true;
        for (int v = 0; v < list.size(); v++)
        {
            if (list[u][v] && !visited[v] && list[u][v] < weights[v])
            {
                weights[v] = list[u][v];
                parents[v] = u;
                cost += list[u][v];
            }
        }
    }
    // for (auto child : parents)
    // {
    //     cout<<child<<" ";
    // }
    // cout<<endl;
    
    return cost;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> list = {{0, 2, 0, 6, 0},
                                {2, 0, 3, 8, 5},
                                {0, 3, 0, 0, 7},
                                {6, 8, 0, 0, 9},
                                {0, 5, 7, 9, 0}};

    int cost = prims_algo(list, 0);
    cout << "Min Cost " << cost << endl;

    return 0;
}
