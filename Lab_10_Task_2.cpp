#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) 
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfs(graph, visited, neighbor);
        }
    }
}

void findConnectedComponents(vector<vector<int>>& graph) 
{
    int n = graph.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) 
    {
        if (!visited[i]) 
        {
            cout << "Connected Component: ";
            dfs(graph, visited, i);
            cout << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph = 
    {
        {1, 2},
        {0},
        {0},
        {4, 5},
        {3},
        {3}
    };

    findConnectedComponents(graph);

    return 0;
}