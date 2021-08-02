#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void _dfs_print(vector<vector<int>> node, int current_vertex, vector<bool> &visited)
{

    cout << current_vertex << endl;
    visited[current_vertex] = true;
    for (int i = 0; i < node.size(); i++)
    {
        if (node[current_vertex][i] && !visited[i])
        {
            _dfs_print(node, i, visited);
        }
    }
}

void _bfs_print(vector<vector<int>> node, int current_vertex, vector<bool> &visited)
{

    queue<int> q;
    q.push(current_vertex);
        visited[current_vertex] = true;

    while (!q.empty())
    {
        int ele = q.front();
        cout << ele << endl;
        q.pop();

        for (int i = 0; i < node.size(); i++)
        {
            if (node[ele][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int dfs_print(vector<vector<int>> node){

    int count =0;
    vector<bool> visited(node.size());
    for (int i = 0; i < node.size(); i++)
    {
        if(!visited[i]){
            _dfs_print(node,i,visited);
            count++;
        }
    }
        return count;
    

}
int bfs_print(vector<vector<int>> node){

    int count=0;
    vector<bool> visited(node.size());
    for (int i = 0; i < node.size(); i++)
    {
        if(!visited[i]){
            _bfs_print(node,i,visited);
            count++;
        }
    }
    return count;
    

}

int main()
{

    int v, e, starting_vertex;
    cout<<"Enter no of vertices and edges "<<endl;
    cin >> v >> e;

    vector<vector<int>> adj_matrix(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++)
    {
        int first_vertex, second_vertex;
        cin >> first_vertex >> second_vertex;
        if (i == 0)
            starting_vertex = first_vertex;

        adj_matrix[first_vertex][second_vertex] = 1;
        adj_matrix[second_vertex][first_vertex] = 1;
    }
    vector<bool> visited(v, false);
    // dfs_print(adj_matrix, starting_vertex, visited);
    // cout<<endl<<dfs_print(adj_matrix);
    // bfs_print(adj_matrix, starting_vertex, visited);
    cout<<endl<<bfs_print(adj_matrix);

    return 0;
}
