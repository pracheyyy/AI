
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    int src;

    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, 1000000);

    dist[src] = 0;

    // Relaxation
    for(int i = 0; i < V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != 1000000 &&
               dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Negative cycle detection
    for(int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != 1000000 &&
           dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle detected";
            return 0;
        }
    }

    cout << "\nShortest distances:\n";

    for(int i = 0; i < V; i++)
    {
        cout << src << " -> " << i << " = ";

        if(dist[i] == 1000000)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}

// Enter number of vertices: 5
// Enter number of edges: 8

// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3

// Enter source vertex: 0