
#include <iostream>
using namespace std;

int main()
{
    int V = 5;

    int graph[5][5] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[5];
    int parent[5];
    bool mstSet[5];

    for(int i = 0; i < V; i++)
    {
        key[i] = 9999;
        parent[i] = -1;
        mstSet[i] = false;
    }

    key[0] = 0;

    for(int count = 0; count < V; count++)
    {
        int min = 9999;
        int u = -1;

        for(int i = 0; i < V; i++)
        {
            if(mstSet[i] == false && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        if(u == -1)
        {
            cout << "MST not possible";
            return 0;
        }

        mstSet[u] = true;

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 &&
               mstSet[v] == false &&
               graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;

    cout << "Minimum Spanning Tree:\n";

    for(int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "\nMinimum Road Length = " << total;

    return 0;
}
