#include <bits/stdc++.h>
using namespace std;

bool solve(int pos, vector<vector<int>>& graph,
           vector<int>& path, vector<bool>& visited, int n) {

    if (pos == n) {
        // Check if last vertex connects back to start
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < n; v++) {

        if (!visited[v] &&
            graph[path[pos - 1]][v] == 1) {

            path[pos] = v;
            visited[v] = true;

            if (solve(pos + 1, graph, path, visited, n))
                return true;

            visited[v] = false; // backtrack
        }
    }

    return false;
}

bool hamiltonianCycle(vector<vector<int>>& graph) {

    int n = graph.size();

    vector<int> path(n, -1);
    vector<bool> visited(n, false);

    path[0] = 0;          // Start from vertex 0
    visited[0] = true;

    if (!solve(1, graph, path, visited, n))
        return false;

    cout << "Hamiltonian Cycle: ";
    for (int v : path)
        cout << v << " ";

    cout << path[0] << endl; // Complete cycle

    return true;
}

int main() {

    vector<vector<int>> graph = {
        {0,1,1,0,1},
        {1,0,1,1,1},
        {1,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
    };

    if (!hamiltonianCycle(graph))
        cout << "No Hamiltonian Cycle exists\n";

    return 0;
}