
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    int cost[10][10];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> visited(V, 0);

    visited[0] = 1;

    int total = 0;

    cout << "\nMST edges:\n";

    for(int k = 0; k < V - 1; k++)
    {
        int minCost = 9999;
        int u = -1, v = -1;

        for(int i = 0; i < V; i++)
        {
            if(visited[i] == 1)
            {
                for(int j = 0; j < V; j++)
                {
                    if(visited[j] == 0 && cost[i][j] != 0)
                    {
                        if(cost[i][j] < minCost)
                        {
                            minCost = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        if(u == -1)
        {
            cout << "MST not possible";
            return 0;
        }

        cout << u << " - " << v
             << " : " << minCost << endl;

        total += minCost;

        visited[v] = 1;
    }

    cout << "\nMinimum cost = " << total;

    return 0;
}
