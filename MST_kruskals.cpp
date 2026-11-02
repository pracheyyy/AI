
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int findParent(vector<int>& parent, int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void Union(vector<int>& parent, int u, int v)
{
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);

    parent[pu] = pv;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);

    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int cost = 0;
    int count = 0;

    cout << "\nMST edges:\n";

    for(int i = 0; i < E; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(findParent(parent, u) != findParent(parent, v))
        {
            cout << u << " - " << v << " : " << w << endl;

            cost += w;
            count++;

            Union(parent, u, v);

            if(count == V - 1)
                break;
        }
    }

    if(count != V - 1)
    {
        cout << "MST not possible";
    }
    else
    {
        cout << "\nMinimum cost = " << cost;
    }

    return 0;
}
